#include <windows.h>
#include <iostream>
#include <encryption.hpp>
    uint64_t view_data_decryption_xor_value;
    uint64_t view_data_decryption_add_value;

namespace offset
{
        uintptr_t GetActor(uintptr_t Pawn)
    {
    	return __ROL8__(RPM<uintptr_t>
    		(Pawn + 0x18) - 101i64, 56) - 0x1C5DD825B2498B00i64;
    }
     
    uintptr_t GetPawn(uintptr_t Player)
    {
    	return (__ROL8__(RPM<uintptr_t>
    		(Player + 56), 47) + 0x2E32184E980B94E8i64) ^ 0x72C27753E8FBCA83i64;
    }
     
    static void init_view_data_decryption(void)
    {
    	view_data_decryption_xor_value = 0x2C4271B184C37EFD;
    	view_data_decryption_add_value = 0xEFB8CBEAB4138A79;
    }
        uintptr_t GetGameManager()
    {
    	return __ROL8__((RPM<uintptr_t>
    	(BaseAddress + 0x7A4BE60) - 0x2DFBC9ECA85C0230) ^ 0x8776BB84854170C4, 0x37);
    }
     
    static uint64_t decrypt_view_data(const uint64_t x)
    {
    	const auto temp = (x + view_data_decryption_add_value) ^ view_data_decryption_xor_value;
     
    	view_data_decryption_xor_value -= 0x633FE7A7F870CD7F;
    	view_data_decryption_add_value += 0xFC232120A243611;
     
    	return temp << 0x27 | temp >> 0x19;
    }
     
    bool WorldToScreen(Vector3 world, Vector3& screen)
    {
    	auto camera_manager = offsets::CameraManager();
     
    	uint64_t fovX_offset = 0x2FC;
    	uint64_t fovY_offset = 0x300;
     
    	init_view_data_decryption();
     
    	__m128i pRight = memory::Read<__m128i>(camera_manager + 0x1D0, global::global.pid);
    	pRight.m128i_i64[0] = decrypt_view_data(pRight.m128i_i64[0]);
    	pRight.m128i_i64[1] = decrypt_view_data(pRight.m128i_i64[1]);
    	Vector3 vecRight = *(Vector3*)&(pRight);
     
    	__m128i pUp = memory::Read<__m128i>(camera_manager + 0x1D0 + 0x10, global::global.pid);
    	pUp.m128i_i64[0] = decrypt_view_data(pUp.m128i_i64[0]);
    	pUp.m128i_i64[1] = decrypt_view_data(pUp.m128i_i64[1]);
    	Vector3 vecUp = *(Vector3*)&(pUp);
     
    	__m128i pForward = memory::Read<__m128i>(camera_manager + 0x1D0 + 0x10 + 0x10, global::global.pid);
    	pForward.m128i_i64[0] = decrypt_view_data(pForward.m128i_i64[0]);
    	pForward.m128i_i64[1] = decrypt_view_data(pForward.m128i_i64[1]);
    	Vector3 vecForward = *(Vector3*)&(pForward);
     
    	__m128i pTranslation = memory::Read<__m128i>(camera_manager + 0x1D0 + 0x10 + 0x10 + 0x10, global::global.pid);
    	pTranslation.m128i_i64[0] = decrypt_view_data(pTranslation.m128i_i64[0]);
    	pTranslation.m128i_i64[1] = decrypt_view_data(pTranslation.m128i_i64[1]);
    	Vector3 vecTranslation = *(Vector3*)&(pTranslation);
     
    	Vector3 temp = world - vecTranslation;
    	float x = temp.Dot(vecRight);
    	float y = temp.Dot(vecUp);
    	float z = temp.Dot(vecForward * -1.f);
     
    	uint32_t fovX_ = (memory::Read<uint32_t>(camera_manager + fovX_offset, global::global.pid) + 0x5A90F23D) ^ 0x18;
    	uint32_t fovY_ = _rotr(memory::Read<uint32_t>(camera_manager + fovY_offset, global::global.pid) - 0x6A, 1) - 0x0E6DA57D2;
    	float fovX = *(float*)&fovX_;
    	float fovY = *(float*)&fovY_;
     
    	int width = 1920;
    	int height = 1080;
     
    	screen.x = (width / 2.f) * (1.f + x / -fovX / z); // fovx
    	screen.y = (height / 2.f) * (1.f - y / -fovY / z); // fovy
    	if (screen.x < 0.0f || screen.x > width)
    	return false;
    	return z >= 1.0f;
    }

} offset;
    