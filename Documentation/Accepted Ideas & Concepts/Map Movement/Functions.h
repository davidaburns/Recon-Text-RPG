/* Functions.h */

#include "Library.h"

void DrawColorText(char* drawString, int drawColor)
{
     HANDLE hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, drawColor);
     cout << drawString;
}

void DrawColorTextLine(char* drawString, int drawColor)
{
     HANDLE hConsole;
     hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(hConsole, drawColor);
     cout << drawString << endl;
}
