#ifndef SCREEN_H
#define SCREEN_H

#include "Library.h"

//Text Colors
#define TEXT_COLOR_DEFAULT 7

//Menu Types
#define NPC_SELECTION 1
#define NPC_SHOP 2
#define PLAYER_INVENTORY 3
#define PLAYER_MAGIC 4

//--------------------------------------------------------

class MENU
{
private:
	bool Active;			//Is the menu active?
	int MenuSelection;		//Which menu item is selected
	int CursorY;

protected:
	MENU();
	~MENU();

public:

	int Menu(int MenuType, std::string ...);

	void OutputSelectionMenu();
	void OutputShopMenu();
	void OutputInventoryMenu();
	void OutputMagicMenu();
};

//--------------------------------------------------------

class SCREEN
{
private:
	int CursorX;
	int CursorY;

	HANDLE hConsole;
	CONSOLE_SCREEN_BUFFER_INFO CBufferInfo;
	CONSOLE_CURSOR_INFO CCursorInfo;

	COORD ConsoleHome;
	COORD DialogStart;

protected:
	
public:
	SCREEN();
	~SCREEN();

	void SetCursorPosition(int XPos, int YPos);
	void SetCursorInvisible();

	void SetTextColor(int ColorId);

	int GetCursorX();
	int GetCursorY();

	void ClearScreen(); //Clears the whole screen
	void ClearDialog(); //Clears only the dialog

	//Instance Text
	void DrawColorText(char* DrawText, int DrawColor = 7);

	//Game Style Functions (text style)
	void DrawDialogText(std::string Text, int Color = 7);
};

#endif