#ifndef CHARACTER_H
#define CHARACTER_H

class CHARACTER
{
public:
	char* Name;

	unsigned short Hp;
	unsigned short MaxHp;
	unsigned short Mp;
	unsigned short MaxMp;

	unsigned short Str;
	unsigned short Def;
	unsigned short MgcStr;
	unsigned short MgcDef;
	unsigned short Agil;
	unsigned short Intel;
	unsigned short Luck;
	
	unsigned short Level;

	CHARACTER();
	~CHARACTER();

	/* Add health and MP */
	void AddHp(int Hp);
	void AddMp(int Mp);
	
	/* Subtract health and MP */
	void SubHp(int Hp);
	void SubMp(int Mp);

	/* Virtual load function for the player and monsters */
	virtual void Load();
};

#endif