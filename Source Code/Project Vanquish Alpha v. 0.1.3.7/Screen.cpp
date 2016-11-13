#include "Library.h"

SCREEN::SCREEN()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsole, &CBufferInfo);
	GetConsoleCursorInfo(hConsole, &CCursorInfo);

	CursorX = 0;
	CursorY = 0;

	ConsoleHome.X = 0, ConsoleHome.Y = 0;
	DialogStart.X = 0, DialogStart.Y = 11;
}
SCREEN::~SCREEN()
{
}
void SCREEN::SetCursorPosition(int XPos, int YPos)
{
	CursorX = XPos;
	CursorY = YPos;

	COORD CursorPosition = {CursorX, CursorY};

	SetConsoleCursorPosition(hConsole, CursorPosition);
}
void SCREEN::SetCursorInvisible()
{
	CCursorInfo.bVisible = false;
	SetConsoleCursorInfo(hConsole, &CCursorInfo);
}
void SCREEN::SetTextColor(int ColorId)
{
	SetConsoleTextAttribute(hConsole, ColorId);
}
int SCREEN::GetCursorX()
{
	GetConsoleScreenBufferInfo(hConsole, &CBufferInfo);
	int CursorX = CBufferInfo.dwCursorPosition.X;

	return CursorX;
}
int SCREEN::GetCursorY()
{
	GetConsoleScreenBufferInfo(hConsole, &CBufferInfo);
	int CursorY = CBufferInfo.dwCursorPosition.Y;

	return CursorY;
}
void SCREEN::ClearScreen()
{
	DWORD ScreenSize;
	DWORD ScreenCharsSpaces;

	ScreenSize = CBufferInfo.dwSize.X * CBufferInfo.dwSize.Y;

	FillConsoleOutputCharacter(hConsole, (TCHAR)' ', 
		ScreenSize, ConsoleHome, &ScreenCharsSpaces);

	GetConsoleScreenBufferInfo(hConsole, &CBufferInfo);

	FillConsoleOutputAttribute(hConsole, CBufferInfo.wAttributes, 
		ScreenSize, ConsoleHome, &ScreenCharsSpaces);

	SetConsoleCursorPosition(hConsole, ConsoleHome);
}
void SCREEN::ClearDialog()
{
	DWORD DialogSize;
	DWORD DialogCharsSpaces;

	DialogSize = CBufferInfo.dwSize.X * CBufferInfo.dwSize.Y;

	FillConsoleOutputCharacter(hConsole, (TCHAR)' ', 
		DialogSize, DialogStart, &DialogCharsSpaces);

	GetConsoleScreenBufferInfo(hConsole, &CBufferInfo);

	FillConsoleOutputAttribute(hConsole, CBufferInfo.wAttributes, 
		DialogSize, DialogStart, &DialogCharsSpaces);

	SetConsoleCursorPosition(hConsole, DialogStart);
}
void SCREEN::DrawColorText(char* DrawText, int DrawColor)
{
	SetConsoleTextAttribute(hConsole, DrawColor);
	cout << DrawText;
	SetConsoleTextAttribute(hConsole, 7);
}
void SCREEN::DrawDialogText(std::string Text, int Color)
{
	int TextLength = Text.length();
	char ColorId;


	if (Color == NULL)
		SetTextColor(7);
	else
		SetTextColor(Color);

	for (int itr = 0; itr < TextLength; itr++)
	{
		if (Text[itr] == '/' && Text[itr + 1] == '#')
		{
			itr = itr + 2;
			
			ColorId = Text[itr];
			if ((int)ColorId >= 48 && (int)ColorId <= 57)
			{
				switch((int)ColorId)
				{
				case 48:
					{
						itr++;
						SetTextColor(1);
						break;
					}
				case 49:
					{
						itr++;
						SetTextColor(2);
						break;
					}
				case 50:
					{
						itr++;
						SetTextColor(3);
						break;
					}
				default:
					{
						itr++;
						SetTextColor(7);
					}
				}
			}

			while (Text[itr] != '$')
			{
				std::cout << Text[itr];
				Sleep(50);
				itr++;

				if (Text[itr] == '$')
				{
					itr++;
					break;
				}
			}

			if (Color == NULL)
				SetTextColor(7);
			else
				SetTextColor(Color);
		}

		std::cout << Text[itr];
		Sleep(50);
	}
}