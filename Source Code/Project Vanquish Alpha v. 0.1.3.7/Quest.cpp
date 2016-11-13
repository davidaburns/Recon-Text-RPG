#include "Library.h"

QUEST::QUEST()
{
	Name = "NA";
	StartNPC = "NA";
	CompleteNPC = "NA";

	ID = "NA";
	Description = "NA";

	Kill = false;
	MonsterId = "NA";
	MonsterAmount = 0;

	Transport = false;
	ItemId = "NA";
	ItemAmount = 0;

	Gold = 0;
	Experience = 0;	
}

QUEST::~QUEST()
{
}

bool QUEST::LoadQuest(std::string Id)
{
	ifstream In;
	string Load;

	In.open(QUEST_FILE, ios::in);

	if(!In.is_open())
	{
		std::cout << "Cannot open quest file!" << std::endl;
		return false;
	}

	while(Load != "[" + Id + "]")
	{
		getline(In, Load);
		
		if(In.eof())
		{
			std::cout << "Quest not found in file!" << std::endl;
			return false;
		}
	}

	/* Set ID to ID */
	ID = Id;

	/* Get the quest's name */
	getline(In, Load);
	Name = StrToCharPtr(Load);
	
	/* Get the starting NPC */
	getline(In, Load);
	StartNPC = Load;

	/* Get finishing NPC */
	getline(In, Load);
	StartNPC = Load;

	/* Get description */
	getline(In, Load);
	Description = Load;

	/* Get if the quest is a kill a monster quest */
	getline(In, Load);
	if(Load == "1")
	{
		Kill = true;
	}
	else if(Load == "0")
	{
		Kill = false;
	}

	if(Kill == false)
	{
		MonsterId = "NA";
		MonsterAmount = 0;
	}
	else
	{
		/* Get the monster's ID */
		getline(In, Load);
		MonsterId = Load;

		/* Get the amount of monsters to kill */
		getline(In, Load);
		MonsterAmount = atoi(Load.c_str());
	}

	/* Get if the quest is a transport quest */
	getline(In, Load);
	if(Load == "1")
	{
		Transport = true;
	}
	else if(Load == "0")
	{
		Transport = false;
	}

	if(Kill == false)
	{
		ItemId = "NA";
		ItemAmount = 0;
	}
	else
	{
		/* Get the item's ID */
		getline(In, Load);
		ItemId = Load;

		/* Get the amount of items to transport */
		getline(In, Load);
		ItemAmount = atoi(Load.c_str());
	}

	/* Get the gold reward */
	getline(In, Load);
	Gold = atoi(Load.c_str());

	/* Get experience reward */
	getline(In, Load);
	Experience = atoi(Load.c_str());

	while(Load != "[END QUEST]")
	{
		getline(In, Load);

		ITEM* Item = new ITEM;
		ITEM* Weapon = new WEAPON;
		ITEM* Armor = new ARMOR;
		ITEM* Potion = new POTION;

		if(Item->Load(Load))
		{
			Rewards.Insert(*(Item));
		}
		else if(Weapon->Load(Load))
		{
			Rewards.Insert(*(Weapon));
		}
		else if(Armor->Load(Load))
		{
			Rewards.Insert(*(Armor));
		}
		else if(Potion->Load(Load))
		{
			Rewards.Insert(*(Potion));
		}
	}

	if(Name == "NA")
	{
		std::cout << "Quest did no load correctly." << std::endl;
		return false;
	}
	else
	{
		return true;
	}
}

void QUEST::CompleteQuest()
{
	ofstream Save;

	Save.open(COMPLETED_QUESTS, ios::out | ios::binary | ios::app);

	Save << ID << std::endl;
}

bool QUEST::CheckCompletedQuests(std::string Id)
{
	ifstream In;
	string Load;

	In.open(COMPLETED_QUESTS, ios::in | ios::binary);

	while(Load != Id)
	{
		getline(In, Load);

		if(In.eof())
		{
			return false;
		}
	}
	return true;
}