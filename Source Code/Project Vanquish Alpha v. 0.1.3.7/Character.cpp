#include "Library.h"
using namespace std;

CHARACTER::CHARACTER()
{
}
CHARACTER::~CHARACTER()
{
}

/* Add health and MP functions */
void CHARACTER::AddHp(int HpAmount)
{
	Hp += HpAmount;

	if(Hp >= MaxHp)
	{
		Hp = MaxHp;
	}
}
void CHARACTER::AddMp(int MpAmount)
{
	Mp += MpAmount;

	if(Mp >= MaxMp)
	{
		Mp = MaxMp;
	}
}

/* Subtract health and MP functions*/
void CHARACTER::SubHp(int HpAmount)
{
	Hp -= HpAmount;

	if(Hp < 0)
	{
		Hp = 0;
	}
}
void CHARACTER::SubMp(int MpAmount)
{
	Mp -= MpAmount;
	
	if(Mp < 0)
	{
		Mp = 0;
	}
}

/* Virtual load function for the player and monsters */
void CHARACTER::Load()
{
}