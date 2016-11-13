#include "Library.h"
#include <fstream>

MONSTER::MONSTER()
{
	Name = "default";
	
	Exp = 38;
	QuestMonster = false;
}
MONSTER::~MONSTER()
{
}

/* Give functions */
double MONSTER::GiveExp()
{
	Exp = (double) ((Hp * Level + (Engine->Player.Hp - Hp) * 9) / 2) * Engine->Player.ExpLevelBonus;

	return Exp;
}

void MONSTER::Load(std::string Map)
{
	std::string ID;
	std::string MLoad;
	int MonsterNumber;
	int TimesRan = 1;

	ifstream Load;
	Load.open(MONSTER_FILE, ios::in);

	MonsterNumber = rand()%6;

	std::string MonsterID = Map;
	MonsterID += MonsterNumber;

	if(!Load.is_open())
	{
		std::cout << "Cannot load monster file!" << std::endl;
		getchar();
		return;
	}
	else
	{
		while(ID != "[" + MonsterID + "]")
		{
			if(Load.eof())
			{
				TimesRan++;

				if(TimesRan >= 5)
				{
					return;
				}

				std::string Temp = MonsterID;
				while(Temp != MonsterID)
				{
					MonsterNumber = rand()%6;
					MonsterID = Map;
					MonsterID += MonsterNumber;
				}

				Load.seekg(0, ios::beg);
			}

			getline(Load, ID);
		}

		if(ID != "[END MONSTER]" && ID == "[" + MonsterID + "]")
		{
			/* Get monster's name */
			getline(Load, MLoad);
			Name = StrToCharPtr(MLoad);

			/* Setting monsters' level */
			Level = Engine->Player.Level + MonsterNumber;

			/* Get tank stats */
			getline(Load, MLoad);
			if(atoi(MLoad.c_str()) == 0)
			{
				Type = 0;

				Hp = 40 + (8 * Level - 1);
				Str = 6 + (4 * Level - 1);
				Def = 6 + (4 * Level - 1);

				Mp = 40 + Level - 1;
				MgcStr = 6 + Level - 1;
				MgcDef = 6 + Level - 1;

				Agil = 6 + Level - 1;
				Intel = 6 + Level - 1;
				Luck = 6 + Level - 1;
			}

			/* Get mage stats */
			else if(atoi(MLoad.c_str()) == 1)
			{
				Type = 1;

				Hp = 40 + Level - 1;
				Str = 6 + Level - 1;
				Def = 6 + Level - 1;

				Mp = 40 + (8 * Level - 1);
				MgcStr = 6 + (4 * Level - 1);
				MgcDef = 6 + (4 *Level - 1);

				Agil = 6 + Level - 1;
				Intel = 6 + Level - 1;
				Luck = 6 + Level - 1;
			}

			/* Get normal stats */
			else if(atoi(MLoad.c_str()) == 2)
			{
				Type = 2;

				Hp = 40 + (4 * Level - 1);
				Str = 6 + (2 * Level - 1);
				Def = 6 + (2 * Level - 1);

				Mp = 40 + (4 * Level - 1);
				MgcStr = 6 + (2 * Level - 1);
				MgcDef = 6 + (2 * Level - 1);

				Agil = 6 + Level - 1;
				Intel = 6 + (2 * Level - 1);
				Luck = 6 + Level - 1;
			}

			/* Get lucky stats */
			else if(atoi(MLoad.c_str()) == 3)
			{
				Type = 3;

				Hp = 40 + Level - 1;
				Str = 6 + Level - 1;
				Def = 6 + Level - 1;

				Mp = 40 + Level - 1;
				MgcStr = 6 + Level - 1;
				MgcDef = 6 + Level - 1;

				Agil = 6 + (6 * Level - 1);
				Intel = 6 + Level - 1;
				Luck = 6 + (8 * Level - 1);
			}

			/* Get rabbit stats */
			else if(atoi(MLoad.c_str()) == 4)
			{
				Type = 4;

				Hp = 40 + ((Level - 1) / 2);
				Str = 6 + Level - 1;
				Def = 6 + Level - 1;

				Mp = 40 + Level - 1;
				MgcStr = 6 + Level - 1;
				MgcDef = 6 + Level - 1;

				Agil = 6 + (8 * Level - 1);
				Intel = 6 + Level - 1;
				Luck = 6 + (6 * Level - 1);
			}

			/* Get turtle stats */
			else if(atoi(MLoad.c_str()) == 5)
			{
				Type = 5;

				Hp = 40 + (6 * Level - 1);
				Str = 6 + Level - 1;
				Def = 6 + (8 * Level - 1);

				Mp = 40 + Level - 1;
				MgcStr = 6 + Level - 1;
				MgcDef = 6 + Level - 1;

				Agil = 6 + ((Level - 1) / 2);
				Intel = 6 + Level - 1;
				Luck = 6 + Level - 1;
			}

			/* Get guardian stats */
			else if(atoi(MLoad.c_str()) == 6)
			{
				Type = 6;

				Hp = 40 + Level - 1;
				Str = 6 + (8 * Level - 1);
				Def = 6 + Level - 1;

				Mp = 40 + Level - 1;
				MgcStr = 6 + (6 * Level - 1);
				MgcDef = 6 + ((Level - 1) / 2);

				Agil = 6 + Level - 1;
				Intel = 6 + Level - 1;
				Luck = 6 + Level - 1;
			}

			/* Get brainiac stats */
			else if(atoi(MLoad.c_str()) == 7)
			{
				Type = 7;

				Hp = 40 + Level - 1;
				Str = 6 + (6 * Level - 1);
				Def = 6 + ((Level - 1) / 2);

				Mp = 40 + Level - 1;
				MgcStr = 6 + (8 * Level - 1);
				MgcDef = 6 + Level - 1;

				Agil = 6 + Level - 1;
				Intel = 6 + (8 * Level - 1);
				Luck = 6 + Level - 1;
			}

			/* Get if the monster is a quest monster or not */
			getline(Load, MLoad);
			if(atoi(MLoad.c_str()) == 1)
			{
				QuestMonster = true;

				Hp *= 2;
				Str *= 2;
				Def *=2;

				Mp *= 2;
				MgcStr *= 2;
				MgcDef *= 2;

				Agil *= 2;
				Intel *= 2;
				Luck *= 2;
			}

			while(MLoad != "[END MONSTER]")
			{
				getline(Load, MLoad);

				ITEM* Item = new ITEM;
				ITEM* Weapon = new WEAPON;
				ITEM* Armor = new ARMOR;
				ITEM* Potion = new POTION;

				if(Item->Load(MLoad))
				{
					KillRewards.Insert(*(Item));
				}
				else if(Weapon->Load(MLoad))
				{
					KillRewards.Insert(*(Weapon));
				}
				else if(Armor->Load(MLoad))
				{
					KillRewards.Insert(*(Armor));
				}
				else if(Potion->Load(MLoad))
				{
					KillRewards.Insert(*(Potion));
				}
			}

			GoldDrop = rand()%(Level * 3) + (Level - 1);
		}
		else if(Name == "default")
		{
			std::cout << "An error occured while loading the monster" << std::endl;
			getchar();
		}
	}
}