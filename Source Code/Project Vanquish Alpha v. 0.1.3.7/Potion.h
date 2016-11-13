#ifndef POTION_H
#define POTION_H

#define POTION_FILE "Data\\Items\\Potions\\Potions.txt"

class POTION : public ITEM
{
public:
	unsigned int HealthRestore;
	unsigned int ManaRestore;

	POTION();
	~POTION();

	virtual bool Load(std::string PotionID);
};

#endif