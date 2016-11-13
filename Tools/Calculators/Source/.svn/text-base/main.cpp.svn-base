#include "BattleTextCalcs.h"

int main()
{
	int choice;

	cout << " XXXXXX    XXXXXX  DDDDDDDDDD  EEEEEEEEEE FFFFFFFFFF" << endl;
	cout << "  XXXXXX  XXXXXX   DDDD  DDDDD EEEE       FFFF	  " << endl;
	cout << "   XXXXXXXXXXXX    DDDD  DDDDDDEEEEEEE    FFFFFFFFF " << endl;
	cout << "  XXXXXX  XXXXXX   DDDD  DDDDD EEEE       FFFF	  " << endl;
	cout << " XXXXXX    XXXXXX  DDDDDDDDDD  EEEEEEEEEE FFFF	  " << endl << endl;

	cout << "BattleText Calculators Rev 0.5 9/27/08" << endl;
	cout << "Created & Tested, David Burns" << endl;
	cout << "Copyright(c). X-Def Productions 2007 - 2008" << endl << endl << endl;

choose:
	system("TITLE BattleText Calculators Rev 0.8 10/2/08");

	cout << "//MENU\\\\" << endl;
	cout << "1.Physical Atks" << endl;
	cout << "2.Magic Atks" << endl;
	cout << "3.Leveling Experience (NOT IMPLEMENTED)" << endl;
	cout << "4.Exit" << endl;

	cin >> choice;

	switch (choice)
	{
	case 1:
		{
			PhysAtk pAtk;
			pAtk.physCalcInit();

			goto choose;
			break;
		}
	case 2:
		{
			MgcAtk mAtk;
			mAtk.mgcCalcInit();

			goto choose;
			break;
		}
	case 3:
		{
			cout << "-NOT IMPLEMENTED-" << endl;
			
			Sleep(600);

			goto choose;
			break;
		}
	case 4:
		{
			cout << "Thank you, for using BattleText Calculators...." << endl;
			cout << "Now Exiting..." << endl;
			
			Sleep(600);

			return 0;
			break;
		}
	default:
		{
			cout << "-INVALID SELECTION-" << endl;
			
			Sleep(600);

			goto choose;
		}
	}

	cin.ignore();
	getchar();
	return 0;
}