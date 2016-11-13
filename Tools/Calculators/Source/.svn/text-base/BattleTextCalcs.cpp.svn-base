#include "BattleTextCalcs.h"

//Physical Attack Calculator Functions
void PhysAtk::physCalcInit()
{
	system("TITLE TextBattle Physical Damage Calculator: Rev 1.8.5 9/27/08");
	srand(static_cast<unsigned int>(time(0)));

	algoOutput();

	setPlrStr(inputPlrStr());
	setEnmyDef(inputEnmyDef());

	physAtkMain();

}
void PhysAtk::physAtkMain()
{
	int prtPlrStr = getPlrStr();  
	int prtEnmyDef = getEnmyDef();
	
	int prtRndNum;
	int damage;

	cout << "\n-----------------------" << endl << endl;

	cout << "RndNum  PlrStr  EnmyDef  Damage" << endl;

	for (int i = 0; i <= 5; i++)
	{
		prtRndNum = getRndNum();
		damage = ((prtPlrStr * prtRndNum) - prtEnmyDef) + (rand() % 6 + 1);

		if (damage < 0)
		{
			damage = 0;
		}

		cout << prtRndNum << "       " << prtPlrStr << "      " << prtEnmyDef << "         " << damage << endl;
	}
	
	cout << endl;
}
void PhysAtk::algoOutput()
{
	cout << "\n--Random Number Algorithm-- " << endl;
	cout << " (rand() % 4+1)" << endl << endl;

	cout << "--Physical Damage Algorithm--" << endl;
	cout << "((plrStr * rndNum) - enmyDef) + (rand() % 6 + 1)" << endl << endl;

	cout << "-----------------------" << endl << endl;
}

int PhysAtk::inputPlrStr()
{
	cout << "Enter PLAYER Str Stat: ";
	cin >> plrStr;

	return plrStr;
}
int PhysAtk::inputEnmyDef()
{
	cout << "Enter ENEMY Def Stat: ";
	cin >> enmyDef;

	return enmyDef;
}

int PhysAtk::getPlrStr()
{
	return plrStr;
}
int PhysAtk::getEnmyDef()
{
	return enmyDef;
}
int PhysAtk::getRndNum()
{
	return (rand() % 5 + 2);
}
void PhysAtk::setPlrStr(int Str)
{
	plrStr = Str;
}
void PhysAtk::setEnmyDef(int Def)
{
	enmyDef = Def;
}

//Magical Attack Calculator Functions
void MgcAtk::mgcCalcInit(void)
{
	system("TITLE TextBattle Magic Damage Calculator: Rev 1.0 10/2/08");
	srand(static_cast<unsigned int>(time(0)));

	algoOutput();

	setPlrMgcStr(inputPlrMgcStr());
	setEnmyMgcDef(inputEnmyMgcDef());

	mgcAtkMain();
}
void MgcAtk::mgcAtkMain(void)
{
	int prtRndNum;
	int prtEnmyType;
	int prtAtkType;
	int prtTypeAtkBonus;
	int prtDamage;

	int prtPlrMgcStr = getPlrMgcStr();
	int prtEnmyMgcDef = getEnmyMgcDef();

	cout << "RndNum    AtkType    EnmyType    Type Bonus    Damage" <<endl;

	for (int i = 0; i <= 5; i++)
	{
		prtRndNum = getRndNum();
		prtEnmyType = getRndEnmyElmntType();
		prtAtkType = getRndMgcAtkType();

		prtTypeAtkBonus = atkElmntBonus(prtAtkType, prtEnmyType);

		prtDamage = ((prtPlrMgcStr * prtRndNum) - prtEnmyMgcDef) + (rand() % 6 + 1) + prtTypeAtkBonus;

		cout << prtRndNum << "         " 
			 << prtAtkType << "          " 
			 << prtEnmyType << "           " 
			 << prtTypeAtkBonus << "             "
			 << prtDamage << endl;

	}

	cout << endl;
}

void MgcAtk::algoOutput(void)
{
	cout << "--Random Number-- " << endl;
	cout << "(rand() % 5 + 1)" << endl <<endl;
	cout << "--Magic Damage Algorithm--" << endl;
	cout << "((prtPlrMgcStr * prtRndNum) - prtEnmyMgcDef) + (rand() % 6 + 1) \n+ prtTypeAtkBonus" << endl <<endl;
	cout << "-----------------------" << endl << endl;
}
int MgcAtk::atkElmntBonus(int atkType, int enmyType)
{
		int bonus;

		int plrMgcStr = getPlrMgcStr();
		int enmyMgcDef = getEnmyMgcDef();
		int rndNum = (rand() % 5 + 1);

		if ((atkType == 2) && (enmyType == 3)) 
		{
			bonus = -((plrMgcStr + enmyMgcDef) / rndNum);
			return bonus;
		}
		else if ((atkType == 3) && (enmyType == 2)) 
		{
			bonus = (plrMgcStr + enmyMgcDef) * rndNum;
			return bonus;
		}
		else if ((atkType == 2) && (enmyType == 7)) 
		{
			bonus = (plrMgcStr + enmyMgcDef) * rndNum;
			return bonus;
		}
		else if ((atkType == 7) && (enmyType == 2)) 
		{
			bonus = (plrMgcStr + enmyMgcDef) * rndNum;
			return bonus;
		}
		else if ((atkType == 3) && (enmyType == 5)) 
		{
			bonus = -((plrMgcStr + enmyMgcDef) / rndNum);
			return bonus;
		}
		else if ((atkType == 5) && (enmyType == 3)) 
		{
			bonus = (plrMgcStr + enmyMgcDef) * rndNum;
			return bonus;
		}
		else if ((atkType == 9) && (enmyType == 8)) 
		{
			bonus = (plrMgcStr + enmyMgcDef) * rndNum;
			return bonus;
		}
		else if ((atkType == 8) && (enmyType == 9)) 
		{
			bonus = (plrMgcStr + enmyMgcDef) * rndNum;
			return bonus;
		}
		else
		{
			return 0;
		}

}
int MgcAtk::inputPlrMgcStr(void)
{
	cout << "Enter PLAYER MAGIC Str Stat: ";
	cin >> plrMgcStr;

	return plrMgcStr;
}
int MgcAtk::inputEnmyMgcDef(void)
{
	cout << "Enter ENEMY MAGIC Def Stat: ";
	cin >> enmyMgcDef;

	cout << "\n-----------------------------" << endl <<endl;

	return enmyMgcDef;
}

int MgcAtk::getPlrMgcStr(void)
{
	return plrMgcStr;
}
int MgcAtk::getEnmyMgcDef(void)
{
	return enmyMgcDef;
}
int MgcAtk::getRndNum(void)
{
	return (rand() % 6 + 2);
}
int MgcAtk::getRndEnmyElmntType(void)
{
	return (rand() % 9 + 1);
}
int MgcAtk::getRndMgcAtkType(void)
{
	return (rand() % 9 + 1);
}

void MgcAtk::setPlrMgcStr(int plrMgStr)
{
	plrMgcStr = plrMgStr;
}
void MgcAtk::setEnmyMgcDef(int enmyMgDef)
{
	enmyMgcDef = enmyMgDef;
}
//Experience Calculator Functions