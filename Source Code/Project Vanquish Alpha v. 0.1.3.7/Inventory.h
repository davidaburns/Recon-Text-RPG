#ifndef INVENTORY_H
#define INVENTRY_H

#include "Library.h"

class INVENTORY
{
private:
	std::list<ITEM> Inventory;

public:
	INVENTORY();
	~INVENTORY();

	void AddItem(ITEM* Item, unsigned short int Amount);
	void RemoveItem(ITEM* Item, unsigned short int Amount);
	void ListInventory();
	void ListInventoryDetailed();
	char* TranslateType(unsigned int Type);
};
#endif