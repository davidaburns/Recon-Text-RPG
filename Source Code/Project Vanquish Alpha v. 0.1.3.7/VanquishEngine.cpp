#include "Library.h"

VanquishEngine _Engine;
VanquishEngine* Engine;

VanquishEngine::VanquishEngine()
{
	Engine = &_Engine;
	
	IsRunning = true;
	IsDrawing = true;

}
VanquishEngine::~VanquishEngine()
{
}
void VanquishEngine::TurnOffEngine()
{
	IsRunning = false;
}
void VanquishEngine::TurnOffDrawing()
{
	IsDrawing = false;
}
void VanquishEngine::TurnOnDrawing()
{
	IsDrawing = true;
}
void VanquishEngine::TranslateInput(int KeyInput)
{
	switch(KeyInput)
	{
	case 27:			//ESC
		{
			Screen.ClearDialog();
			IsRunning = false;
			Engine->CleanUp();

			break;
		}
	case 119:			//W
		{
			//Move Up
			if (IsDrawing)
			{
				if(*(Engine->Map.TheMap + Engine->Player.X + ((Engine->Player.Y - 1) * Engine->Map.MapWidth)) == 0)
				{
					*(Engine->Map.TheMap + Engine->Player.X + (Engine->Player.Y * Engine->Map.MapWidth)) = 0;
					Engine->Player.AddY(-1);
					*(Engine->Map.TheMap + Engine->Player.X + (Engine->Player.Y * Engine->Map.MapWidth)) = 2;

					if(rand()%101 < 4)
					{
						Monster = new MONSTER();
						Monster->Load(Engine->Player.CurrentMap);

						Engine->Screen.SetCursorPosition(0, 11);
						std::cout << "The battle function would be called here." << std::endl;
					}
				}
				else if(*(Engine->Map.TheMap + Engine->Player.X + ((Engine->Player.Y - 1) * Engine->Map.MapWidth)) == 4)
				{
					Engine->Screen.ClearDialog();
					Engine->Map.WarpPlayer(Engine->Player.X, (Engine->Player.Y)-1);
				}
			}
			break;
		}
	case 115:			//S
		{
			//Move Down
			if (IsDrawing)
			{
				if(*(Engine->Map.TheMap + Engine->Player.X + ((Engine->Player.Y) + 1) * (Engine->Map.MapWidth)) == 0)
				{
					*(Engine->Map.TheMap + Engine->Player.X + (Engine->Player.Y * Engine->Map.MapWidth)) = 0;
					Engine->Player.AddY(1);
					*(Engine->Map.TheMap + Engine->Player.X + (Engine->Player.Y * Engine->Map.MapWidth)) = 2;

					if(rand()%101 < 4)
					{
						Monster = new MONSTER();
						Monster->Load(Engine->Player.CurrentMap);
						
						Engine->Screen.SetCursorPosition(0, 11);
						std::cout << "The battle function would be called here." << std::endl;
					}
				}
				else if(*(Engine->Map.TheMap + Engine->Player.X + ((Engine->Player.Y + 1) * Engine->Map.MapWidth)) == 4)
				{
					Engine->Screen.ClearDialog();
					Engine->Map.WarpPlayer(Engine->Player.X, (Engine->Player.Y)+1);
				}
			}
			break;
		}
	case 97:			//A
		{
			//Move Left
			if (IsDrawing)
			{
				if(*(Engine->Map.TheMap + (Engine->Player.X - 1) + (Engine->Player.Y * Engine->Map.MapWidth)) == 0)
				{
					*(Engine->Map.TheMap + Engine->Player.X + (Engine->Player.Y * Engine->Map.MapWidth)) = 0;
					Engine->Player.AddX(-1);
					*(Engine->Map.TheMap + Engine->Player.X + (Engine->Player.Y * Engine->Map.MapWidth)) = 2;

					if(rand()%101 < 4)
					{
						Monster = new MONSTER();
						Monster->Load(Engine->Player.CurrentMap);
						
						Engine->Screen.SetCursorPosition(0, 11);
						std::cout << "The battle function would be called here." << std::endl;
					}
				}
				else if(*(Engine->Map.TheMap + (Engine->Player.X - 1) + (Engine->Player.Y * Engine->Map.MapWidth)) == 4)
				{
					Engine->Screen.ClearDialog();
					Engine->Map.WarpPlayer(Engine->Player.X-1, Engine->Player.Y);
				}
			}
			break;
		}
	case 100:			//D
		{
			//Move Right
			if (IsDrawing)
			{
				if(*(Engine->Map.TheMap + (Engine->Player.X + 1) + (Engine->Player.Y * Engine->Map.MapWidth)) == 0)
				{
					*(Engine->Map.TheMap + Engine->Player.X + (Engine->Player.Y * Engine->Map.MapWidth)) = 0;
					Engine->Player.AddX(1);
					*(Engine->Map.TheMap + Engine->Player.X + (Engine->Player.Y * Engine->Map.MapWidth)) = 2;

					if(rand()%101 < 4)
					{
						Monster = new MONSTER();
						Monster->Load(Engine->Player.CurrentMap);
						
						Engine->Screen.SetCursorPosition(0, 11);
						std::cout << "The battle function would be called here." << std::endl;
					}
				}
				else if(*(Engine->Map.TheMap + (Engine->Player.X + 1) + (Engine->Player.Y * Engine->Map.MapWidth)) == 4)
				{
					Engine->Screen.ClearDialog();
					Engine->Map.WarpPlayer(Engine->Player.X+1, Engine->Player.Y);
				}
			}
			break;
		}
	case 105:			//I
		{
			//Prints The Players Current Inventory, Might Be Temporary (Include A Menu System)
			Engine->Screen.ClearDialog();
			Engine->Player.Inventory->ListInventory();
			break;
		}
	case 113:			//Q
		{
			Engine->Screen.ClearDialog();
			Engine->Player.Quests.Display();
			break;
		}
	case 109:			//M
		{
			//Prints The Players Current Magic Abilities, Might Be Temporary (Include A Menu System)
			Engine->Screen.ClearDialog();
			Engine->Player.Magic->ListMagic();
			break;
		}
	case 112:			//P
		{
			//Prints The Players Current Position
			Engine->Screen.ClearDialog();
			Engine->Screen.SetCursorPosition(0, 11);

			std::cout << "Player is At: " << Engine->Player.X << ", " << Engine->Player.Y << std::endl;

			break;
		}
	case 103:			//G
		{
			//Gets The Current Game States And Prints Them To The Screen
			Engine->Screen.ClearDialog();
			std::cout << "Gamestates" << std::endl;
			std::cout << "Running: " << IsRunning << std::endl;
			std::cout << "Drawing: " << IsDrawing << std::endl << std::endl;

			std::cout << "Map width: " << Engine->Map.MapWidth << std::endl;
			std::cout << "Map height: " << Engine->Map.MapHeight << std::endl;

			break;
		}
	case 102:			//F
		{
			// Finds all the warps/NPCs/shops on the current map
			Engine->Screen.ClearDialog();

			Engine->Map.FindWarps();
			Engine->Map.FindNpcs();
			Engine->Map.FindShops();

			break;
		}
	case 99:			//C
		{
			//Clears The Dialog Portion Of The Screen
			Engine->Screen.ClearDialog();
			break;
		}
	case 114:			//R
		{
			Engine->Screen.ClearDialog();

			std::string UserInput;
			
			std::cout << "Script> ";
			getline(cin, UserInput);

			Engine->Lua.RunLuaScript(LUA_DEFAULT, UserInput + ".lua");

			break;
		}
	case 45:			//-
		{
			//Turn Drawing Off
			Engine->Screen.ClearDialog();
			TurnOffDrawing();

			Engine->Screen.SetCursorPosition(0, 11);

			std::cout << "Drawing Turned Off." << std::endl;
			break;
		}
	case 61:			//+
		{
			//Turn Drawing On
			Engine->Screen.ClearDialog();
			TurnOnDrawing();

			Engine->Screen.SetCursorPosition(0, 11);

			std::cout << "Drawing Turned On." << std::endl;
			break;
		}
	case 32:			//SPACE
		{
			//The Action Key Used For Multiple Actions Throught Out The Game
			Engine->Screen.ClearDialog();
			Engine->Screen.SetCursorPosition(0, 11);

			//Is There an npc next to the player?
			if (*(Engine->Map.TheMap + Engine->Player.X + ((Engine->Player.Y - 1) * Engine->Map.MapWidth)) == 3 || 
			*(Engine->Map.TheMap + (Engine->Player.X + 1) + (Engine->Player.Y * Engine->Map.MapWidth)) == 3 ||
			*(Engine->Map.TheMap + Engine->Player.X + ((Engine->Player.Y + 1) * Engine->Map.MapWidth)) == 3 ||
			*(Engine->Map.TheMap + (Engine->Player.X - 1) + (Engine->Player.Y * Engine->Map.MapWidth)) == 3)
			{
				std::string TempScript = Engine->Map.GetNpc(Engine->Player.Y, Engine->Player.X);
				if (TempScript != "No NPC")
				{
					Engine->Lua.RunLuaScript(LUA_NPC, TempScript);
				}
				else
				{
					Engine->Screen.DrawColorText("That npc was not found in: Maps//Npcs.txt\n", 7);
				}
			}
			else if (*(Engine->Map.TheMap + Engine->Player.X + ((Engine->Player.Y - 1) * Engine->Map.MapWidth)) == 5 || 
			*(Engine->Map.TheMap + (Engine->Player.X + 1) + (Engine->Player.Y * Engine->Map.MapWidth)) == 5 ||
			*(Engine->Map.TheMap + Engine->Player.X + ((Engine->Player.Y + 1) * Engine->Map.MapWidth)) == 5 ||
			*(Engine->Map.TheMap + (Engine->Player.X - 1) + (Engine->Player.Y * Engine->Map.MapWidth)) == 5)
			{
				std::string TempScript = Engine->Map.GetShop(Engine->Player.Y, Engine->Player.X);
				if (TempScript != "No SHOP")
				{
					Engine->Lua.RunLuaScript(LUA_SHOP, TempScript);
				}
				else
				{
					Engine->Screen.DrawColorText("That shop was not found in: Maps//Shops.txt\n", 7);
				}
			}
			else
			{
				Engine->Screen.DrawDialogText("There is nobody to talk to.", 7);
			}

			break;
		}
	case 108:			//L
		{
			//This is the map loader, not to be included in final game.
			TurnOffDrawing();

			Engine->Screen.ClearScreen();
		
			Engine->Map.LoadMapNames();
			Engine->Map.SelectMap();

			Engine->Screen.ClearScreen();

			TurnOnDrawing();

			break;
		}
	default:
		Engine->Screen.ClearDialog();
		std::cout << "Key not recognized." << std::endl;
	}
}
void VanquishEngine::Initiate(std::string GameTitle, std::string MapName)
{
	//Open the debug file.
	if(!Engine->Debug.OpenDebugFile())
	{
		std::cout << "Failed to open debug file." << std::endl;
		
		Sleep(500);
		IsRunning = false;
		return;
	}

	Engine->Debug.DebugWrite("Engine Debug File Opened.");
	Engine->Debug.DebugWrite("\nEngine Initation Started...");

	//Set console title
	SetConsoleTitle(StrToCharPtr(GameTitle));
	Engine->Debug.DebugWrite("\t~Title set to: " + GameTitle);

	//Set cursor to invisible (No Underscore)
	Engine->Screen.SetCursorInvisible();
	Engine->Debug.DebugWrite("\t~Cursor set to: Invisible");

	//Load the default map
	Engine->Debug.DebugWrite("\t~Loading Default Map: " + MapName + "...");
	if (Engine->Map.LoadMap(MapName) == false)
	{
		std::cout << "Initiation Failed!" << std::endl;
		Engine->Debug.DebugWrite("Engine Intiation Failed!");

		Sleep(500);
		IsRunning = false;
		return;
	}

	Engine->Debug.DebugWrite("\t~" + MapName + " Loaded Successfully!");
	Engine->Debug.DebugWrite("Engine Initiation Finished");


	IsRunning = true;
	//Initiate Lua
	Engine->Debug.DebugWrite("\nLua Initiation Started...");
	Engine->Debug.DebugWrite("\t~Opening Lua");
	Engine->Lua.OpenLua();

	Engine->Debug.DebugWrite("\t~Registering Lua Functions");
	Engine->Lua.RegisterLuaFunctions();

	Engine->Debug.DebugWrite("Lua Initiation Finished!");
}
void VanquishEngine::ProccessInput()
{
	if (_kbhit() != 0)
	{
		Engine->Screen.ClearDialog();
		KeyInput = _getch();
		TranslateInput(int(KeyInput));
	}
}
void VanquishEngine::Update()
{
	Engine->Player.X = Engine->Map.GetPlayerX();
	Engine->Player.Y = Engine->Map.GetPlayerY();
}
void VanquishEngine::Draw()
{
	Engine->Screen.SetCursorPosition(0, 0);
	if (IsDrawing == true)
	{
		Engine->Map.DisplayMap();
	}
}
void VanquishEngine::CleanUp()
{
	std::cout << "\nEntered CleanUp()..." << std::endl;
	Engine->Debug.DebugWrite("\nEngine Entered CleanUp()");
	
	Engine->Map.ClearWarps();
	Engine->Map.ClearMapsList();

	delete Engine->Map.TheMap;
	delete Engine->Monster;
	delete Engine->Player.Inventory;
	delete Engine->Player.Magic;

	std::cout.flush();

	Engine->Debug.DebugWrite("Engine Finished CleanUp()");
	Engine->Debug.DebugWrite("\nClosing Engine Debug File...");

	Engine->Debug.CloseDebugFile();
	std::cout << "\nVanquish has been cleaned!" << std::endl;
}
bool VanquishEngine::GetIsRunning()
{
	return IsRunning;
}
bool VanquishEngine::GetIsDrawing()
{
	return IsDrawing;
}