
#ifndef DEBUG_H
#define DEBUG_H

#include "Library.h"

class VANQ_DEBUG
{
private:
	std::ofstream DebugFile;

public:
	VANQ_DEBUG();
	~VANQ_DEBUG();

	bool OpenDebugFile();
	void CloseDebugFile();

	void DebugWrite(std::string DebugTxt);
};

#endif