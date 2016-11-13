#ifndef MONSTER_H
#define MONSTER_H

#define MONSTER_FILE "Data//Monsters//Monsters.txt"

class MONSTER : public CHARACTER
{
public:
	unsigned int GoldDrop;

	unsigned short int Type;

	double Exp;

	bool QuestMonster;

	LinkedList<ITEM> KillRewards;

	MONSTER();
	~MONSTER();

	/* Give function */
	double GiveExp();

	/* Load mosnter function */
	virtual void Load(std::string MonsterID);
};

#endif