#ifndef LUAFUNCTIONS_H
#define LUAFUNCTIONS_H

#include "Library.h"

#pragma comment(lib, "lua5.1.lib")

extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

//C++ Functions used in Lua Scripts

//Lua Variables
static int MenuCounter = 0;		//used to keep track of how many menus there are, used by DisplayMenu() & MenuSelect()

//Engine Functions
int DialogText(lua_State* LuaState);
int DisplayMenu(lua_State* LuaState);
int MenuSelect(lua_State* LuaState);
int ListShopItems(lua_State* LuaState);
int AddItemInventory(lua_State* LuaState);
int PlayerName(lua_State* LuaState);
int AddQuest(lua_State* LuaState);
int Fight(lua_State* LuaState);

//Console Functions
int Print(lua_State* LuaState);
int ClearScreen(lua_State* LuaState);
int ClearDialog(lua_State* LuaState);
int SetScreenCursorPosition(lua_State* LuaState);
int GetScreenCursorX(lua_State* LuaState);
int GetScreenCursorY(lua_State* LuaState);

#endif