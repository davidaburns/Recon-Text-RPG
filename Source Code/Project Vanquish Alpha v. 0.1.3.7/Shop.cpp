#include "Library.h"

SHOP::SHOP()
{
}
SHOP::~SHOP()
{
}
void SHOP::LoadItems()
{
	ifstream Load;
	std::string TempString;
	std::string ItemID;

	Load.open(SHOP_ITEMS_FILE, ios::in);
	if (!Load.is_open())
	{
		std::cout << "Error openening: " << SHOP_ITEMS_FILE << std::endl;
		return;
	}

	while (!Load.eof())
	{
		getline(Load, TempString);
		if (TempString == '[' + Name + ']')
		{
			while (TempString != "[END SHOP]")
			{
				getline(Load, ItemID);
				if (ItemID == "[END SHOP]")
				{
					return;
				}

				ITEM* Item = new ITEM;
				ITEM* Weapon = new WEAPON;
				ITEM* Armor = new ARMOR;
				ITEM* Potion = new POTION;

				if(Item->Load(ItemID))
				{
					Items.push_back(*(Item));
				}
				else if(Weapon->Load(ItemID))
				{
					Items.push_back(*(Weapon));
				}
				else if(Armor->Load(ItemID))
				{
					Items.push_back(*(Armor));
				}
				else if(Potion->Load(ItemID))
				{
					Items.push_back(*(Potion));
				}
			}
		}
	}
}