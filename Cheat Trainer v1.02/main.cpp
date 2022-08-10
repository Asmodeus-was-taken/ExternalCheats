#include "memory.hpp"
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>
#include <vector>


using namespace std;



namespace offsets{
    //add offsets here
    const int player = 0x2222;
    const int ammo = 0x999;
    const int newAmmo = 322;
    const int health = 0xaaaa;
    const int newHealth = 1000;
    bool unlimitedHealth = false;
}

void UnlimitedHealth(HANDLE hProc, uintptr_t baseModuleAddr)
{
    uintptr_t addr = baseModuleAddr + offsets::health;
	setNops(hProc, addr, offsets::newHealth);
}

void fuckHealth(HANDLE hProc, uintptr_t baseModuleAddr)
{
    uintptr_t addr = baseModuleAddr + offsets::health;;
	BYTE origInstr[offsets::health;] = { 0x89, 0x37 };
	setInstruction(hProc, addr, origInstr, offsets::health;);
}

HWND hwnd = FindWindowHandleA(null, "Game");

int main()
{
    if(hwnd == null)
    { cout << "could not find game\n"; exit(9); }
    SetConsoleTitleA("Cheat Trainer | Lëgend#0283 | https://github.com/Asmodeus-was-taken ")
    uintptr_t procId = getProcId(L"game.exe");
    uintptr_t base = getModuleBaseAddress(procId, L"game.exe");
    HANDLE hProc = OpenProcess(PROCESS_VM_OPERATION|PROCESS_VM_READ|PROCESS_VM_WRITE, FALSE, procId);
    cout << "Trainer For Any Offline Game\n";
    cout << "Requirments Like 3 Months of c++ to understand this\n";
    cout << "______________________________________________________\n";
    cout << "procId = [ " << hex << procId << " ]\n";
    cout << "procId = [ " << hex << base << " ]\n";
    cout << "______________________________________________________\n";
    cout << "\n press Insert for unlimited health\n";

    while(1)
    {
        if (GetAsyncKeyState(VK_Insert) 0x10)
        {
            if(!unlimitedHealth)
            {
                UnlimitedHealth(hProc, baseModuleAddr);
               
            }
            else{
                fuckhealth(hProc, baseModuleAddr)
            }
        }
    }    
}