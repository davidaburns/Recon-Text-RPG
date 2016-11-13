#ifndef ITEM_H
#define ITEM_H

#define ITEM_FILE "Data//Items//Items.txt"
#define MAX_ITEM_AMOUNT 100			//Only works if items is size 0

class ITEM
{
public:
	bool Size;							//False - small enough to stack (Potions, misc. items, etc.)
										//True - too big to have stacks (Weapons, armor, etc.)
	unsigned int Type;					//Item type
	unsigned int BuyAmount;				//Cost of the item
	unsigned int SellAmount;			//Amount it sells for
	unsigned int SortNumber;			//Item's sorting number
	unsigned short int Amount;			//How many of that item you have
	unsigned short int LevelReq;		//Level requirement of the item
	
	unsigned int PhyDef;
	unsigned int MagDef;
	unsigned short int Blocking;
	
	unsigned int Attack;
	unsigned int MagicAttack;
	unsigned int Critical;

	char* Name;							//Item's name
	std::string Description;			//A short description of the item
	std::string Id;						//The unique id of the item

	ITEM();
	~ITEM();

	virtual bool Load(string ItemID);	//Load item by ID
};

#endif