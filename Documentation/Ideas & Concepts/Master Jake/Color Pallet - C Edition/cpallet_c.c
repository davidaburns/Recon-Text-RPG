/* Umm... Hi! C version of color pallet! */

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void PrintColor(int, HANDLE*);

main()
{
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		int iColorNumber;
		int x;
		
		printf("How many colors would you like to display? ");
		scanf("%d", &iColorNumber);
		
		for (x = 1; x <= iColorNumber; x++)
		{
			PrintColor(x, &hConsole);	
		}
		
		SetConsoleTextAttribute(hConsole, 7);
		
		system("PAUSE");
		return 0;
}

void PrintColor(int colorIndex, HANDLE* colorConsole)
{
		SetConsoleTextAttribute(*colorConsole, colorIndex);
		printf("This color is index #%d\n", colorIndex);
}
