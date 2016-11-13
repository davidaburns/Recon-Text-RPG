#ifndef SHOP_H
#define SHOP_H

#include "Library.h"

#define SHOP_ITEMS_FILE "Data//Shops//ShopItems.txt"

class SHOP
{
private:
public:

	SHOP();
	~SHOP();

	std::string Name;
	std::string Script;
	std::string Map;
	int MapX;
	int MapY;

	std::list<ITEM> Items;

	void LoadItems();	//Loads all of the items to sell for that shop
};

#endif