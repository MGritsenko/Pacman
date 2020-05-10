#include "stdafx.h"

void Cout_Scores(scores* players, int size)
{
	system("cls");

	for (int i = 0; i < size; i++)
	{
		SetConsoleCursorPosition(17, (7 + i));
		SetConsoleColorTextBackground(clYellow, clBlack);

		cout << setw(9) << players[i].name << ' ' << players[i].best_score << endl;
	}

	_getch();

	system("cls");
}

void Load_scores(scores*& players, int& size)
{
	FILE* file = fopen("score.bin", "rb");

	if (file)
	{
		fread(&size, sizeof(int), 1, file);

		for (int i = 0; i < size; i++)
		{
			fread(&players[i].best_score, sizeof(int), 1, file);

			int size2 = 0;
			fread(&size2, sizeof(int), 1, file);
			fread(&players[i].name, sizeof(char), size2, file);
		}
		fclose(file);
	}
}

void Save_scores(scores* players, int size)
{
	FILE* file = fopen("score.bin", "wb");

	if (file)
	{
		fwrite(&size, sizeof(int), 1, file);

		for (int i = 0; i < size; i++)
		{
			fwrite(&players[i].best_score, sizeof(int), 1, file);

			int size2 = 0;
			size2 = static_cast<int>(strlen(players[i].name) + 1);
			fwrite(&size2, sizeof(int), 1, file);
			fwrite(&players[i].name, sizeof(char), size2, file);
		}
		fclose(file);
	}
}