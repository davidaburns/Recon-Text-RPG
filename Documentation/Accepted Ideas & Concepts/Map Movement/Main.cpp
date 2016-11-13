/* Main.cpp */

// Include Libraries
#include "Functions.h"

// Player Class
class player
{
public:
	int x;
	int y;
	int gold;
}player;

// Main Function
int main()
{
	// Initialize The Map
	int map[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 2, 1, 3, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 0, 0, 3, 1, 1, 0, 1},
	{1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 3, 1},
	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 1, 3, 0, 0, 0, 1, 0, 1},
	{1, 3, 1, 3, 0, 0, 0, 0, 3, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	// Player Variables
	player.x = 1;
	player.y = 1;
	player.gold = 0;

	// Other Variables
	char kbInput;

	// Setup Rand Function
	srand(static_cast<unsigned>(time(0)));

	while(true)
	{
	// Draw Title
	cout << endl;
	DrawColorTextLine("\t\t\tShining Kingdoms", 12);
	DrawColorTextLine("\t\tby Jake \"Master Jake\" Chappell", 13);
	DrawColorTextLine("\t\thttp://www.masterjakeonline.com/", 14);
	DrawColorText(" Gold: ", 10);
	cout << player.gold << endl << endl;

	// Draw The Map Characters (Attributes)
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			switch(map[x][y])
			{
			case 1:
				DrawColorText(" # ", 15);
				break;
			case 2:
				DrawColorText(" P ", 9);
				break;
			case 3:
				DrawColorText(" $ ", 10);
				break;
			case 99:
                DrawColorText(" X ", 14);
                break;
			default:
				cout << "   ";
				break;
			}
		}
		cout << endl;
	}
		// Get Keyboard Input
		kbInput = _getch();
		switch(kbInput)
		{
        case 13:
             map[player.x-1][player.y] = 99;
             map[player.x+1][player.y] = 99;
             map[player.x][player.y-1] = 99;
             map[player.x][player.y+1] = 99;
             break;
		case 'w':
			if (map[player.x-1][player.y] != 1)
			{
				if (map[player.x-1][player.y] == 3) { player.gold += rand()%25+1; }
			map[player.x][player.y] = 0;
			player.x -= 1;
			map[player.x][player.y] = 2;
			}
			break;
		case 'a':
			if (map[player.x][player.y-1] != 1)
			{
				if (map[player.x][player.y-1] == 3) { player.gold += rand()%25+1; }
			map[player.x][player.y] = 0;
			player.y -= 1;
			map[player.x][player.y] = 2;
			}
			break;
		case 'd':
			if (map[player.x][player.y+1] != 1)
			{
				if (map[player.x][player.y+1] == 3) { player.gold += rand()%25+1; }
			map[player.x][player.y] = 0;
			player.y += 1;
			map[player.x][player.y] = 2;
			}
			break;
		case 's':
			if (map[player.x+1][player.y] != 1)
			{
				if (map[player.x+1][player.y] == 3) { player.gold += rand()%25+1; }
			map[player.x][player.y] = 0;
			player.x += 1;
			map[player.x][player.y] = 2;
			}
			break;
		default:
			break;
		}
		system("CLS");
	}

	// Final Figures
	return 0;
}
