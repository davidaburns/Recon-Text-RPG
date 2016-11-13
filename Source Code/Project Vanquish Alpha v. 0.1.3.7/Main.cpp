#include "Library.h"

int main()
{

	Engine->Initiate("Project Vanquish Alpha v0.2.5", "[NPCWarpTest]");
	while (Engine->GetIsRunning())
	{
		Engine->Update();
		Engine->Draw();
		Engine->ProccessInput();
		//_CrtDumpMemoryLeaks(); //Dumps memory leaks if any found.
	}

	//CleanUp call was moved to the escape key.
	return 0;
}