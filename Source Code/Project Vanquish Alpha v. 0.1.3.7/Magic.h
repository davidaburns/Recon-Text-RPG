#ifndef MAGIC_H
#define MAGIC_H

/*
MgcAtkName: Is the name of the magic atk ex. Fire 1, Ice 3, etc
MgcAtkType: Is the type of magic skill it is:
		0 - Type Not set
		1 - Damage Dealing
		2 - Healing
MgcAtkElem: Is the element of the magic attack:
		0 - Neutral Element	3 - Water		6 - Dark
		1 - Fire			4 - Wind		7 - Holy
		2 - Ice				5 - Earth

*/



#include "Library.h"

typedef struct Magic
{
	char* MgcAtkName;
	unsigned int Id;
	unsigned int MgcAtkType;
	unsigned int MgcAtkElem;
	unsigned int MgcAtkLv;
	unsigned int MgcAtkMinDmg;
	unsigned int MgcAtkMaxDmg;
	unsigned int MpCost;
	unsigned int PriceCost;
	char* AtkDesc;
}MAGIC_SKILL;


class MAGIC
{
private:
	std::list<MAGIC_SKILL> MagicList;
	MAGIC_SKILL* MagicSkill;

protected:

public:

	void AddMgcAtk(char* Name, unsigned int Type, unsigned int Id, unsigned int AtkElem, 
		unsigned int Lv, unsigned int MinDmg, unsigned int MaxDmg, unsigned int MpCost, 
		char* AtkDesc);
	void ListMagic();
};
#endif