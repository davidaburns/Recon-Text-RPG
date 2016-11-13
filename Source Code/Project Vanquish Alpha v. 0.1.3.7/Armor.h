#ifndef ARMOR_H
#define ARMOR_H

#define ARMOR_FILE "Data\\Items\\Armor\\Armor.txt"

class ARMOR : public ITEM
{
public:
	ARMOR();
	~ARMOR();

	/*unsigned int PhyDef;
	unsigned int MagDef;
	unsigned short int Blocking;*/

	/* Loading function */
	virtual bool Load(std::string ArmorID);
};

#endif