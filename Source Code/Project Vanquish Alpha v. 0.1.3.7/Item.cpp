#include "Library.h"

ITEM::ITEM()
{
	Name = "default";
	Amount = 0;
}
ITEM::~ITEM()
{
}
bool ITEM::Load(string ItemID)
{
	std::string ID;
	std::string ILoad;

	ifstream Load;
	Load.open(ITEM_FILE, ios::in);

	if(!Load.is_open())
	{
		std::cout << "Cannot open item file!" << std::endl;
		getchar();
		return false;
	}
	else
	{
		while(ID != "[" + ItemID + "]")
		{
			if(Load.eof())
			{
				return false;
			}

			getline(Load, ID);
		}

		if(ID != "[END ITEM]" && ID == "[" + ItemID + "]")
		{
			/* Get item's name */
			getline(Load, ILoad);
			Name = StrToCharPtr(ILoad);

			/* Get item's size */
			getline(Load, ILoad);
			Size = StrToBool(ILoad);

			/* Get item's type */
			getline(Load, ILoad);
			Type = atoi(ILoad.c_str());

			/* Get item's cost */
			getline(Load, ILoad);
			BuyAmount = atoi(ILoad.c_str());

			/* Get item's level requirement */
			getline(Load, ILoad);
			LevelReq = atoi(ILoad.c_str());

			/* Get item's description */
			getline(Load, ILoad);
			Description = ILoad;

			SellAmount *= (int) .75;
			Id = ItemID;
			PhyDef = 0;
			MagDef = 0;
			Blocking = 0;
			Attack = 0;
			MagicAttack = 0;
			Critical = 0;

			if(Name == "default")
			{
				std::cout << "An error occured while loading the item!" << std::endl;
				getchar();
			}
			return true;
		}
	}
	return false;
}