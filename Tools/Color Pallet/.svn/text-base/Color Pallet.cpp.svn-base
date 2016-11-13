#include <iostream>
#include <windows.h>
using namespace std;

void SetColor(int i)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, i);	
}

int main(void)
{
	int howMany;
	cout << "How many colors would you like to display? ";
	cin >> howMany;
	system("CLS");
	for(int x = 0; x < howMany; x++)
	{
		SetColor(x);
		cout << "This Color Is Index: " << x << endl;	
	}
	SetColor(7);
	system("PAUSE");
	return 0;
}
