#include "Globals.h"

int main()
{
	short select;

menu:
	cout << "//MENU\\\n";
	cout << "1. Create File\n";
	cout << "2. Open File\n";
	cout << "3. Close File\n";
	cout << "4. Get Open Files\n";
	cout << "5. Exit\n";

	cout << "Selection: ";
	cin >> select;

	switch(select)
	{
	case 1:
		{
			File.FileCreate(File.FilePathInput());
			cout << endl;

			goto menu;
			break;
		}
	case 2:
		{
			File.FileOpen(File.FilePathInput());
			cout << endl;

			goto menu;
			break;
		}
	case 3:
		{
			File.FileClose();
			cout << endl;

			goto menu;
			break;
		}
	case 4:
		{
			File.GetOpenedFile();
			cout << endl; 
			
			goto menu;
			break;
		}
	case 5:
		{
			goto exit;
			break;
		}
	default:
		{
			cout << "-INVALID SELECTION-\n\n";
			goto menu;
			break;
		}
	}

exit:
	getchar();
	return 0;
}