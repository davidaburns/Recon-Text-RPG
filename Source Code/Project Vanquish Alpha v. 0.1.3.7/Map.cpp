#include "Library.h"

MAP::MAP()
{
	TheMap = (unsigned short int*) malloc(sizeof(unsigned short int));

	MapWidth = 0;
	MapHeight = 0;

	XOffSet = 0;
	YOffSet = 0;
}
MAP::~MAP()
{
	free(TheMap);
}
void MAP::DisplayMap()
{
	if(XOffSet >= 0 && YOffSet >= 0 &&
		XOffSet <= MapWidth - ViewWidth && 
		YOffSet <= MapHeight - ViewHeight)
	{
		XOffSet = GetPlayerX() - ((ViewWidth - 1) / 2);
		YOffSet = GetPlayerY() - ((ViewHeight - 1) / 2);
	}

	if(MapWidth < ViewWidth)
	{
		ViewWidth = MapWidth;
	}
	if(MapHeight < ViewHeight)
	{
		ViewHeight = MapHeight;
	}
	if(XOffSet < 0)
	{
		XOffSet = 0;
	}
	else if(XOffSet > MapWidth - ViewWidth)
	{
		XOffSet = MapWidth - ViewWidth;
	}

	if(YOffSet < 0)
	{
		YOffSet = 0;
	}
	else if(YOffSet > MapHeight - ViewHeight)
	{
		YOffSet = MapHeight - ViewHeight;
	}

	for(int y = 0; y < ViewHeight; y++)
	{
		for(int x = 0; x < ViewWidth; x++)
		{
			switch(*(TheMap + (x + XOffSet) +((y + YOffSet) * MapWidth)))
			{
			case 0:
				std::cout << " ";
				break;
			case 1:
				Engine->Screen.DrawColorText(" ", 255);
				break;
			case 2:
				Engine->Screen.DrawColorText("P", 10);
				break;
			case 3:
				Engine->Screen.DrawColorText("N", 14);
				break;
			case 4:
				Engine->Screen.DrawColorText(" ", 221);
				break;
			case 5:
				Engine->Screen.DrawColorText("S", 7);
				break;
			case 6:
				Engine->Screen.DrawColorText("I", 15);
				break;
			case 7:
				Engine->Screen.DrawColorText("M", 12);
				break;
			default:
				std::cout << "?";
				break;
			}
		}
		cout << endl;
	}
}
bool MAP::LoadMap(std::string MapName)
{
	if(AllocateMap(MapName))
	{
		int TempInt;
		char* TempChar;
		char Loading[512];
		std::string Map = "";
		ifstream Load;

		Load.open(MAP_FILE, ios::in);

		while(Map != MapName)
		{
			getline(Load, Map);
		}

		if(Map != "[END MAP]" && MapName == Map)
		{
			for(int y = 0; y < MapHeight; y++)
			{
				TempChar = "";

				Load.getline(Loading, 1024);

				TempInt = strtol(Loading, &TempChar, 10);

				for(int x = 0; x < MapWidth && TempChar != NULL; x++)
				{
					*(TheMap + x + (y * MapWidth)) = TempInt;
					TempInt = strtol(TempChar, &TempChar, 10);
				}
			}
		}
		if(*(TheMap + (MapWidth - 1) + ((MapHeight - 1) * MapWidth)) == NULL)
		{
			std::cout << "An error occured while loading the map." << std::endl;
			getchar();
			return false;
		}

		
		ViewWidth = 15;
		ViewHeight = 11;

		Engine->Player.CurrentMap = MapName;
		CurrentMapLoaded = MapName;

		LoadWarps();
		LoadNpcs();
		LoadShops();

		Load.close();
		return true;
	}
	else
	{
		std::cout << "Cannot allocate map." << std::endl;
		getchar();
		return false;
	}
}
bool MAP::AllocateMap(std::string MapName)
{
	// Reset values
	MapWidth = 0;
	MapHeight = 0;

	char Reading[1024];
	bool InNum = false;
	std::string Map = "";
	ifstream Read;

	Read.open(MAP_FILE, ios::in);

	if(!Read.is_open())
	{
		std::cout << "An error occured while opening the map." << std::endl;
		return false;
	}
	else
	{
		while(Map != MapName)
		{
			getline(Read, Map);

			if(Read.eof())
			{
				std::cout << "Map file not found!" << std::endl;
				return false;
			}
		}

		if(Map != "[END MAP]" && Map == MapName)
		{
			Read.getline(Reading, 1024);

			for(int i = 0; Reading[i] != NULL; i++)
			{
				if(Reading[i] == ' ')
				{
					InNum = false;
				}
				else if(Reading[i] == '\n')
				{
					InNum = false;
				}
				else
				{
					if(InNum)
					{
						continue;
					}
					else
					{
						MapWidth++;
						InNum = true;
					}
				}
			}
		}
		while(Reading[0] != '[')
		{
			Read.getline(Reading, 1024);
			MapHeight++;
		}
		if(MapWidth == 0 || MapHeight == 0)
		{
			std::cout << "An error occurred while trying to get the MapWidth and MapHeight." << std::endl;
			return false;
		}
		else
		{
			Read.close();

			TheMap = (unsigned short int*) realloc(TheMap, MapWidth * MapHeight * sizeof(unsigned short int*));
			*(TheMap + (MapWidth - 1) + ((MapHeight - 1) * MapWidth)) = NULL;
			return true;
		}
	}
}

bool MAP::LoadMapNames()
{
	//This function loads all of the map names into a STL List so that the user
	//can select one of them to load, may be used later for warps.

	std::string MapName = "";
	ifstream Load;

	Load.open(MAP_FILE, ios::in);
	if (!Load.is_open())
	{
		std::cout << "Failed to open Maps.txt" << std::endl;
		return false;
	}

	while (!Load.eof())
	{
		getline(Load, MapName);
		if (MapName[0] == '[' && MapName != "[END MAP]")
		{
			Maps.push_back(MapName);
		}
	}

	return true;
}
void MAP::SelectMap()
{
	int CursorPosition = 1;			//For keeping track of which map you chose
	int CursorPositionY = 1;		//For Drawing the Cursor on the right line

	int MapCounter = 0;				//To keep track of how man maps there are and to compare which map you chose so it can load the right map
	char KeyInput = 'z';			//to hold user input

	Engine->Screen.ClearScreen();
	Engine->Screen.DrawColorText("Vanquish Map Loader\n", 10);

	for(std::list<std::string>::iterator itr = Maps.begin();
		itr != Maps.end(); itr++)
	{
		std::cout << ". " << *itr << std::endl;
		MapCounter++;
	}


	while((int)KeyInput != 13)
	{
		Engine->Screen.SetCursorPosition(0, CursorPositionY);
		std::cout << ">";

		if (_kbhit() != 0)
		{
			KeyInput = _getch();
			switch((int)KeyInput)
			{
			case 27:
				{
					Maps.clear();
					return;
				}
			case 72:
				{
					Engine->Screen.SetCursorPosition(0, CursorPositionY);
					std::cout << ".";

					if (CursorPosition <= 1 || CursorPositionY <= 1)
					{
						CursorPosition = MapCounter;
						CursorPositionY = MapCounter;

						break;
					}

					CursorPosition -= 1;
					CursorPositionY -= 1;

					break;
				}
			case 80:
				{
					Engine->Screen.SetCursorPosition(0, CursorPositionY);
					std::cout << ".";

					if (CursorPosition >= MapCounter || CursorPositionY >= MapCounter)
					{
						CursorPosition = 1;
						CursorPositionY = 1;

						break;
					}

					CursorPosition += 1;
					CursorPositionY += 1;

					break;
				}
			}
		}
	}

	MapCounter = 0;
	for (std::list<std::string>::iterator itr = Maps.begin();
		MapCounter != CursorPosition; itr++)
	{
		MapCounter++;
		if (MapCounter == CursorPosition)
		{
			LoadMap(*itr);
		}
	}

	Maps.clear();
}
void MAP::ClearMapsList()
{
	Maps.clear();
}
bool MAP::LoadWarps()
{
	std::string TempString = "";
	ifstream Load;

	Load.open(WARP_FILE, ios::in);
	if (!Load.is_open())
	{
		std::cout << "Failed to open Maps.txt" << std::endl;
		return false;
	}

	while (!Load.eof())
	{
		getline(Load, TempString);
		if (TempString == CurrentMapLoaded && TempString != "[END WARP]")
		{
			Warp = new WARP;

			Warp->WarpLocation = TempString;

			if (TempString == CurrentMapLoaded)
			{
				getline(Load, TempString);
				Warp->WarpDestination = TempString;

				getline(Load, TempString);
				Warp->WarpLocX = atoi(TempString.c_str());

				getline(Load, TempString);
				Warp->WarpLocY = atoi(TempString.c_str());

				getline(Load, TempString);
				Warp->WarpDesX = atoi(TempString.c_str());

				getline(Load, TempString);
				Warp->WarpDesY = atoi(TempString.c_str());

				Warps.push_back(*(Warp));
			}
		}
	}

	return true;
}
void MAP::WarpPlayer(int PlayerLocX, int PlayerLocY)
{
	std::cout << "Warping Player..." << std::endl;

	for(std::list<WARP>::iterator itr = Warps.begin();
		itr != Warps.end(); itr++)
	{
		if (itr->WarpLocX == PlayerLocX)
		{
			if (itr->WarpLocY == PlayerLocY)
			{
				if (Engine->Player.CurrentMap == itr->WarpDestination)
				{
					LoadMap(itr->WarpDestination);

					//This is debug text to show were the player was warped from, and to.
					std::cout << "Warped Player From: " << itr->WarpLocation << std::endl;
					std::cout << "To: " << itr->WarpDestination << std::endl;
					
					while(GetPlayerX() != 0 && GetPlayerY() != 0)
					{
						 *(TheMap + GetPlayerX() + (GetPlayerY() * MapWidth)) = 0;
					}
					*(TheMap + itr->WarpDesX + (itr->WarpDesY * MapWidth)) = 2;
					Engine->Player.X = itr->WarpDesX;
					Engine->Player.Y = itr->WarpDesY;

					ClearWarps();
					LoadWarps();
					
					return;
				}
				else
				{
					LoadMap(itr->WarpDestination);

					//This is debug text to show were the player was warped from, and to.
					std::cout << "Warped Player From: " << itr->WarpLocation << std::endl;
					std::cout << "To: " << itr->WarpDestination << std::endl;

					while(GetPlayerX() != 0 && GetPlayerY() != 0)
					{
						 *(TheMap + GetPlayerX() + (GetPlayerY() * MapWidth)) = 0;
					}
					*(TheMap + itr->WarpDesX + (itr->WarpDesY * MapWidth)) = 2;
					Engine->Player.X = itr->WarpDesX;
					Engine->Player.Y = itr->WarpDesY;

					ClearWarps();
					LoadWarps();

					return;
				}
			}
		}
	}

	std::cout << "Warp not found in Warps.txt" << std::endl;
}
bool MAP::FindWarps()
{
	ClearWarps();
	LoadWarps();

	if (Warps.size() == 0)
	{
		std::cout << "There are no warps on this map." << std::endl;
		return false;
	}

	std::cout << "Found Warps At\n";
	for(std::list<WARP>::iterator itr = Warps.begin();
		itr != Warps.end(); itr++)
	{
		std::cout << itr->WarpLocation << "\t" << itr->WarpDestination << "\t"
			<< itr->WarpLocX << ", " << itr->WarpLocY << "\t"
			<< itr->WarpDesX << ", " << itr->WarpDesY << endl;
	}

	std::cout << std::endl;
	return true;
}
void MAP::ClearWarps()
{
	Warps.clear();
}
void MAP::LoadNpcs()
{
	ifstream Load;
	std::string TempString;

	Load.open(NPC_FILE, ios::in);
	if (!Load.is_open())
	{
		std::cout << "Could not open: " << NPC_FILE << std::endl;
		return;
	}

	while (!Load.eof())
	{
		getline(Load, TempString);
		if (TempString[0] == '[' && TempString != "[END NPC]")
		{
			getline(Load, TempString);
			if (CurrentMapLoaded == TempString)
			{
				Npc = new NPC;

				Npc->Map = TempString;

				getline(Load, TempString);
				Npc->Name = TempString;

				getline(Load, TempString);
				Npc->Script = TempString;

				getline(Load, TempString);
				Npc->MapX = atoi(TempString.c_str());
				
				getline(Load, TempString);
				Npc->MapY = atoi(TempString.c_str());

				Npcs.push_back(*(Npc));
			}
		}
	}

	Load.close();
}
void MAP::FindNpcs()
{
	ClearNpcs();
	LoadNpcs();

	if (Npcs.size() == 0)
	{
		std::cout << "There are no npcs on this map." << std::endl;
		return;
	}

	std::cout << "Found Npcs at:\n";
	for (std::list<NPC>::iterator itr = Npcs.begin();
		itr != Npcs.end(); itr++)
	{
		std::cout << itr->Map << "\t" << itr->Name << "\t" << itr->Script << "\t" 
			<< (int)itr->MapY << ", " << (int)itr->MapX << std::endl;
	}

	std::cout << std::endl;
}
void MAP::ClearNpcs()
{
	Npcs.clear();
}
std::string MAP::GetNpc(int PlayerY, int PlayerX)
{
	for (std::list<NPC>::iterator itr = Npcs.begin();
		itr != Npcs.end(); itr++)
	{
		if (itr->MapY == PlayerY - 1 || itr->MapY == PlayerY + 1 || itr->MapY == PlayerY)
		{
			if (itr->MapX == PlayerX - 1 || itr->MapX == PlayerX + 1 || itr->MapX == PlayerX)
			{
				return itr->Script;
			}
		}
	}

	return "No NPC";
}
void MAP::LoadShops()
{
	ifstream Load;
	std::string TempString;

	Load.open(SHOP_FILE, ios::in);
	if (!Load.is_open())
	{
		std::cout << "Could not open: " << SHOP_FILE << std::endl;
		return;
	}

	while (!Load.eof())
	{
		getline(Load, TempString);
		if (TempString[0] == '[' && TempString != "[END SHOP]")
		{
			getline(Load, TempString);
			if (CurrentMapLoaded == TempString)
			{
				Shop = new SHOP;

				Shop->Map = TempString;

				getline(Load, TempString);
				Shop->Name = TempString;

				getline(Load, TempString);
				Shop->Script = TempString;

				getline(Load, TempString);
				Shop->MapX = atoi(TempString.c_str());

				getline(Load, TempString);
				Shop->MapY = atoi(TempString.c_str());

				Shop->LoadItems();

				Shops.push_back(*(Shop));
			}
		}
	}

	Load.close();
}
void MAP::FindShops()
{
	ClearShops();
	LoadShops();

	if (Shops.size() == 0)
	{
		std::cout << "There are no shops on this map." << std::endl;
		return;
	}

	std::cout << "Found Shops at:\n";
	for (std::list<SHOP>::iterator itr = Shops.begin();
		itr != Shops.end(); itr++)
	{
		std::cout << itr->Map << "\t" << itr->Name << "\t" << itr->Script << "\t" 
			<< (int)itr->MapY << ", " << (int)itr->MapX << std::endl;
	}

	std::cout << std::endl;
}

void MAP::ClearShops()
{
	Shops.clear();
}
std::string MAP::GetShop(int PlayerY, int PlayerX)
{
	for (std::list<SHOP>::iterator itr = Shops.begin();
		itr != Shops.end(); itr++)
	{
		if (itr->MapY == PlayerY - 1 || itr->MapY == PlayerY + 1 || itr->MapY == PlayerY)
		{
			if (itr->MapX == PlayerX - 1 || itr->MapX == PlayerX + 1 || itr->MapX == PlayerX)
			{
				return itr->Script;
			}
		}
	}

	return "No SHOP";
}
SHOP MAP::GetShop(const char* ShopName)
{
	for (std::list<SHOP>::iterator itr = Shops.begin();
		itr != Shops.end(); itr++)
	{
		if (itr->Name == ShopName)
		{
			return (*itr);
		}
	}
}
int MAP::GetPlayerX()
{
	for (int y = 0; y < MapHeight; y++)
	{
		for(int x = 0; x < MapWidth; x++)
		{
			if (*(TheMap + x + (y * MapWidth)) == 2)
			{
				return x;
			}
		}
	}
	return 0;
}
int MAP::GetPlayerY()
{
	for (int y = 0; y < MapHeight; y++)
	{
		for(int x = 0; x < MapWidth; x++)
		{
			if (*(TheMap + x + (y * MapWidth)) == 2)
			{
				return y;
			}
		}
	}
	return 0;
}