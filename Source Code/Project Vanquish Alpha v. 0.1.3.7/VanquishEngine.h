#ifndef VANQUISH_ENGINE_H
#define VANQUISH_ENGINE_H

#include "Library.h"

class VanquishEngine
{
private:	
	char KeyInput;
	
	bool IsRunning;
	bool IsDrawing;

protected:

public:
	//Sub-Systems - ENGINE
	VANQ_DEBUG Debug;
	SCREEN Screen;
	MAP Map;
	QUEST Quest;
	_LUA Lua;

	//Game Objects
	PLAYER Player;
	MONSTER* Monster;

	VanquishEngine();
	~VanquishEngine();

	//Game Loop Functions
	void Initiate(std::string GameTitle, std::string MapName);
	void ProccessInput();
	void Update();
	void Draw();
	void CleanUp();

	//Other Functions
	void TranslateInput(int KeyInput);

	void TurnOffEngine();
	void TurnOffDrawing();
	void TurnOnDrawing();

	bool GetIsRunning();
	bool GetIsDrawing();
};

extern VanquishEngine _Engine;
extern VanquishEngine* Engine;
#endif