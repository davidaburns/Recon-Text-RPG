
#include <stdlib.h>
#include <windows.h>

#define Map1_XW 10
#define Map1_YW 10
#define MAX_GOLD 25

main()
{
	// Init The Map
	int Map1[10][10] = {
					   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					   {1, 2, 0, 0, 0, 0, 0, 0, 0, 1},
					   {1, 0, 0, 0, 3, 3, 0, 0, 0, 1},
					   {1, 0, 0, 0, 3, 3, 0, 0, 0, 1},
					   {1, 0, 0, 0, 3, 3, 0, 0, 0, 1},
					   {1, 0, 0, 3, 0, 0, 3, 0, 0, 1},
					   {1, 0, 0, 0, 3, 3, 0, 0, 0, 1},
					   {1, 0, 4, 0, 0, 0, 0, 4, 0, 1},
					   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
					   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					   }, x, y, playerMoney = 0,
					   			playerLevel = 1,
								playerX = 1,
								playerY = 1;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	char kbInput;
	
	// Rand()
	srand(time(NULL));
	
	// Draw The Map
	while(1)
	{
		
		// For Skipping
			skipCEvent:
	
	system("CLS");	
	printf("\n");
	
	SetConsoleTextAttribute(hConsole, 10);
	printf(" Money: %d", playerMoney);
	
	SetConsoleTextAttribute(hConsole, 15);
	printf(" * ");
	
	SetConsoleTextAttribute(hConsole, 9);
	printf("Level: %d\n", playerLevel);
				   
	for (x = 0; x < Map1_XW; x++)
	{
		for (y = 0; y < Map1_YW; y++)
		{
			switch (Map1[x][y])
			{
				// 1 - Wall
				// 2 - Player
				// 3 - Gold
				// 4 - Ball (Movable)
				// Default - Empty
				
				case 1:
					SetConsoleTextAttribute(hConsole, 15);
					printf(" # ");
					break;
					
				case 2:
					SetConsoleTextAttribute(hConsole, 9);
					printf(" P ");
					break;
					
				case 3:
					SetConsoleTextAttribute(hConsole, 10);
					printf(" $ ");
					break;
					
				case 4:
					SetConsoleTextAttribute(hConsole, 12);
					printf(" O ");
					break;
				
				default:
					SetConsoleTextAttribute(hConsole, 7);
					printf("   ");
					break;	
			}
		}
		
		printf("\n");
	}
	
	// Keyboard Input (Real Time Movement)
	// W - Up
	// A - Left
	// S - Down
	// D - Right
	
	kbInput = _getch();
	kbInput = toupper(kbInput);
	
	if (kbInput == 'W')
	{
		if (Map1[playerY-1][playerX] != 1)
		{
			if (Map1[playerY-1][playerX] == 3)
				playerMoney += rand() % MAX_GOLD + 1;
				
			if (Map1[playerY-1][playerX] == 4)
			{
				if (Map1[playerY-2][playerX] == 0)
				{
					Map1[playerY-2][playerX] = 4;
				}
				else
					goto skipCEvent;
			}
				
			Map1[playerY][playerX] = 0;
			playerY--;
			Map1[playerY][playerX] = 2;
			
		}
	}
	
	if (kbInput == 'A')
	{
		if (Map1[playerY][playerX-1] != 1)
		{
			if (Map1[playerY][playerX-1] == 3)
				playerMoney += rand() % MAX_GOLD + 1;
				
			if (Map1[playerY][playerX-1] == 4)
			{
				if (Map1[playerY][playerX-2] == 0)
				{
					Map1[playerY][playerX-2] = 4;
				}
				else
					goto skipCEvent;		
			}
			
			Map1[playerY][playerX] = 0;
			playerX--;
			Map1[playerY][playerX] = 2;
			
		}
	}
	
	if (kbInput == 'S')
	{
		if (Map1[playerY+1][playerX] != 1)
		{
			if (Map1[playerY+1][playerX] == 3)
				playerMoney += rand() % MAX_GOLD + 1;
				
			if (Map1[playerY+1][playerX] == 4)
			{
				if (Map1[playerY+2][playerX] == 0)
				{
					Map1[playerY+2][playerX] = 4;
				}
				else
					goto skipCEvent;		
			}
			
			Map1[playerY][playerX] = 0;
			playerY++;
			Map1[playerY][playerX] = 2;
		}
	}
	
	if (kbInput == 'D')
	{
		if (Map1[playerY][playerX+1] != 1)
		{
			if (Map1[playerY][playerX+1] == 3)
				playerMoney += rand() % MAX_GOLD + 1;
				
			if (Map1[playerY][playerX+1] == 4)
			{
				if (Map1[playerY][playerX+2] == 0)
				{
					Map1[playerY][playerX+2] = 4;
				}
				else
					goto skipCEvent;		
			}
				
			Map1[playerY][playerX] = 0;
			playerX++;
			Map1[playerY][playerX] = 2;
		}
	}
	
}
	
	return 0;	
}
