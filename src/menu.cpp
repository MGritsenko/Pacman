#include "stdafx.h"

void Menu (scores *players, int &size, bool &escape, bool &start, int &difficulty)
{
	

	SetConsoleCursorPosition(2, 0);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "                  ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 1);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "               ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGG"<< endl;   

	SetConsoleCursorPosition(2, 2);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "             ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 3);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "           ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGG";
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout<<"   ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 4);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "         ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 5);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "        ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 6);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "       ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 7);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "      ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 8);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "     ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 9);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "     ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 10);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "     ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 11);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "     ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGG"<< endl; 

	SetConsoleCursorPosition(2, 12);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "     ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 13);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "      ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGGGGG"<< endl;        

	SetConsoleCursorPosition(2, 14);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "       ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 15);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "        ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 16);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "         ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 17);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "           ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGGGGGGGG"<< endl;

	SetConsoleCursorPosition(2, 18);
	SetConsoleColorTextBackground(clYellow, clBlack);
	cout << "              ";
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout<<"GGGGGGGGGGGGGGGGGGGGG"<< endl;    

	SetConsoleCursorPosition(0, 19);
	SetConsoleColorTextBackground(clYellow, clYellow);
	cout << "                                                  "<< endl;

	SetConsoleCursorPosition(20, 22);
	SetConsoleColorTextBackground(clWhite, clBlack);
	cout<<"START GAME";

	SetConsoleCursorPosition(20, 23);
	SetConsoleColorTextBackground(clMagneta, clBlack);
	cout<<"HIGH SCORES";

	SetConsoleCursorPosition(20, 24);
	SetConsoleColorTextBackground(clCyan, clBlack);
	cout<<"DIFFICULTY";

	SetConsoleCursorPosition(15, 25);
	SetConsoleColorTextBackground(clGreen, clBlack);
	cout<<"                                               ";

	SetConsoleCursorPosition(23, 26);
	SetConsoleColorTextBackground(clBrown, clBlack);
	cout<<"EXIT";

	//---------------------------------------------------------------------------------------------------

	int key=0;
	int key2=0;
	int y=22;
	int x=15;
	bool exit=false;
	bool choose=false;

	while (!exit)
	{
		if(_kbhit())
		{
			key=_getch();

			switch (key)
			{
			case 72:						// идем вверх

				if (y==22)
					break;
				else if (y==26)
					y-=2;
				else
					y-=1;
				break;

			case 80:						// идем вниз

				if (y==26)
					break;
				else if (y==24)
					y+=2;
				else
					y+=1;
				break;

			case 13:						// ентер

				exit=true;
				break;
			}

			switch (y)
			{
			case 22:

				SetConsoleCursorPosition(20, 22);
				SetConsoleColorTextBackground(clWhite, clBlack);
				cout<<"START GAME";

				SetConsoleCursorPosition(20, 23);
				SetConsoleColorTextBackground(clMagneta, clBlack);
				cout<<"HIGH SCORES";

				SetConsoleCursorPosition(20, 24);
				SetConsoleColorTextBackground(clCyan, clBlack);
				cout<<"DIFFICULTY";

				SetConsoleCursorPosition(23, 26);
				SetConsoleColorTextBackground(clBrown, clBlack);
				cout<<"EXIT";

				break;

			case 23:

				SetConsoleCursorPosition(20, 22);
				SetConsoleColorTextBackground(clBlue, clBlack);
				cout<<"START GAME";

				SetConsoleCursorPosition(20, 23);
				SetConsoleColorTextBackground(clWhite, clBlack);
				cout<<"HIGH SCORES";

				SetConsoleCursorPosition(20, 24);
				SetConsoleColorTextBackground(clCyan, clBlack);
				cout<<"DIFFICULTY";

				SetConsoleCursorPosition(23, 26);
				SetConsoleColorTextBackground(clBrown, clBlack);
				cout<<"EXIT";

				break;

			case 24:

				SetConsoleCursorPosition(20, 22);
				SetConsoleColorTextBackground(clBlue, clBlack);
				cout<<"START GAME";

				SetConsoleCursorPosition(20, 23);
				SetConsoleColorTextBackground(clMagneta, clBlack);
				cout<<"HIGH SCORES";

				SetConsoleCursorPosition(20, 24);
				SetConsoleColorTextBackground(clWhite, clBlack);
				cout<<"DIFFICULTY";

				SetConsoleCursorPosition(23, 26);
				SetConsoleColorTextBackground(clBrown, clBlack);
				cout<<"EXIT";

				break;

			case 26:

				SetConsoleCursorPosition(20, 22);
				SetConsoleColorTextBackground(clBlue, clBlack);
				cout<<"START GAME";

				SetConsoleCursorPosition(20, 23);
				SetConsoleColorTextBackground(clMagneta, clBlack);
				cout<<"HIGH SCORES";

				SetConsoleCursorPosition(20, 24);
				SetConsoleColorTextBackground(clCyan, clBlack);
				cout<<"DIFFICULTY";

				SetConsoleCursorPosition(23, 26);
				SetConsoleColorTextBackground(clWhite, clBlack);
				cout<<"EXIT";

				break;
			}
		}
	}

	switch (y)
	{
	case 22:

		Load_scores (players, size);

		start=true;

		break;

	case 23:

		Load_scores (players, size);
		Cout_Scores (players, size);

		break;

	case 24:

		SetConsoleCursorPosition(20, 24);
		SetConsoleColorTextBackground(clCyan, clBlack);
		cout<<"DIFFICULTY";

		SetConsoleCursorPosition(15, 25);
		SetConsoleColorTextBackground(clWhite, clBlack);
		cout<<"EASY";

		SetConsoleCursorPosition(22, 25);
		SetConsoleColorTextBackground(clYellow, clBlack);
		cout<<"NORMAL";

		SetConsoleCursorPosition(32, 25);
		SetConsoleColorTextBackground(clRed, clBlack);
		cout<<"HARD";

		while (!choose)
		{
			if(_kbhit())
			{
				key2=_getch();

				switch (key2)
				{
				case 75:						// идем влево

					if (x==15)
						break;
					else if (x==32)
						x-=10;
					else
						x-=7;
					break;

				case 77:						// идем впарво

					if (x==32)
						break;
					else if (x==15)
						x+=7;
					else
						x+=10;
					break;

				case 13:						// ентер

					if (x==15)
						difficulty=1;
					else if (x==22)
						difficulty=2;
					else 
						difficulty=3;

					choose=true;
					break;

				case 27:

					choose=true;

					break;
				}

				switch (x)
				{
				case 15:

					SetConsoleCursorPosition(15, 25);
					SetConsoleColorTextBackground(clWhite, clBlack);
					cout<<"EASY";

					SetConsoleCursorPosition(22, 25);
					SetConsoleColorTextBackground(clYellow, clBlack);
					cout<<"NORMAL";

					SetConsoleCursorPosition(32, 25);
					SetConsoleColorTextBackground(clRed, clBlack);
					cout<<"HARD";

					break;

				case 22:

					SetConsoleCursorPosition(15, 25);
					SetConsoleColorTextBackground(clGreen, clBlack);
					cout<<"EASY";

					SetConsoleCursorPosition(22, 25);
					SetConsoleColorTextBackground(clWhite, clBlack);
					cout<<"NORMAL";

					SetConsoleCursorPosition(32, 25);
					SetConsoleColorTextBackground(clRed, clBlack);
					cout<<"HARD";

					break;

				case 32:

					SetConsoleCursorPosition(15, 25);
					SetConsoleColorTextBackground(clGreen, clBlack);
					cout<<"EASY";

					SetConsoleCursorPosition(22, 25);
					SetConsoleColorTextBackground(clYellow, clBlack);
					cout<<"NORMAL";

					SetConsoleCursorPosition(32, 25);
					SetConsoleColorTextBackground(clWhite, clBlack);
					cout<<"HARD";

					break;
				}
			}
		}

		break;

	case 26:

		start=true;
		escape=true;

		break;
	}
}