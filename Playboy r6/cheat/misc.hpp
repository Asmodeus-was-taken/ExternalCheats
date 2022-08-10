#include <windows.h>
#include "encryption.hpp"
#include "vector.hpp"
#include "offset.hpp"
#include "driver.hpp"
#include "var.hpp"


void norecoil()
{
    if( _var::recoil)
    {
        originalrecoil = driver_t::read<uint32_t>(_var::CurrentWeapon + 0x1A8)

        _var::CurrentWeapon->recoil(0.0f);
    }
}
