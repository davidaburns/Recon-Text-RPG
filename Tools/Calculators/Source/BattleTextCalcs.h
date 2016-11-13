#ifndef BATTLE_CALC
#define BATTLE_CALC

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class PhysAtk
{
	private:
		int rndNum;

		int plrStr;
		int enmyDef;
		int damage;

	public:
		void physCalcInit(void);
		void algoOutput(void);
		void physAtkMain(void);

		//Input Functions
		int inputPlrStr(void);
		int inputEnmyDef(void);

		//Get Functions
		int getPlrStr(void);
		int getEnmyDef(void);
		int getRndNum(void);

		//Set Functions
		void setPlrStr(int plrStr);
		void setEnmyDef(int enmyDef);

};

class MgcAtk
{
	private:
		int rndNum;
		int plrMgcStr;
		int enmyMgcDef;
		int damage;

		int mgcAtkType;
		int enmyElmntType;

	public:
		void mgcCalcInit(void);
		void mgcAtkMain(void);
		void algoOutput(void);

		int atkElmntBonus(int atkType, int enmyType);

		int inputPlrMgcStr(void);
		int inputEnmyMgcDef(void);

		int getPlrMgcStr(void);
		int getEnmyMgcDef(void);
		int getRndNum(void);
		int getRndEnmyElmntType(void);
		int getRndMgcAtkType(void);

		void setPlrMgcStr(int plrStr);
		void setEnmyMgcDef(int enmyDef);
};
#endif