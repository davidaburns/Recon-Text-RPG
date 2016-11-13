#include "Library.h"

ARMOR::ARMOR()
{
	Name = "default";
}
ARMOR::~ARMOR()
{
}
bool ARMOR::Load(std::string ArmorID)
{
	std::string ID;
	std::string ALoad;

	ifstream Load;
	Load.open(ARMOR_FILE, ios::in);

	if(!Load.is_open())
	{
		std::cout << "Cannot open armor file!" << std::endl;
		getchar();
		return false;
	}
	else
	{
		while(ID != "[" + ArmorID + "]")
		{
			if(Load.eof())
			{
				return false;
			}

			getline(Load, ID);
		}

		if(ID != "[END ARMOR]" && ID == "[" + ArmorID + "]")
		{
			/* Get armor's name */
			getline(Load, ALoad);
			Name = StrToCharPtr(ALoad);

			/* Get armor's physical defence */
			getline(Load, ALoad);
			PhyDef = atoi(ALoad.c_str());

			/* Get armor's magical defence */
			getline(Load, ALoad);
			MagDef = atoi(ALoad.c_str());

			/* Get armor's blocking */
			getline(Load, ALoad);
			Blocking = atoi(ALoad.c_str());

			/* Get armor's cost */
			getline(Load, ALoad);
			BuyAmount = atoi(ALoad.c_str());

			/* Get armor's level requirement */
			getline(Load, ALoad);
			LevelReq = atoi(ALoad.c_str());

			/* Get item's description */
			getline(Load, ALoad);
			Description = ALoad;

			SellAmount *= (int) .75;
			Id = ArmorID;
			Type = 2;
			Size = true;
			Attack = 0;
			MagicAttack = 0;
			Critical = 0;

			if(Name == "default")
			{
				std::cout << "An error occured while loading the armor!" << std::endl;
				return false;
			}
			return true;
		}
	}
	return false;
}