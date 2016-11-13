#include "Library.h"

POTION::POTION()
{
}
POTION::~POTION()
{
}

bool POTION::Load(std::string PotionID)
{
	std::string ID;
	std::string PLoad;

	ifstream Load;
	Load.open(POTION_FILE, ios::in);

	if(!Load.is_open())
	{
		std::cout << "Cannot open potion file!" << std::endl;
		getchar();
		return false;
	}
	else
	{
		while(ID != "[" + PotionID + "]")
		{
			if(Load.eof())
			{
				return false;
			}

			getline(Load, ID);
		}

		if(ID != "[END POTION]" && ID == "[" + PotionID + "]")
		{
			/* Get potion's name */
			getline(Load, PLoad);
			Name = StrToCharPtr(PLoad);

			/* Get potion's health restore */
			getline(Load, PLoad);
			HealthRestore = atoi(PLoad.c_str());

			/* Get potion's mana restore */
			getline(Load, PLoad);
			ManaRestore = atoi(PLoad.c_str());

			/* Get potion's cost */
			getline(Load, PLoad);
			BuyAmount = atoi(PLoad.c_str());

			/* Get item's description */
			getline(Load, PLoad);
			Description = PLoad;

			SellAmount *= (int) .75;
			Id = PotionID;
			Type = 1;
			Size = false;
			LevelReq = 0;

			PhyDef = 0;
			MagDef = 0;
			Blocking = 0;
			Attack = 0;
			MagicAttack = 0;
			Critical = 0;

			if(Name == "default")
			{
				std::cout << "An error occured while loading the potion!" << std::endl;
				getchar();
			}
			return true;
		}
	}
	return false;
}