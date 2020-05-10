#include "stdafx.h"

void Random_path(int maze[][col], bool &stop, int grid[row][col], monster P_B_R[], int monsters, int letter, player &G, bool &eat)
{
	bool chek=false;

	int step=rand()%4;
	int x=P_B_R[monsters].x;
	int y=P_B_R[monsters].y;

	if (step==0)
	{
		if (grid[P_B_R[monsters].x][P_B_R[monsters].y+2]==254)
		{
			P_B_R[monsters].y+=2;
			chek=true;
		}
	}
	else if (step==1)
	{
		if (grid[P_B_R[monsters].x][P_B_R[monsters].y-2]==254)
		{
			P_B_R[monsters].y-=2;
			chek=true;
		}
	}
	else if (step==2)
	{
		if (grid[P_B_R[monsters].x-1][P_B_R[monsters].y]==254)
		{
			P_B_R[monsters].x-=1;
			chek=true;
		}
	}
	else if (step==3)
	{
		if (grid[P_B_R[monsters].x+1][P_B_R[monsters].y]==254)
		{
			P_B_R[monsters].x+=1;
			chek=true;
		}
	}
//=================================================================================================================
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

	printf ("%c", letter);
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
			stop=true;											//выходит из игры в мейне
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