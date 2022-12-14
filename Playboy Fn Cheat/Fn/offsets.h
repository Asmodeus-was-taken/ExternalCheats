#pragma once
#include <basetsd.h>
#include <stdint.h>



typedef struct _actors
{
	uint64_t ACTOR;
	int ID;
	uint64_t MESH;
	std::string name;
}actors;

namespace offname
{
	DWORD_PTR uworld;
	DWORD_PTR gameinst;
	DWORD_PTR localactors;
	DWORD_PTR localactor;
	DWORD_PTR controlactor;
	DWORD_PTR localactorpawn;
	DWORD_PTR actorstate;
	DWORD_PTR rootcomp;
	DWORD_PTR perslvl;
	DWORD_PTR levels;
	DWORD_PTR localactorpos;
	DWORD_PTR actorcount;
	DWORD_PTR aactors;
	DWORD_PTR relativeloc;
	DWORD_PTR vischeck;
	DWORD_PTR imposible;
	int localactorid;
}


namespace Offsets
{
	enum External : uint64_t
	{
		UWORLD = 0xcbf3538,
		GAMEINST = 0x1A8,
		LOCALACTOR = 0x38,
		LEVEL = 0x160,
		ACTORPAWN = 0x310,
		ACTORSTATE = 0x290,
		ROOTCOMPONENT = 0x188,
		ITEMDEF = 0x18,
		PERSLEVEL = 0x30,
		LEVELS = 0x160,
		ACTORCOUNT = 0xA0,
		AACTORS = 0x98,
		CURACTOR = 0x8,
		MESH = 0x2f0,
		RELATIVELOC = 0x128,
		TEAMID = 0x1048,
	};
}
