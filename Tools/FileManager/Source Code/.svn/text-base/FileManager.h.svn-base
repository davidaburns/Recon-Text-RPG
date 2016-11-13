#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "Globals.h"

class FileManager
{
private:

	char *FileName; //Keeps track of current name of the file
	FILE *File;		//A stream to a file

public:
	FileManager()
	{
		SetConsoleTitle("C++ Testing: File Manager");

		//Make sure no file are open
		FileName = NULL;
		File = NULL;
	}
	~FileManager()
	{
	}
	char *FilePathInput()
	{
		std::string FilePath;
		char *FilePathSz = NULL;

		std::cout << "Enter File Path: ";
		std::cin >> FilePath;

		FilePathSz = new char[FilePath.length() + 1];
		strcpy(FilePathSz, FilePath.c_str());

		return FilePathSz;
	}
	bool FileCreate(char *FilePath)
	{
		File = fopen(FilePath, "w+");
		if (File == NULL)
		{
			std::cout << "\nFailed To Create: " << FilePath << std::endl;
			return false;
		}

		std::cout << FilePath << " Created Successfully!\n";

		FileName = FilePath;
		fclose(File);

		return true;
	}
	bool FileOpen(char *FName)
	{
		File = fopen(FName, "r+");
		if (File == NULL)
		{
			std::cout << "Failed To Open: " << FName << std::endl;
			return false;
		}

		std::cout << std::endl << FName << " Opened Successfully!\n";

		FileName = FName;

		return true;
	}
	bool FileClose()
	{
		if (File == NULL)
		{
			std::cout << "\nNo File is currently opened.\n";
			return false;
		}
		else
		{
			std::cout << "Closing File: " << FileName << "...\n";
			fclose(File);
			std::cout << FileName << " is now closed.\n";
			
			return true;
		}
	}
	void GetOpenedFile()
	{
		std::cout << "\nCurrent Opened File: " << FileName << std::endl;
	}
}File;

#endif