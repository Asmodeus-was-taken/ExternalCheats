#pragma once

#include "../../string/xor.hpp"
#include "../../includes.hpp"

#include "../func/function.hpp"

#define secret_t 166

std::wstring str_to_wstr (const std::string& str)
{
    std::wostringstream wstm;
    const std::ctype<wchar_t>& ctfacet = std::use_facet<std::ctype<wchar_t>> (wstm.getloc ());
    for (size_t i = 0; i < str.size (); ++i)
        wstm << ctfacet.widen (str[i]);
    return wstm.str ();
}

class driver_t
{
private:
    DWORD process_id = NULL;
    const char* window_class_name = "";
    const char* window_name = "";

    bool is_process_valid ()
    {
        if (!process_id) return false;

        return true;
    }

public:

    void set_pid (const char* class_name, const char* _window_name)
    {
        GetWindowThreadProcessId (FindWindowA (class_name, _window_name), &process_id);

        window_class_name = class_name;
        window_name = _window_name;
    }

    DWORD get_pid ()
    {
        return process_id;
    }

    bool is_mapped ()
    {

        cmd_t cmd{};
        cmd.key = secret_t;
        cmd.code = control::base;
        cmd.process_id = GetCurrentProcessId ();

        cmd.module_name = const_cast< wchar_t* >( L"win32u.dll" );

        function.call (&cmd);

        return cmd.outbase;
    }

    uintptr_t get_module_base (const char* module_name)
    {
        std::wstring wide_module_name = str_to_wstr (module_name);
        wchar_t* final_module_name = const_cast< wchar_t* >( wide_module_name.c_str () );

        if (!is_process_valid ()) return 0;

        cmd_t cmd{};
        cmd.key = secret_t;
        cmd.code = control::base;
        cmd.process_id = process_id;
        cmd.module_name = final_module_name;
        function.call (&cmd);
        return reinterpret_cast< uintptr_t >( cmd.outbase );
    }

    template<typename T>
    T read (uintptr_t address)
    {
        T buffer{};

        if (!is_process_valid ()) return buffer;

        cmd_t cmd{};

        cmd.key = secret_t;
        cmd.process_id = process_id;
        cmd.code = control::read;

        cmd.address = reinterpret_cast< PVOID >( address );
        cmd.size = sizeof (T);
        cmd.value = &buffer;
        function.call (&cmd);

        return buffer;
    }

    void read (uintptr_t read_address, void* buffer, size_t size)
    {
        if (!is_process_valid ()) return;

        cmd_t cmd{};

        cmd.key = secret_t;
        cmd.process_id = process_id;
        cmd.code = control::read;

        cmd.address = reinterpret_cast< PVOID >( read_address );
        cmd.size = size;
        cmd.value = buffer;

        function.call (&cmd);
    }

    template <typename T>
    T read_chain (std::uint64_t address, std::vector<std::uint64_t> chain)
    {
        uint64_t cur_read = address;

        for (size_t r = 0; r < chain.size () - 1; ++r)
            cur_read = read<std::uint64_t> (cur_read + chain[r]);

        return read<T> (cur_read + chain[chain.size () - 1]);
    }

    std::string read_wstr (uintptr_t address)
    {
        wchar_t buffer[1024 * sizeof (wchar_t)];
        read (address, &buffer, 1024 * sizeof (wchar_t));

        std::wstring new_buffer = std::wstring (buffer);

        return std::string (new_buffer.begin (), new_buffer.end ());
    }

    const char* read_str (uintptr_t address, int size = 64)
    {
        std::unique_ptr<char[]> buffer (new char[size]);
        read (address, buffer.get (), size);
        return buffer.get ();
    }

    template<typename T>
    bool write (uintptr_t address, T value)
    {
        if (!is_process_valid ()) return false;

        cmd_t cmd{};
        cmd.key = secret_t;
        cmd.process_id = process_id;
        cmd.code = control::write;
        cmd.address = reinterpret_cast< PVOID >( address );
        cmd.value = &value;
        cmd.size = sizeof (T);

        function.call (&cmd);

        return true;
    }

}driver;

