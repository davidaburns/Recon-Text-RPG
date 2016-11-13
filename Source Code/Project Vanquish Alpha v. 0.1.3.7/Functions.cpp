#include <iostream>
#include <windows.h>
using namespace std;

char* StrToCharPtr(std::string String)
{
	char* Buffer = new char[String.length() + 1];
	strcpy(Buffer, String.c_str());

	return Buffer;
}

bool StrToBool(std::string String)
{
	if(atoi(String.c_str()) == 0)
	{
		return false;
	}
	else if(atoi(String.c_str()) == 1)
	{
		return true;
	}
	else
	{
		std::cout << "Error! Unable to convert from string to bool!" << std::endl;
		return true;
	}
}