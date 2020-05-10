#include "stdafx.h"

void Find_path (int maze[][col], bool &stop, int grid[row][col], int letter, monster P_B_R[], int monsters, player &G, bool &eat)
{
	int Ni=0;					//счетчик распространения волны
	const int Nk=64;			//рaвна мaксимaльно возможному числу итерaций Ni не должно быть больше Nk
	bool chek=false;			//для выхода из циклов фор которые распространяют волну

	do {
		for (int i=0; i<row; i++)			//кaждому элементу рaбочего поля [i][j] присвaивaем знaчение в зaвисимости от свойств квадрата [i][j] по следующим правилам
		{
			for (int j=0; j<col; j++)
			{
				if (grid[i][j]==Ni)			//поиск идет с финиша. клетки по которым идет волна увеличиваются от финиша пока не дойдет до старта
				{
					if (i+1==P_B_R[monsters].x && j==P_B_R[monsters].y || i-1==P_B_R[monsters].x && j==P_B_R[monsters].y || i==P_B_R[monsters].x && j+1==P_B_R[monsters].y || i==P_B_R[monsters].x && j-1==P_B_R[monsters].y)  //если равно стартовой позиции то переход к этaпу построения мaршрута перемещения
					{
						chek=true;
						break;
					}
					if (grid [i+1][j]==254)  //если равно проходимой позиции то присваиваем
						grid [i+1][j]=Ni+1;

					if (grid [i-1][j]==254)  //если равно проходимой позиции то присваиваем
						grid [i-1][j]=Ni+1;

					if (grid [i][j+1]==254)  //если равно проходимой позиции то присваиваем
						grid [i][j+1]=Ni+1;

					if (grid [i][j-1]==254)  //если равно проходимой позиции то присваиваем
						grid [i][j-1]=Ni+1;
				}
			}
			if (chek==true)
				break;
		}

		Ni+=1;						//По зaвершению построчного просмотрa всего мaссивa увеличивaем волну Ni нa 1.

		if (Ni>Nk)					//если Ni>Nk то игрок рандомно ходит по полю  до появления маршрута
		{
			Random_path(maze, stop, grid, P_B_R, monsters, letter, G, eat);
			return;
		}
	}while (chek==false);			//пускаем волну пока grid [i][j] не равно стартовой позиции


	//---------------------------------------------Этaп построения мaршрутa перемещения---------------------------------

	int x=P_B_R[monsters].x;		//знaчения координaт стaртовой позиции (монстров)
	int y=P_B_R[monsters].y;

	if (grid[x+1][y]<grid[x][y])	//поиск наименьшего значения Ni в окрестности рабочего поля [x][y] для перемещения монстра
	{
		P_B_R[monsters].x=x+1;
		P_B_R[monsters].y=y;
	}
	if (grid[x-1][y]<grid[x][y])
	{
		P_B_R[monsters].x=x-1;
		P_B_R[monsters].y=y;
	}
	if (grid[x][y+1]<grid[x][y])
	{
		P_B_R[monsters].x=x;
		P_B_R[monsters].y=y+2;
	}
	if (grid[x][y-1]<grid[x][y])
	{
		P_B_R[monsters].x=x;
		P_B_R[monsters].y=y-2;
	}

	//----------------------------------------------Передвижение монстра Р-----------------------------
	
	SetConsoleCursorPosition(y, x);

	switch (monsters)
	{
	case (0):
		if (eat==false)
			SetConsoleColorTextBackground(clMagneta, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	case (1):
		if (eat==false)
			SetConsoleColorTextBackground(clRed, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	case (2):
		if (eat==false)
			SetConsoleColorTextBackground(clCyan, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	}

	printf("%c", letter);
//=================================================================================================================
	SetConsoleCursorPosition(y, x);
	SetConsoleColorTextBackground(clYellow, clBlack);

	if (maze[x][y]==142)
		SetConsoleColorTextBackground(clWhite, clBlack);

	printf("%c", maze[x][y]);
//=================================================================================================================
	SetConsoleCursorPosition(P_B_R[monsters].y, P_B_R[monsters].x);

	switch (monsters)
	{
	case (0):
		if (eat==false)
			SetConsoleColorTextBackground(clMagneta, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	case (1):
		if (eat==false)
			SetConsoleColorTextBackground(clRed, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	case (2):
		if (eat==false)
			SetConsoleColorTextBackground(clCyan, clBlack);
		else
			SetConsoleColorTextBackground(clWhite, clBlack);
		break;
	}

	printf("%c", letter);
//=================================================================================================================
	if (P_B_R[monsters].x==G.x && P_B_R[monsters].y==G.y)	//если монстр догнал игрока то 
	{
		if (eat==false)
		{
			stop=true;										//отнимаем жизнь
			return;
		}
		else
		{
			switch (monsters)
			{
			case (0):
				P_B_R[monsters].x=14;
				P_B_R[monsters].y=24;
				break;
			case (1):
				P_B_R[monsters].x=14;
				P_B_R[monsters].y=20;
				break;
			case (2):
				P_B_R[monsters].x=14;
				P_B_R[monsters].y=28;
				break;
			}
		}
	}
}