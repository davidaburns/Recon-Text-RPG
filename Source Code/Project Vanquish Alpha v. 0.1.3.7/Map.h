#ifndef MAP_H
#define MAP_H

#include "Library.h"

#define MAP_FILE "Data//Maps//Maps.txt"
#define WARP_FILE "Data//Maps//Warps.txt"
#define NPC_FILE "Data//Maps//Npcs.txt"
#define SHOP_FILE "Data//Maps//Shops.txt"

typedef struct Warp
{
	std::string WarpLocation;
	std::string WarpDestination;

	int WarpLocX, WarpLocY;
	int WarpDesX, WarpDesY;
}WARP;

typedef struct Npc
{
	std::string Name;
	std::string Script;

	std::string Map;
	int MapX;
	int MapY;
}NPC;

class MAP
{
private:
	bool AllocateMap(std::string MapName); //Sets the width and height, and allocates memory for the map

public:
	unsigned short int* TheMap;

	unsigned short int MapWidth;
	unsigned short int MapHeight;

	unsigned short int ViewWidth;
	unsigned short int ViewHeight;

	short int XOffSet;
	short int YOffSet;

	std::string CurrentMapLoaded;

	std::list<std::string> Maps;
	std::list<WARP> Warps;
	std::list<NPC> Npcs;
	std::list<SHOP> Shops;
	
	WARP* Warp;
	NPC* Npc;
	SHOP* Shop;

	MAP();
	~MAP();

	void DisplayMap();
	void SelectMap();
	void WarpPlayer(int PlayerLocX, int PlayerLocY);

	bool LoadMapNames();
	bool LoadMap(std::string MapName);
	bool LoadWarps();
	void LoadNpcs();
	void LoadShops();

	//For Debuging purposes only
	bool FindWarps();
	void FindNpcs();
	void FindShops();
	
	void ClearMapsList();
	void ClearWarps();
	void ClearNpcs();
	void ClearShops();

	int GetPlayerX();
	int GetPlayerY();
	std::string GetNpc(int PlayerY, int PlayerX);
	std::string GetShop(int PlayerY, int PlayerX);
	SHOP GetShop(const char* ShopName);
};

#endif