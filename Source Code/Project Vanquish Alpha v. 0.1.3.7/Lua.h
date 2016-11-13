#ifndef LUA_H
#define LUA_H

#include "Library.h"
#include "LuaFunctions.h"

#pragma comment(lib, "lua5.1.lib")

extern "C"
{
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

//Lua Script Paths
#define LUA_DEFAULT_SCRIPT_PATH "Data//Scripts//"
#define LUA_NPC_SCRIPT_PATH "Data//Scripts//NPC//"
#define LUA_SHOP_SCRIPT_PATH "Data//Scripts//SHOP//"

//Lua Scipt Types
#define LUA_DEFAULT "DEFAULT"
#define LUA_NPC "NPC"
#define LUA_SHOP "SHOP"

class _LUA
{
private:
public:

	_LUA();
	~_LUA();

	lua_State* LuaState;

	bool OpenLua();
	void CloseLua();

	void RegisterLuaFunctions();
	void RunLuaScript(std::string ScriptType, std::string ScriptName);
};

#endif