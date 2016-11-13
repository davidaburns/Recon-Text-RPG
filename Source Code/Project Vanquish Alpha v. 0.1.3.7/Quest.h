#ifndef QUEST_H
#define QUEST_H

#include "Library.h"

#define QUEST_FILE "Data\\Quests\\Quests.txt"
#define COMPLETED_QUESTS "Data\\Quests\\Completed.dat"

class QUEST
{
public:
	char* Name;
	std::string StartNPC;			// What NPC did this quest come from?
	std::string CompleteNPC;		// What NPC will finish this quest? If set to NULL, 
										//the quest will complete once the quota is met.

	std::string ID;
	std::string Description;

	bool Kill;
	std::string MonsterId;
	unsigned int MonsterAmount;

	bool Transport;
	std::string ItemId;
	unsigned int ItemAmount;

	unsigned int Gold;
	unsigned int Experience;

	LinkedList<ITEM> Rewards;

	QUEST();
	~QUEST();

	bool LoadQuest(std::string Id);
	void CompleteQuest();
	bool CheckCompletedQuests(std::string Id);
};

#endif