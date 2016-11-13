/* Main.cpp */

/*
Program: PasswordBulletDisplay
Programmer: Jake "Master Jake" Chappell
Website: http://www.masterjakeonline.com/
E-Mail: skateparkceasercash@yahoo.com
Rights: Private & Team Use Only

Overview: I originally built this using
a char array, but the characters would sometimes
screw up severly on display. Now it's all strings =]
*/

// Include Libraries
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// Main Function
int main(void)
{
	// Declare Variables
	string userPassword;
	string userProtected;
	char kbInput;
	
	// Loop For Length Detection (Length Cap: 32 Characters)
	for(int i = 0; i < 32; i++)
	{
		// Display
		cout << endl << "* Please Input Your Password And Press Enter *" << endl;
		cout << "\t\tValid Characters: a-z; A-Z" << endl << endl;
		cout << "> Password: " << userProtected;
		
		// Get User Input
		kbInput = _getch();
		
		// Test Input
		if (kbInput != 13)
		{
			// Allow Only Characters a-z and A-Z
			if ((kbInput >= 65 && kbInput <= 90) || (kbInput >= 97 && kbInput <= 122))
			{
				userPassword += kbInput;
				userProtected += '*';
			}
		} else {
			break;	
		}
		
		system("CLS");
	}
	
	system("CLS");
	cout << endl << "* SUCCESS! Your Password Is: " << userPassword << endl;
	system("PAUSE");
	return 0;
}
