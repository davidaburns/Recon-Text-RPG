#ifndef WEAPON_H
#define WEAPON_H

#define WEAPON_FILE "Data\\Items\\Weapons\\Weapons.txt"

class WEAPON : public ITEM
{
public:
	WEAPON();
	~WEAPON();

	/*unsigned int Attack;
	unsigned int MagicAttack;
	unsigned int Critical;*/

	bool Load(std::string WeaponID);
};

#endif