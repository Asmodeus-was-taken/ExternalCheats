#include <iostream>
#include <windows.h>
#include <vector>
#include "driver.hpp"
#include "encryption.hpp"
#include "var.hpp"
#include "offset.hpp"
#include "driver.hpp"

HWND hwnd == FindWindowA(Null, "Rainbow6");

    auto UpdateEnts()
    {
	    while (true)
	    {
	    	std::vector<entity_t> tmp = { {} };

	    	for (int i = 0; i < _var::entityCount; i++)
	    	{
		    	uint64_t player = driver_t::Read<uint64_t>(_var::entityCount + (i * sizeof(uint64_t)));

	    		if (!player) continue;
		    	uint64_t pawn = offset::GetPawn (player);

		    	if (!pawn) continue;
		    	if (Var.teamcheck)
		    	{
		    		Var.TeamID = offset::get_team_id(Var.replicationinfo);
		    		uint64_t replicationInfo = offset::ReplicationInfo(player);
		    		if (offset::get_team_id(replicationInfo) == Var.TeamID) continue;
		    	}

		    	entity_t entity{ {} };
		    	entity.controller = player;
		    	entity.pawn = pawn;
		    	tmp.push_back(entity);
		    }

		    Visuals::entities = tmp;
		    sleep(250);
	    }
    }


void driverm()
{
	uintptr_t driver_t::get_module_base = ("Rainbowsix.exe");
	DWORD driver_t::get_pid = ("RainbowSix.exe");
	
}


	

void check() // checks driver load, pid, game found, ect 
{
    if(hwnd == null)
    { cout << "could not find game\n"; exit(9); }

	if(!driver_t::is_mapped)
	{ return cout << "Driver Not Mapped\n"; }

    if(!driver_t::get_pid)
    { cout << "could Not Find Games pId\n\n"; }

   
    if(!driver_t::get_module_base)
    { cout << "Could Not Find Game Base\n\n"; }

    sleep(100);
    
}

int main()
{
	SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 500, 500, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW); 

	driverm();
    check();

    _var::gameManager = offset::GameManager();
   _var::gameProfile = offset::GamerProfile();
	_var::cam = offset::GetCamera();
	_var::entityList = offset::EntityManager(_vargameManager).first;
	_var::entityCount = offset::EntityManager(_vargameManager).second;
	_var::replicationinfo = offset::ReplicationInfo(_varlocalPlayer);
	_var::localPawn = offset::Pawn(_varlocalPlayer);
    _var::localPlayer = driver::Read<uint64_t>(_varentityList);
    sleep(1);

    

	system("start https://discord.gg/KmWxn3Ww3E");
	cout << "Welcome To a Legit R6 Cheat!\n";
	cout << "________________________________\n";
	cout << "Menu Key is [Insert] Pls Do not close this exe!\n";
	cout << "ModuleBase [ " << hex << driver_t::get_module_base << " ] \n";
	cout << "ModuleBase [ " << hex << driver_t::get_pid  << " ] \n";
    cout << "\n\n\n\n\n\n Devloped by Lëgend#0283\n";
}