#include "stdafx.h"

void Reset (int maze[][col], int grid[][col], int monsters, int letter, monster P_B_R[], player &G)
{
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			if (maze[i][j]==255 || maze[i][j]==249 || maze[i][j]==142)  //если квадрат игрового поля [i][j] проходИм то 
				grid[i][j]=254;										    //присваиваем рабочему полю

			else if (i==P_B_R[monsters].x && j==P_B_R[monsters].y)		//если квадрат игрового поля [i][j] равен стартовой (P || R || B) позиции
				grid[i][j]=letter;										//присваиваем рабочему полю

			else														//если квадрат игрового поля [i][j] не проходИм то 
				grid[i][j]=255;											//присваиваем рабочему полю

			if (i==P_B_R[0].x && j==P_B_R[0].y && monsters!=0 ||		//если квадрат игрового поля [i][j] равен (P || R || B) то 
				i==P_B_R[1].x && j==P_B_R[1].y && monsters!=1 ||
				i==P_B_R[2].x && j==P_B_R[2].y && monsters!=2)			
			{
				grid[i][j]=255;											//присваиваем рабочему полю не проходную клетку
			}

			if (i==G.x && j==G.y)										//если квадрат игрового поля [i][j] равен финишной (G) позиции
				grid[i][j]=0;											//присваиваем рабочему полю
		}
	}

	if (G.x==24 && G.y==46)
				grid[12][24]=255;	
}