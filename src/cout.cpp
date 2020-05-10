#include "stdafx.h"

void SetConsoleColorTextBackground(unsigned short Tex, unsigned short Bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Bg = Bg << 4 | Tex;
	SetConsoleTextAttribute(hConsole, Bg);
}

void SetConsoleWinSizePosition(int width, int heigth, short x_position, short y_position)
{
	HWND hWnd = GetForegroundWindow();

	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWindowPos(hWnd, NULL, x_position, y_position, 0, 0, NULL);
	SMALL_RECT windowSize;
	windowSize.Bottom = heigth;
	windowSize.Left = 0;
	windowSize.Right = width;
	windowSize.Top = 0;
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	COORD bufferSize = { static_cast<short>(width + 1) , static_cast<short>(heigth + 1) };
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void SetConsoleCursorPosition(short x_position, short y_position)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD _coordPosition = { x_position, y_position };
	SetConsoleCursorPosition(hConsole, _coordPosition);
}

void Absence()												//отключает курсор в консоле
{
	HANDLE A_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(A_handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(A_handle, &structCursorInfo);
}

void Cout_mas(int maze[][col])
{
	SetConsoleCursorPosition(0, 0);
	for (int i = 0; i < row; i++)
	{
		SetConsoleColorTextBackground(clCyan, clBlue);
		for (int j = 0; j < col; j++)
		{
			if (maze[i][j] == 249)
			{
				SetConsoleColorTextBackground(clYellow, clBlack);
				printf("%c", maze[i][j]);
			}
			else if (maze[i][j] == 71)
			{
				SetConsoleColorTextBackground(clLime, clBlack);
				printf("%c", maze[i][j]);
			}
			else if (maze[i][j] == 142)
			{
				SetConsoleColorTextBackground(clWhite, clBlack);
				printf("%c", maze[i][j]);
			}
			else
			{
				SetConsoleColorTextBackground(clBlue, clBlack);
				printf("%c", maze[i][j]);
			}
		}
		cout << endl;
	}
	cout << endl;

	SetConsoleCursorPosition(46, 24);
	SetConsoleColorTextBackground(clLime, clBlack);
	cout << (char)71;
}

