#ifndef LIBRARY_H
#define LIBRARY_H

#define _CRTDBG_MAP_ALLOC
/*This is a header file to house all of the include pre-proccessor directives
that includes all of the headers, and stands as a linking file to link all of our
custom made header files together in order for them to access each other.*/

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <list>
#include <stdlib.h>
#include <math.h>
#include <crtdbg.h>

using namespace std;

/* Main classes */
#include "Debug.h"
#include "Functions.h"
#include "LuaFunctions.h"
#include "Lua.h"
#include "LinkedList.h"

/* Parent classes */
#include "Character.h"	//Player, Monster
#include "Item.h"		//Weapon, Armor, Potion, Misc

/* Child classes */
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Quest.h"
#include "Inventory.h"
#include "Magic.h"
#include "Player.h"
#include "Monster.h"
#include "Shop.h"
#include "Map.h"
#include "Screen.h"
#include "Battle.h"

/* Engine (Accesses everything)*/
#include "VanquishEngine.h"

#endif