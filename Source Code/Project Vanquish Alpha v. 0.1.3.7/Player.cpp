#include "Library.h"
using namespace std;

PLAYER::PLAYER()
{
	Inventory = new INVENTORY;
	Magic = new MAGIC;

	X = 0;
	Y = 0;

	Name = "Default";

	Hp = 50;
	MaxHp = 50;
	Mp = 50;
	MaxMp = 50;

	Str = 5;
	Def = 5;
	MgcStr = 5;
	MgcDef = 5;
	Agil = 5;
	Intel = 5;
	Luck = 5;

	Gold = 10;
	Exp = 0;
	Level = 1;
	AttribPoints = 0;

	ExpLevelBonus = .5;
	BaseExp = new unsigned int [MAX_LV];
	BaseExp[0] = 483;
	BaseExp[1] = 555; 
	BaseExp[2] = 638;
	BaseExp[3] = 733;
	BaseExp[4] = 842;
	BaseExp[5] = 968;
	BaseExp[6] = 1113;
	BaseExp[7] = 1279;
	BaseExp[8] = 1470;
	BaseExp[9] = 1690;
	BaseExp[10] = 1943;
	BaseExp[11] = 2234;
	BaseExp[12] = 2569;
	BaseExp[13] = 2954;
	BaseExp[14] = 3397;
	BaseExp[15] = 3906;
	BaseExp[16] = 4491;
	BaseExp[17] = 5164;
	BaseExp[18] = 5938;
	BaseExp[19] = 6828;
	BaseExp[20] = 7852;
	BaseExp[21] = 9029;
	BaseExp[22] = 10383;
	BaseExp[23] = 11940;
	BaseExp[24] = 13730;
	BaseExp[25] = 15789;
	BaseExp[26] = 18157;
	BaseExp[27] = 20880;
	BaseExp[28] = 24011; 
	BaseExp[29] = 27612;	
	BaseExp[30] = 31753;
	BaseExp[31] = 36515; 
	BaseExp[32] = 41992;
	BaseExp[33] = 48290;
	BaseExp[34] = 55533;
	BaseExp[35] = 63862;
	BaseExp[36] = 73441;
	BaseExp[37] = 84457;
	BaseExp[38] = 97125;
	BaseExp[39] = 111693;
	BaseExp[40] = 128446;
	BaseExp[41] = 147712;
	BaseExp[42] = 169868;
	BaseExp[43] = 195348;
	BaseExp[44] = 224650;
	BaseExp[45] = 258347;
	BaseExp[46] = 297099;
	BaseExp[47] = 341663;
	BaseExp[48] = 392912;
	BaseExp[49] = 451848;
	BaseExp[50] = 519625;
	BaseExp[51] = 597568;
	BaseExp[52] = 687203;
	BaseExp[53] = 790283;
	BaseExp[54] = 908825;
	BaseExp[55] = 1045148;
	BaseExp[56] = 1201920;
	BaseExp[57] = 1382208;
	BaseExp[58] = 1589539;
	BaseExp[59] = 1827969;	
	BaseExp[60] = 2102164;
	BaseExp[61] = 2417488;
	BaseExp[62] = 2780111;
	BaseExp[63] = 3197127;
	BaseExp[64] = 3676696;
	BaseExp[65] = 4228200;
	BaseExp[66] = 4862430;
	BaseExp[67] = 5591794;
	BaseExp[68] = 6430563;
	BaseExp[69] = 7395147;	
	BaseExp[70] = 8504419;
	BaseExp[71] = 9780081;	
	BaseExp[72] = 11247093;
	BaseExp[73] = 12934156;
	BaseExp[74] = 14874279;
	BaseExp[75] = 17105420;
	BaseExp[76] = 19671233;
	BaseExp[77] = 22621917;
	BaseExp[78] = 26015204;
	BaseExp[79] = 29917484;	
	BaseExp[80] = 34405106;
	BaseExp[81] = 39565871;
	BaseExp[82] = 45500751;
	BaseExp[83] = 52325863;
	BaseExp[84] = 60174742;
	BaseExp[85] = 69200953;
	BaseExp[86] = 79581095;
	BaseExp[87] = 91518259;
	BaseExp[88] = 105245997;
	BaseExp[89] = 121032896;
	BaseExp[90] = 139187830;
	BaseExp[91] = 160066004;
	BaseExp[92] = 184075904;
	BaseExp[93] = 211687289;
	BaseExp[94] = 243440382;
	BaseExp[95] = 279956439;
	BaseExp[96] = 321949904;
	BaseExp[97] = 370242389;
	BaseExp[98] = 425778747;
}
PLAYER::~PLAYER()
{
	delete [] BaseExp;
}

/* Add functions */
void PLAYER::AddX(int XAmount)
{
	X += XAmount;
}
void PLAYER::AddY(int YAmount)
{
	Y += YAmount;
}

void PLAYER::AddGold(int GoldAmount)
{
	Gold += GoldAmount;
}
void PLAYER::AddExp(double ExpAmount)
{
	Exp += ExpAmount;

	if(Level == MAX_LV && Exp >= BaseExp[Level - 1])
	{
		Exp = BaseExp[Level - 1] - 1;
	}
	else if(Exp >= BaseExp[Level - 1])
	{
		Exp -= BaseExp[Level - 1];
		AddAttribPoints(1);

		Str++;
		Def++;
		MaxHp += 3;
		Hp += 3;
		Agil++;
		Def += 3;
		Intel++;
		MgcStr += 3;
		Luck++;
		MgcDef += 3;
		MaxMp += 3;
		Mp += 3;

		AddLevel(1);
	}
	else
	{
		if(Exp >= BaseExp[Level - 1])
		{
			Exp = BaseExp[Level - 1] - 1;
		}
	}
}
void PLAYER::AddLevel(int LevelAmount)
{
	Engine->Screen.ClearScreen();
	Engine->Screen.DrawColorText("Level up!", 11);
	Level += LevelAmount;

	if(Level >= 80)
	{
		ExpLevelBonus += .1;
	}
	else if(Level >= 65)
	{
		ExpLevelBonus += .05;
	}
	else if(Level >= 50)
	{
		ExpLevelBonus += .025;
	}
	else
	{
		ExpLevelBonus += .01;
	}
}
void PLAYER::AddAttribPoints(int AttribPointsAmount)
{
	AttribPoints += AttribPointsAmount;
}
void PLAYER::AddStats()
{
	short Choice;

	if(AttribPoints > 0)
	{
		if(AttribManual == true && AttribAutoSet == false && AttribAutoGame == false)
		{
			Engine->Screen.SetCursorPosition(11, 0);

			std::cout << "What stat would you like to put a point on? (" << AttribPoints << " left)" << std::endl;
			std::cout << "1) Strength\t\t-" << Str << std::endl;
			std::cout << "2) Agility\t\t-" << Agil << std::endl;
			std::cout << "3) Intelligence\t-" << Intel << std::endl;
			std::cout << "4) Luck\t\t\t\t-" << Luck << std::endl;
			cin >> Choice;

			switch(Choice)
			{
			case 1:
				Str += 2;
				Def += 2;
				MaxHp += 6;
				Hp += 6;
				AttribPoints--;
				break;
			case 2:
				Agil += 2;
				Def += 6;
				MaxHp += 2;
				Hp += 2;
				AttribPoints--;
				break;
			case 3:
				Intel += 2;
				MgcStr += 6;
				MaxMp += 2;
				Mp += 2;
				AttribPoints--;
				break;
			case 4:
				Luck += 2;
				MgcDef += 6;
				MaxMp += 6;
				Mp += 6;
				AttribPoints--;
				break;
			default:
				break;
			}
		}
		else if(AttribManual == false && AttribAutoSet == true && AttribAutoGame == false)
		{
			Engine->Screen.SetCursorPosition(11, 0);

			std::cout << "Attribute point put on ";

			switch(AttribSet)
			{
			case 1:
				Str += 2;
				Def += 2;
				MaxHp += 6;
				Hp += 6;
				std::cout << "strength." << std::endl;
				AttribPoints--;
				break;
			case 2:
				Agil += 2;
				Def += 6;
				MaxHp += 2;
				Hp += 2;
				std::cout << "agility." << std::endl;
				AttribPoints--;
				break;
			case 3:
				Intel += 2;
				MgcStr += 6;
				MaxMp += 2;
				Mp += 2;
				std::cout << "intelligence." << std::endl;
				AttribPoints--;
				break;
			case 4:
				Luck += 2;
				MgcDef += 6;
				MaxMp += 6;
				Mp += 6;
				std::cout << "luck." << std::endl;
				AttribPoints--;
				break;
			default:
				break;
			}
		}
		else if(AttribManual == false && AttribAutoSet == false && AttribAutoGame == true)
		{
			Engine->Screen.SetCursorPosition(11, 0);

			if(Deaths * 5 < Kills || (Deaths * 5) + (Kills / 10) > PhyAttacks)
			{
				Choice = 1;
			}
			else if(Deaths * 5 > Def || (Deaths * 5) + (Kills / 10) > PhyHits)
			{
				Choice = 2;
			}
			else if((Deaths * 5) + Def < MgcStr || (Deaths * 5) + (Kills / 10) < MagAttacks)
			{
				Choice = 3;
			}
			else if(Deaths * 5 > MaxMp || (Deaths * 5) + (Kills / 10) < MagHits || (Deaths * 5) + (Kills / 10) < MgcDef)
			{
				Choice = 4;
			}
			else /* Happens with high deaths, high amount of physical attacks, high defence, high physical hits from monters,
								low magic strength, low magic attacks, medium maximum MP (assuming there are deaths),
								low magic hits from monsters, and low magic defence. */
			{
				Choice = rand()%5 + 1;
			}

			std::cout << "Attribute point put on ";

			switch(Choice)
			{
			case 1:
				Str += 2;
				Def += 2;
				MaxHp += 6;
				Hp += 6;
				std::cout << "strength." << std::endl;
				AttribPoints--;
				break;
			case 2:
				Agil += 2;
				Def += 6;
				MaxHp += 2;
				Hp += 2;
				std::cout << "agility." << std::endl;
				AttribPoints--;
				break;
			case 3:
				Intel += 2;
				MgcStr += 6;
				MaxMp += 2;
				Mp += 2;
				std::cout << "intelligence." << std::endl;
				AttribPoints--;
				break;
			case 4:
				Luck += 2;
				MgcDef += 6;
				MaxMp += 6;
				Mp += 6;
				std::cout << "luck." << std::endl;
				AttribPoints--;
				break;
			case 5: // 20% chance for this to happen if the character is described above.
				Str += 2;
				Def += 8;
				MaxHp += 8;
				Hp += 8;
				Agil += 2;
				Intel += 2;
				MgcStr += 6;
				MaxMp += 8;
				Mp += 8;
				Luck += 2;
				MgcDef += 6;
			default:
				break;
			}
		}
	}
}

/* Subtract functions */
void PLAYER::SubGold(int GoldAmount)
{
	Gold -= GoldAmount;
}