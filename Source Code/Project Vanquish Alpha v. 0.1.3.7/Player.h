#ifndef PLAYER_H
#define PLAYER_H

#include "Library.h"
using namespace std;

#define MAX_HP 999999
#define MAX_MP 999999
#define MAX_GOLD 999999999
#define MAX_LV 99

class PLAYER : public CHARACTER
{
private:
	unsigned int Gold;
	unsigned int *BaseExp;
	unsigned short AttribPoints;
	double Exp;

protected:

public:
	int X, Y;
	double ExpLevelBonus;

	bool AttribManual;

	bool AttribAutoSet;
	unsigned short int AttribSet;

	bool AttribAutoGame;
	unsigned int Deaths;
	unsigned int Kills;
	unsigned long long int PhyAttacks;
	unsigned long long int PhyHits;
	unsigned long long int MagAttacks;
	unsigned long long int MagHits;

	std::string CurrentMap;

	LinkedList<QUEST> Quests;
	INVENTORY* Inventory;
	MAGIC* Magic;
	

	PLAYER();
	~PLAYER();

	/* Add functions */
	void AddX(int X);
	void AddY(int Y);

	void AddGold(int Gold);
	void AddExp(double Exp);
	void AddLevel(int Level);
	void AddAttribPoints(int AttribPoints);
	void AddStats();
	
	/* Subtract functions */
	void SubGold(int Gold);

	void Save();
};
#endif

