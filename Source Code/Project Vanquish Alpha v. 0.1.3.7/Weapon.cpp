#include "Library.h"

WEAPON::WEAPON()
{
	Name = "default";
}
WEAPON::~WEAPON()
{
}
bool WEAPON::Load(std::string WeaponID)
{
	std::string ID;
	std::string WLoad;

	ifstream Load;
	Load.open(WEAPON_FILE, ios::in);

	if(!Load.is_open())
	{
		std::cout << "Cannot open weapon file!" << std::endl;
		getchar();
		return false;
	}
	else
	{
		while(ID != "[" + WeaponID + "]")
		{
			if(Load.eof())
			{
				return false;
			}

			getline(Load, ID);
		}

		if(ID != "[END WEAPON]" && ID == "[" + WeaponID + "]")
		{
			/* Get weapon's name */
			getline(Load, WLoad);
			Name = StrToCharPtr(WLoad);

			/* Get weapon's attack */
			getline(Load, WLoad);
			Attack = atoi(WLoad.c_str());

			/* Get weapon's magic attack */
			getline(Load, WLoad);
			MagicAttack = atoi(WLoad.c_str());

			/* Get weapon's critical */
			getline(Load, WLoad);
			Critical = atoi(WLoad.c_str());

			/* Get weapon's blocking (if it's a sword and shield; 0 otherwise) */
			getline(Load, WLoad);
			Blocking = atoi(WLoad.c_str());

			/* Get weapon's physical defense (if it's a sword and shield; 0 otherwise) */
			getline(Load, WLoad);
			PhyDef = atoi(WLoad.c_str());

			/* Get weapon's magical defense (if it's a sword and shield; 0 otherwise) */
			getline(Load, WLoad);
			MagDef = atoi(WLoad.c_str());

			/* Get weapon's cost */
			getline(Load, WLoad);
			BuyAmount = atoi(WLoad.c_str());

			/* Get weapon's level requirement */
			getline(Load, WLoad);
			LevelReq = atoi(WLoad.c_str());

			/* Get item's description */
			getline(Load, WLoad);
			Description = WLoad;

			SellAmount = BuyAmount * .75;
			Id = WeaponID;
			Type = 2;
			Size = true;

			if(Name == "default")
			{
				std::cout << "An error occured while loading the weapon!" << std::endl;
				return false;
			}
			return true;
		}
	}
	return false;
}