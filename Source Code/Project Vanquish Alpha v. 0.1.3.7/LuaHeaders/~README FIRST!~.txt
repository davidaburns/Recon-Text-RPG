Before using lua, make a directory to place the header files and library files.
Preferably a folder that has a inlude & lib folder so you can distinguish were your library
files are at and header files are at.

Then go into your compiler and add the directories so the compiler can find the files.
	
	For MS Visual Studio:
		Tools->Options->Projects and Solutions->VC++ Directories
		Add the directories for 'Include Files' & 'Library Files'

then add the following dll file into your source folder lua5.1.dll, then before distributing
the program, include it with your .exe file.