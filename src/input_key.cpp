#include "stdafx.h"

void Player_G (int maze[][col], int &direction, int &tmp_direction, player &G, bool &eat, monster P_B_R[], bool &stop, bool &exit)
{
	int key=0;
	Sleep (107);
	//getch ();
	
	if(_kbhit())						//временное хранения хода, этот параметр передастся когда не будет препятствий для поворота
	{
		key=_getch();
		switch (key)
		{
		case 75:						// идем влево
			tmp_direction=1;
			break;
		case 72:						// идем вверх
			tmp_direction=2;
			break;
		case 77:						// идем вправо
			tmp_direction=3;
			break;
		case 80:						// идем вниз
			tmp_direction=4;
			break;
		case 27:
			stop=true;
			exit=true;
			return;
		}
	}

	switch (tmp_direction)				//если была команда повернуть то пакман повернет когда не будет препятствия
	{
	case 1:								// идем влево
		if (maze[G.x][G.y-2]==249 || maze[G.x][G.y-2]==255 || maze[G.x][G.y-2]==142)
			direction=1;
		break;
	case 2:								// идем вверх
		if (maze[G.x-1][G.y]==249 || maze[G.x-1][G.y]==255 || maze[G.x-1][G.y]==142)
			direction=2;
		break;
	case 3:								// идем вправо
		if (maze[G.x][G.y+2]==249 || maze[G.x][G.y+2]==255 || maze[G.x][G.y+2]==142)
			direction=3;
		break;
	case 4:								// идем вниз
		if (maze[G.x+1][G.y]==249 || maze[G.x+1][G.y]==255 || maze[G.x+1][G.y]==142)
			direction=4;
		break;
	}

	switch (direction)					//проверка на препятствия
	{
	case 1:								// идем влево
		if (maze[G.x][G.y-2]==249 || maze[G.x][G.y-2]==255 || maze[G.x][G.y-2]==142)
			Move (maze, -2, G, eat, P_B_R, stop);
		break;

	case 2:								// идем вверх
		if (maze[G.x-1][G.y]==249 || maze[G.x-1][G.y]==255 || maze[G.x-1][G.y]==142)
			Move (maze, -1, G, eat, P_B_R, stop);
		break;

	case 3:								// идем вправо
		if (maze[G.x][G.y+2]==249 || maze[G.x][G.y+2]==255 || maze[G.x][G.y+2]==142)
			Move (maze, 2, G, eat, P_B_R, stop);
		break;

	case 4:								// идем вниз
		if (maze[G.x+1][G.y]==249 || maze[G.x+1][G.y]==255 || maze[G.x+1][G.y]==142)
			Move (maze, 1, G, eat, P_B_R, stop);
		break;
	}
}

void Move (int maze[][col], int turn, player &G, bool &eat, monster P_B_R[], bool &stop)	//движок передвижения и игрока
{
	SetConsoleColorTextBackground(clLime, clBlack);
	SetConsoleCursorPosition(G.y, G.x);

	maze[G.x][G.y]=255;
	printf("%c", 255);

	if (turn==2 || turn==-2)			//лево право 
		G.y+=turn;

	if (turn==1 || turn==-1)			//верх низ
		G.x+=turn;

	if (maze[G.x][G.y]==142)			//можно есть монстров
				eat=true;

	if ((G.x==P_B_R[0].x && G.y==P_B_R[0].y || G.x==P_B_R[1].x && G.y==P_B_R[1].y || G.x==P_B_R[2].x && G.y==P_B_R[2].y) && eat==false)
	{
		maze[G.x][G.y]=255;
		stop=true;						//минус одна жизнь
		return;
	}

	SetConsoleCursorPosition(G.y, G.x);

	maze[G.x][G.y]=255;
	printf("%c", 71);

	if (G.x==14 && G.y==0 || G.x==14 && G.y==48 || G.x==25 && G.y==22 || G.x==25 && G.y==26 || G.x==0 && G.y==22 || G.x==0 && G.y==26) //телепорт пакман выходит с другого конца
	{
		SetConsoleCursorPosition(G.y, G.x);

		maze[G.x][G.y]=255;
		printf("%c", 71);

		Sleep (135);
		SetConsoleCursorPosition(G.y, G.x);

		maze[G.x][G.y]=255;
		printf("%c", maze[G.x][G.y]);

		if (G.x==14 && G.y==0)				//вход слева появляется справа
		{
			G.x=14; 
			G.y=48;
		}

		else if (G.x==14 && G.y==48)		//вход справа появляется слева
		{
			G.x=14; 
			G.y=0;
		}

		else if (G.x==25 && G.y==22)		//вход снизу слева появляется сверху слева
		{
			G.x=0; 
			G.y=22;
		}

		else if (G.x==25 && G.y==26)		//вход снизу спарва появляется свреху справа
		{
			G.x=0; 
			G.y=26;
		}

		else if (G.x==0 && G.y==22)			//вход сверху слева появляется снизу слева
		{
			G.x=25; 
			G.y=22;
		}

		else if (G.x==0 && G.y==26)			//вход сверху справа появляется снизу справа
		{
			G.x=25; 
			G.y=26;
		}

		SetConsoleCursorPosition(G.y, G.x);

		maze[G.x][G.y]=255;
		printf("%c", 71);
	}
}