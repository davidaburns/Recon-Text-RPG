#include "Library.h"

_LUA::_LUA()
{
}
_LUA::~_LUA()
{
}
bool _LUA::OpenLua()
{
	LuaState = lua_open();
	luaL_openlibs(LuaState);

	return true;
}
void _LUA::CloseLua()
{
	lua_close(LuaState);
}

void _LUA::RegisterLuaFunctions()
{
	//Registers all of the Lua functions that will be available to Lua scripts
	
	//Game Functions
	lua_register(LuaState, "DialogText", DialogText);
	lua_register(LuaState, "DisplayMenu", DisplayMenu);
	lua_register(LuaState, "MenuSelect", MenuSelect);
	lua_register(LuaState, "ListShopItems", ListShopItems);
	lua_register(LuaState, "AddItemInventory", AddItemInventory);
	lua_register(LuaState, "PlayerName", PlayerName);
	lua_register(LuaState, "AddQuest", AddQuest);
	lua_register(LuaState, "Fight", Fight);

	//Engine Functions
	lua_register(LuaState, "Print", Print);
	lua_register(LuaState, "ClearScreen", ClearScreen);
	lua_register(LuaState, "ClearDialog", ClearDialog);
	lua_register(LuaState, "SetScreenCursorPosition", SetScreenCursorPosition);
	lua_register(LuaState, "GetScreenCursorX", GetScreenCursorX);
	lua_register(LuaState, "GetScreenCursorY", GetScreenCursorY);
}
void _LUA::RunLuaScript(std::string ScriptType, std::string ScriptName)
{
	std::string Script;

	if(ScriptType == LUA_DEFAULT){
		Script = LUA_DEFAULT_SCRIPT_PATH + ScriptName;
	}
	else if(ScriptType == LUA_NPC){
		Script = LUA_NPC_SCRIPT_PATH + ScriptName;
	}
	else if(ScriptType == LUA_SHOP){
		Script = LUA_SHOP_SCRIPT_PATH + ScriptName;
	}

	std::cout << "Running Lua Script: " << Script << std::endl;
	if(luaL_dofile(LuaState, Script.c_str()) == 1)
	{
		Engine->Screen.ClearDialog();
		std::cout << "Lua Script: " << Script.c_str() << ", does not exist\n";
	}
}