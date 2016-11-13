#include "Library.h"


void MAGIC::AddMgcAtk(char* Name, unsigned int Type, unsigned int Id, unsigned int AtkElem, 
			unsigned int Lv, unsigned int MinDmg, unsigned int MaxDmg, unsigned int MpCost, 
			char* AtkDesc)
		{
			MagicSkill = new Magic;

			for(std::list<MAGIC_SKILL>::iterator itr = MagicList.begin();
				itr != MagicList.end(); itr++)
			{
				if (itr->MgcAtkName == Name || itr->Id == Id)
				{
					std::cout << "You already know " << itr->MgcAtkName << std::endl;
					return;
				}
			}

			MagicSkill->MgcAtkName = Name;
			MagicSkill->Id = Id;
			MagicSkill->MgcAtkElem = AtkElem;
			MagicSkill->MgcAtkLv = Lv;
			MagicSkill->MgcAtkMinDmg = MinDmg;
			MagicSkill->MgcAtkMaxDmg = MaxDmg;
			MagicSkill->MgcAtkType = Type;
			MagicSkill->MpCost = MpCost;
			MagicSkill->AtkDesc = AtkDesc;

			MagicList.push_back(*(MagicSkill));
		}
void MAGIC::ListMagic()
{
	if (MagicList.size() == 0)
	{
		std::cout << "You do not know any magic abilities." << std::endl;
		return;
	}
	
	std::cout << "Name \t Mp \t Description" << std::endl;

	for(std::list<MAGIC_SKILL>::iterator itr = MagicList.begin();
		itr != MagicList.end(); itr++)
	{
		std::cout << itr->MgcAtkName << " \t " << itr->MpCost << " \t " << itr->AtkDesc << std::endl;
	}
}