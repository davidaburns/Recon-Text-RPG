#include "Library.h"

VANQ_DEBUG::VANQ_DEBUG()
{
}
VANQ_DEBUG::~VANQ_DEBUG()
{
	delete DebugFile;
}
bool VANQ_DEBUG::OpenDebugFile()
{
	DebugFile.open(StrToCharPtr("Data\\EngineDebug.txt"));
	if (!DebugFile.is_open())
	{
		return false;
	}

	return true;
}
void VANQ_DEBUG::CloseDebugFile()
{
	DebugFile.flush();
	DebugFile.close();
}
void VANQ_DEBUG::DebugWrite(std::string DebugTxt)
{
	DebugFile << DebugTxt << "\n";
}