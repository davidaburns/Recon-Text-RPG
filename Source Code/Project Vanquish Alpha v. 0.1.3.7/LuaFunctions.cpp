#include "Library.h"

//Lua Script Functions
//---Game Functions---
int DialogText(lua_State* LuaState)
{
	int ArgumentIndex = lua_gettop(LuaState);
	std::string StringArgument;

	if (ArgumentIndex > 1)
	{
		std::cout << "Too many arguments in Lua Function 'DialogText()'" << std::endl;
		return 0;
	}

	StringArgument = lua_tostring(LuaState, 1);
	Engine->Screen.DrawDialogText(StringArgument, 7);

	return 0;
}

int DisplayMenu(lua_State* LuaState)
{
	int ArgumentIndex = lua_gettop(LuaState);

	std::string MenuItem;
	std::list<std::string> MenuItems;

	//Go through all of the arguments in the function
	for (int itr = 1; itr <= ArgumentIndex; itr++)
	{
		if (lua_isstring(LuaState, itr))	//if the argument is a string
		{
			MenuItem = lua_tostring(LuaState, itr);
			MenuItems.push_back(MenuItem);

			MenuCounter = itr;
		}
		else
		{
			//if the argument is not a string
			std::cout << "'DisplayMenu()' Argument " << itr << ", is of the wrong type." << std::endl;
			return 0;
		}
	}

	for (std::list<std::string>::iterator itr = MenuItems.begin();
		itr != MenuItems.end(); itr++)
	{
		std::cout << "\t. " << *itr << std::endl;
	}

	return 0;
}

int MenuSelect(lua_State* LuaState)
{
	int ArgumentIndex = lua_gettop(LuaState);

	int CursorReferenceY = Engine->Screen.GetCursorY()- MenuCounter;

	int CursorY = CursorReferenceY;
	int CursorX = 8;
	int CursorPosition = 0;

	char KeyInput = 'z';

	MenuCounter -= 1;

	while ((int)KeyInput != 13)
	{
		Engine->Screen.SetCursorPosition(CursorX, CursorY);
		std::cout << ">";

		if (_kbhit() != 0)
		{
			KeyInput = _getch();
			switch((int)KeyInput)
			{
			case 27:
				{
					return 0;
				}
			case 72:
				{
					Engine->Screen.SetCursorPosition(CursorX, CursorY);
					std::cout << ".";

					if (CursorY <= CursorReferenceY)
					{
						CursorPosition = 1;
						CursorY = CursorReferenceY;
						break;
					}

					CursorPosition -= 1;
					CursorY -= 1;

					break;
				}
			case 80:
				{
					Engine->Screen.SetCursorPosition(CursorX, CursorY);
					std::cout << ".";

					if (CursorPosition >= MenuCounter)
					{
						CursorPosition = MenuCounter;
						CursorY = CursorReferenceY + MenuCounter;
						break;
					}

					CursorPosition += 1;
					CursorY += 1;

					break;
				}
			}
		}
	}

	MenuCounter = 0;
	lua_pushnumber(LuaState, (int)CursorPosition);

	Engine->Screen.ClearDialog();

	return 1;
}

int ListShopItems(lua_State* LuaState)
{
	int ArgumentIndex = lua_gettop(LuaState);
	if (ArgumentIndex > 1)
	{
		std::cout << "Too many arguments in the function 'ListShopItems()'" << std::endl;
		return 0;
	}

	Engine->Screen.ClearDialog();

	char* S = (char*) lua_tostring(LuaState, 1);
	if(S == NULL)
	{
		std::cout << "Error! The shop's name was not specified." << std::endl;
		return 0;
	}

	std::cout << "Name / Cost / Description" << std::endl;

	SHOP TempShop = Engine->Map.GetShop(S);
	for (std::list<ITEM>::iterator itr = TempShop.Items.begin();
		itr != TempShop.Items.end(); itr++)
	{
		std::cout << itr->Name << " / " << itr->BuyAmount << " / " << itr->Description << std::endl;
	}

	return 0;
}

int AddItemInventory(lua_State* LuaState)
{
	int ArgumentIndex = lua_gettop(LuaState);
	if (ArgumentIndex > 1)
	{
		std::cout << "Too many arguemnts in the function 'AddItemInventory()'" << std::endl;
		return 0;
	}

	ITEM* Item = new ITEM;
	ITEM* Weapon = new WEAPON;
	ITEM* Armor = new ARMOR;
	ITEM* Potion = new POTION;

	if(Item->Load(lua_tostring(LuaState, 1)))
	{
		Engine->Player.Inventory->AddItem(Item, 1);
	}
	else if(Weapon->Load(lua_tostring(LuaState, 1)))
	{
		Engine->Player.Inventory->AddItem(Weapon, 1);
	}
	else if(Armor->Load(lua_tostring(LuaState, 1)))
	{
		Engine->Player.Inventory->AddItem(Armor, 1);
	}
	else if(Potion->Load(lua_tostring(LuaState, 1)))
	{
		Engine->Player.Inventory->AddItem(Potion, 1);
	}
	return 0;
}

int PlayerName(lua_State* LuaState)
{
	Engine->Screen.DrawDialogText(Engine->Player.Name, 7);
	return 0;
}

int AddQuest(lua_State* LuaState)	//Passes in a quest's ID
{
	std::string QuestId = lua_tostring(LuaState, 1);

	if(!Engine->Quest.LoadQuest(QuestId))
	{
		std::cout << "Quest ID does not exist!" << std::endl;
	}
	Engine->Player.Quests.Insert(Engine->Quest);
	return 0;
}

int Fight(lua_State* LuaState)
{
	Engine->Monster->Load(lua_tostring(LuaState, 1));
	//Battle(Engine->Monster);
	return 0;
}

//---Engine Functions---
int Print(lua_State* LuaState)
{
	int ArgumentIndex = lua_gettop(LuaState);
	if (ArgumentIndex > 1)
	{
		std::cout << "Too many arguments in the function 'Print()'" << std::endl;
		return 0;
	}

	std::cout << lua_tostring(LuaState, 1);

	return 0;
}

int ClearScreen(lua_State* LuaState)
{
	int ArgumentIndex = lua_gettop(LuaState);
	if (ArgumentIndex > 0)
	{
		std::cout << "'ClearScreen()' does not take any arguments\n";
		return 0;
	}

	Engine->Screen.ClearScreen();
	return 0;
}

int ClearDialog(lua_State* LuaState)
{
	int ArgumentIndex = lua_gettop(LuaState);
	if (ArgumentIndex > 0)
	{
		std::cout << "'ClearDialog' does not take any arguments\n";
		return 0;
	}

	Engine->Screen.ClearDialog();
	return 0;
}

int SetScreenCursorPosition(lua_State* LuaState)
{
	int ArgumentIndex = lua_gettop(LuaState);
	int XPosition, YPosition;

	if (ArgumentIndex > 2)
	{
		std::cout << "Too many arguments in Lua function 'SetScreenCursorPosition'" << std::endl;
		return 0;
	}

	for (int itr = 1; itr < 2; itr++)
	{
		if (!lua_isnumber(LuaState, itr))
		{
			std::cout << "'SetScreenCursorPosition()' \nArgument " 
				<< itr << ", is not an integer please check your script." << std::endl;

			return 0;
		}
	}

	YPosition = lua_tointeger(LuaState, 1);
	XPosition = lua_tointeger(LuaState, 2);

	//Debug Text, please remove before releasing the game
	std::cout << "Setting screen cursor too: " << YPosition << ", " << XPosition << std::endl;
	Engine->Screen.SetCursorPosition(XPosition, YPosition);

	return 0;
}

int GetScreenCursorX(lua_State* LuaState)
{
	int CursorX = Engine->Screen.GetCursorX();
	lua_pushnumber(LuaState, CursorX);

	return 1;
}

int GetScreenCursorY(lua_State* LuaState)
{
	int CursorY = Engine->Screen.GetCursorY();
	lua_pushnumber(LuaState, CursorY);

	return 1;
}