#include "Library.h"

INVENTORY::INVENTORY()
{
}
INVENTORY::~INVENTORY()
{
}

void INVENTORY::AddItem(ITEM *Item, unsigned short int Amount = 1)
{
	if(!Item->Size)
	{
		for(std::list<ITEM>::iterator itr = Inventory.begin();
			itr != Inventory.end(); itr++)
		{
			//Checks if you have this item by name and ID in your inventory
			if (itr->Name == Item->Name || itr->Id == Item->Id)
			{
				std::cout << itr->Name << ", Was found in your inventory. Adding " << Amount << " more\n";
				itr->Amount += Amount;
				
				//Check if user added more than the maximum amount and item: 100
				//If the user did, it gives the user's money back for each item over the maximum amount
				while(itr->Amount >= MAX_ITEM_AMOUNT)
				{
					Engine->Player.AddGold(itr->BuyAmount);
					itr->Amount--;
				}

				return;
			}
		}

		if(Amount >= MAX_ITEM_AMOUNT)
		{
			Amount = MAX_ITEM_AMOUNT;
		}

		Item->Amount = Amount;
		Inventory.push_back(*(Item));

		//Debug Info-----
		std::cout << "Item Added to Inventory: " << Item->Name << "\tAmount: " << Item->Amount;
	}
}
void INVENTORY::RemoveItem(ITEM* Item, unsigned short int Amount = 1)
{
	for (std::list<ITEM>::iterator itr = Inventory.begin();
		itr != Inventory.end(); itr++)
	{
		if (itr->Id == Item->Id)
		{
			//Subtract 1 from the items amount
			itr->Amount -= Amount;

			//Remove the item from your inventory if you ran out of that item
			if (itr->Amount <= 0)
			{
				Inventory.erase(itr);
				std::cout << "Item: " << Item->Id << " removed!" << std::endl << std::endl;
				break;
			}
		}
	}
}
void INVENTORY::ListInventory()
{
	if (Inventory.size() == 0)
	{
		std::cout << "Your inventory is empty." << std::endl;
		return;
	}
	std::cout << "Inventory\n--------------------\n";
	for (std::list<ITEM>::iterator itr = Inventory.begin();
		itr != Inventory.end(); itr++)
	{
		std::cout << itr->Name << " x " << itr->Amount;
		std::cout << "\t" << TranslateType(itr->Type) << std::endl;
	}
}
void INVENTORY::ListInventoryDetailed()
{
	if (Inventory.size() == 0)
	{
		std::cout << "Your inventory is empty." << std::endl;
		return;
	}
	for (std::list<ITEM>::iterator itr = Inventory.begin();
		itr != Inventory.end(); itr++)
	{
		std::cout << "Item Id: " << itr->Id;
		std::cout << "\tItem Name: " << itr->Name;
		std::cout << "\tItem Amount: " << itr->Amount;
		std::cout << "\tItem Type: " << TranslateType(itr->Type) << std::endl;
	}
}
char* INVENTORY::TranslateType(unsigned int Type)
{
	switch(Type)
	{
		case 0:
			return "Type Not Set";
		case 1: 
			return "Consumable";
		case 2:
			return "Equip";
		case 3: 
			return "Misc.";
		case 50:
			return "KeyItem";
		default:
			return "Unkown Type";
	}
}