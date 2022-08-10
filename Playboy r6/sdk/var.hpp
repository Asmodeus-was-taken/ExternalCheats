#pragma once
#include <cstdint>

#include <iostream>
#include <vector>

typedef struct _entity_t
{
	std::uint64_t controller;
	std::uintptr_t pawn;
} entity_t, * p_entity_t;


struct _var{
    //for offsets & fets
    uint64_t pID;
    uint64_t moduleBase;
    uint64_t gameManager;
    uintptr_t CurrentWeapon;
    uint64_t gameProfile;
    uint64_t entityList;
    uint64_t replicationinfo;
    uint64_t TeamID;
    uint64_t roundManager;
    uint32_t gamestate;
    uintptr_t Name;
    uint32_t entityCount;
    uintptr_t cam;
    uint64_t localPlayer;
    uint64_t localPawn;
    int width = 1920;
    int height = 1080;
    bool team;
    float recoilAmount = 100.f;
    bool recoil;
    bool sway;
    float swayAmount = 100.f;
    bool Aimbot;
    bool boxtype;


    //mainmenu 
    bool show = false;
    bool enableEsp = true;
    bool TwoBox = false;
    bool fillBox = false;
    bool CornorBox = false;
    bool PlayboyBox = true;
    bool healthBar = false;
    bool NameBar = false;
    bool distance = false;
    bool snapline = false;
    bool aimbot = false;
    float aimbotFov = 90.f;
    bool Fov = false;
    bool playboyfov = false;
    bool fillFov = false;
    bool Smoothing = false;
    int amountofsmoothing = 10;
    bool normalcrosshair = false;
    bool gaycrosshair = false;
    bool nicenight;


};
//bones for aimbot to lock onto
enum bones{
    head, 
    neck,
    chest,
    legs
    
};

//type of box we r doing 
enum box{

    2Dbox,
    cornorbox,
    playboybox
};



extern _var Var