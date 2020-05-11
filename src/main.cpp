#include "stdafx.h"

void main ()
{
	SetConsoleWinSizePosition (49, 29, 475, 115);

	srand((unsigned)time(NULL));
	
	Absence ();								

	player G;
	monster P_B_R[3];

	timer rand_P;
	timer rand_B;
	timer rand_R;

	scores players[10];

	G.x=24;
	G.y=46;

	P_B_R[0].x=14;
	P_B_R[0].y=24;
	P_B_R[1].x=14;
	P_B_R[1].y=20;
	P_B_R[2].x=14;
	P_B_R[2].y=28;

	rand_P.rand=0;
	rand_P.norand=0;
	rand_B.rand=0;
	rand_B.norand=0;
	rand_R.rand=0;
	rand_R.norand=0;

	int difficulty=0;
	int size=0;
	int count=50;
	int highscore=0;
	int score=0;
	int monster=0;							//монстер P B R для работы с массивом структур
	int letter=0;							//код буквы монстра
	int direction=0;						//текущее направление движения игрока
	int tmp_direction=0;					//будующее направление движения поворота игрока
	bool stop=false;
	bool eat=false;
	bool game_over=false;
	bool escape=false;
	bool start=false;
	bool exit=false;
	int grid_P[row][col];					//дубликат игрового поля для поиска пути
	int grid_B[row][col];					
	int grid_R[row][col];
	
	while (true)
	{
		system ("cls");

		while (!start)
		Menu (players, size, escape, start, difficulty);

		start=false;

		if (escape)
			return;

		SetConsoleColorTextBackground(clWhite, clBlack);

		highscore=0;
		score=0;

		game_over=false;
		exit=false;

		while (!game_over)
		{
			system ("cls");

			int maze[row][col]={{218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217,   0, 249,   0, 179,   0, 249,   0, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191},
			{179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179},
			{179,   0, 249,   0, 218, 196, 196, 196, 196, 196, 191,   0, 249,   0, 218, 196, 196, 196, 196, 196, 191,   0, 249,   0, 179,   0, 249,   0, 218, 196, 196, 196, 196, 196, 191,   0, 249,   0, 218, 196, 196, 196, 196, 196, 191,   0, 249,   0, 179},
			{179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179},
			{179,   0, 142,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 142,   0, 179},
			{179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179},
			{179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179},
			{179,   0, 249,   0, 192, 196, 196, 196, 196, 196, 217,   0, 249,   0, 192, 196, 196, 196, 196, 196, 217,   0, 249,   0, 179,   0, 249,   0, 192, 196, 196, 196, 196, 196, 217,   0, 249,   0, 192, 196, 196, 196, 196, 196, 217,   0, 249,   0, 179},
			{179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179},
			{179,   0, 249,   0, 196, 196, 196, 196, 196, 196, 196,   0, 249,   0, 194,   0, 249,   0, 196, 196, 196, 196, 196, 196, 197, 196, 196, 196, 196, 196, 196,   0, 249,   0, 194,   0, 249,   0, 196, 196, 196, 196, 196, 196, 196,   0, 249,   0, 179},
			{179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179},
			{192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191,   0, 249,   0, 195, 196, 196, 196, 196, 196, 196,   0, 255,   0, 193,   0, 255,   0, 196, 196, 196, 196, 196, 196, 180,   0, 249,   0, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217},
			{255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,   0, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
			{196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217,   0, 249,   0, 193,   0, 255,   0, 218, 196, 196, 196, 196, 180, 255, 195, 196, 196, 196, 196, 191,   0, 255,   0, 193,   0, 249,   0, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196},
			{249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 255, 255, 255,   0, 179, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 179,   0, 255, 255, 255, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249},
			{196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191,   0, 249,   0, 194,   0, 255,   0, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217,   0, 255,   0, 194,   0, 249,   0, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196},
			{255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 179,   0, 249,   0, 179,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255/*!!*/, 255, 255, 255, 255, 255, 255, 255, 255,   0, 179,   0, 249,   0, 179, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
			{218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217,   0, 249,   0, 193,   0, 255,   0, 196, 196, 196, 196, 196, 196, 194, 196, 196, 196, 196, 196, 196,   0, 255,   0, 193,   0, 249,   0, 192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191},	
			{179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179},
			{179,   0, 249,   0, 196, 196, 196, 196, 196, 196, 191,   0, 249,   0, 196, 196, 196, 196, 196, 196, 196,   0, 249,   0, 193,   0, 249,   0, 196, 196, 196, 196, 196, 196, 196,   0, 249,   0, 218, 196, 196, 196, 196, 196, 196,   0, 249,   0, 179},
			{179,   0, 142, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 142,   0, 179},
			{195, 196, 196, 196, 196, 196, 196,   0, 249,   0, 193,   0, 249,   0, 194,   0, 249,   0, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,   0, 249,   0, 194,   0, 249,   0, 193,   0, 249,   0, 196, 196, 196, 196, 196, 196, 180},
			{179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179},
			{179,   0, 249,   0, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196,   0, 249,   0, 194,   0, 249,   0, 196, 196, 196, 196, 196, 196, 193, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196,   0, 249,   0, 179},
			{179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179,   0, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249, 255, 249,   0, 179},
			{192, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 191,   0, 249,   0, 179,   0, 249,   0, 218, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 196, 217}
			};

			int lives=6;

			highscore+=score;
			score=0;

			for (lives; lives>0;)
			{
				SetConsoleColorTextBackground(clWhite, clBlack);

				SetConsoleCursorPosition(37, 28);
				cout<<"HGH SCR: "<<highscore<<endl;

				SetConsoleCursorPosition(13, 28);
				cout<<"LIVES: "<<setw (2)<<lives<<endl;

				SetConsoleCursorPosition(0, 28);
				cout<<"SCORE: "<<score<<endl;

				direction=0;						//текущее направление движения игрока
				tmp_direction=0;					//будующее направление движения поворота игрока

				stop=false;							//обнуляем метку о том что монстр съел игрока

				G.x=24;								//выставляем первоначальные координаты игрока 
				G.y=46;

				P_B_R[0].x=14;						//выставляем первоначальные координаты монстров 
				P_B_R[0].y=24;

				P_B_R[1].x=14;
				P_B_R[1].y=20;

				P_B_R[2].x=14;
				P_B_R[2].y=28;

				Cout_mas (maze);					//выводим массив

				for (int i=0; i<50; i++)			//выводим нижнюю панель
				{
					SetConsoleColorTextBackground(clWhite, clBlack);

					if (i==12 || i==24 || i==36)
					{
						SetConsoleCursorPosition(i, 27);
						printf("%c", 194);
					}
					else
					{
						SetConsoleCursorPosition(i, 27);
						printf("%c", 196);
					}
				}

				for (int i=28; i<30; i++)
				{
					SetConsoleCursorPosition(12, i);
					printf("%c", 179);
					SetConsoleCursorPosition(24, i);
					printf("%c", 179);
					SetConsoleCursorPosition(36, i);
					printf("%c", 179);
				}

				while(stop==false)
				{
					score=0;
					for (int i=0; i<row; i++)
					{
						for (int j=0; j<col; j++)
						{
							if (maze[i][j]==249)
								score+=1;
						}
					}
					score=234-score;

					if (score==234)
					{
						system ("cls");

						SetConsoleCursorPosition(13, 14);
						SetConsoleColorTextBackground(clWhite, clBlack);
						cout<<"YOU HAVE COMPLETED LEVEL!!!"<<endl;
						SetConsoleCursorPosition(13, 15);
						cout<<"YOUR SCORE: "<<score;

						lives=0;
						Sleep (2000);
						stop=true;

						break;
					}

					SetConsoleColorTextBackground(clWhite, clBlack);
					SetConsoleCursorPosition(0, 28);
					cout<<"SCORE: "<<score<<endl;

					Player_G (maze, direction, tmp_direction, G, eat, P_B_R, stop, exit);	//сделал ход

					if (difficulty==1)
					{
						Reset (maze, grid_P, 0, 253, P_B_R, G);						//нашел финишную и старттовую позицию 
						Random_path(maze, stop, grid_P, P_B_R, 0, 80, G, eat);

						if (score>30)
						{
							Reset (maze, grid_B, 1, 252, P_B_R, G);					//нашел финишную и старттовую позицию 1
							Random_path(maze, stop, grid_P, P_B_R, 1, 82, G, eat);	//переместил монстра
						}

						if(score>100)
						{
							Reset (maze, grid_R, 2, 251, P_B_R, G);					//нашел финишную и старттовую позицию 
							Random_path(maze, stop, grid_P, P_B_R, 2, 66, G, eat);	//переместил монстра
						}
					}
					
					else
					{
						if (rand_P.rand==0 && rand_P.norand==0)
						{
							if (difficulty==2)
								rand_P.rand=rand()%25;
							else
								rand_P.rand=rand()%50;
						}

						if (rand_P.rand>0)
						{
							Reset (maze, grid_P, 0, 253, P_B_R, G);				//нашел финишную и старттовую позицию 

							if (eat==false)
								Find_path (maze, stop, grid_P, 80, P_B_R, 0, G, eat);	//переместил монстра
							else 
								Random_path(maze, stop, grid_P, P_B_R, 0, 80, G, eat);

							rand_P.rand--;
						}
						if (rand_P.rand==0 && rand_P.norand==0)
						{
							if (difficulty==2)
								rand_P.norand=rand()%40;
							else
								rand_P.norand=rand()%30;
						}

						if (rand_P.norand>0)
						{	
							Reset (maze, grid_P, 0, 253, P_B_R, G);
							Random_path(maze, stop, grid_P, P_B_R, 0, 80, G, eat);

							rand_P.norand--;
						}

						if (score>30)
						{
							if (rand_B.rand==0 && rand_B.norand==0)
							{
								if (difficulty==2)
									rand_B.rand=rand()%25;
								else
									rand_B.rand=rand()%50;
							}

							if (rand_B.rand>0)
							{
								Reset (maze, grid_B, 1, 252, P_B_R, G);						//нашел финишную и старттовую позицию 1

								if (eat==false)
									Find_path (maze, stop, grid_B, 82, P_B_R, 1, G, eat);		//переместил монстра
								else 
									Random_path(maze, stop, grid_P, P_B_R, 1, 82, G, eat);		//переместил монстра

								rand_B.rand--;
							}
							if (rand_B.rand==0 && rand_B.norand==0)
							{
								if (difficulty==2)
									rand_B.norand=rand()%40;
								else
									rand_B.norand=rand()%30;
							}

							if (rand_B.norand>0)
							{	
								Reset (maze, grid_B, 1, 252, P_B_R, G);				//нашел финишную и старттовую позицию 1
								Random_path(maze, stop, grid_P, P_B_R, 1, 82, G, eat);		//переместил монстра

								rand_B.norand--;
							}
						}

						if(score>100)
						{
							if (rand_R.rand==0 && rand_R.norand==0)
							{
								if (difficulty==2)
									rand_R.rand=rand()%25;
								else
									rand_R.rand=rand()%50;
							}

							if (rand_R.rand>0)
							{
								Reset (maze, grid_R, 2, 251, P_B_R, G);						//нашел финишную и старттовую позицию 

								if (eat==false)
									Find_path (maze, stop, grid_R, 66, P_B_R, 2, G, eat);		//переместил монстра
								else 
									Random_path(maze, stop, grid_P, P_B_R, 2, 66, G, eat);		//переместил монстра

								rand_R.rand--;
							}
							if (rand_R.rand==0 && rand_R.norand==0)
							{
								if (difficulty==2)
									rand_R.norand=rand()%40;
								else
									rand_R.norand=rand()%30;
							}

							if (rand_R.norand>0)
							{	
								Reset (maze, grid_R, 2, 251, P_B_R, G);				//нашел финишную и старттовую позицию 
								Random_path(maze, stop, grid_P, P_B_R, 2, 66, G, eat);		//переместил монстра

								rand_R.norand--;
							}
						}
					}

					if (eat==true)														//если true то можно есть монстров
					{
						SetConsoleColorTextBackground(clWhite, clBlack);
						SetConsoleCursorPosition(25, 28);
						cout<<"POWER: "<<setw (2)<<count<<endl;

						count--;
						if (count==-1)
						{
							SetConsoleCursorPosition(25, 28);
							cout<<"          ";
							count=50;
							eat=false;
						}
					}
				}

				if (exit==true)
				{
					game_over=true;

					count=50;
					eat=false;

					break;
				}

				lives--;														//если игрок стратил отнимаем жизнь

				count=50;
				eat=false;

				if (lives==0)
				{
					game_over=true;
					system ("cls");

					SetConsoleCursorPosition(16, 13);
					SetConsoleColorTextBackground(clWhite, clBlack);
					cout<<"GAME OVER!!!"<<endl;
					SetConsoleCursorPosition(16, 14);
					cout<<"YOUR HIGH SCORE: "<<highscore+score;

					Sleep (2500);

					highscore+=score;

					//----------------------------------------процедура сохранения счета--------------------------------------------

					int pos=-1;
					char buf[10];
					scores tmp[10];

					if (size==0)
					{
						system ("cls");

						SetConsoleCursorPosition(16, 13);
						cout<<"ENTER YOUR NAME";
						SetConsoleCursorPosition(16, 15);
						cout<<"=> ";

						cin.getline (buf, 10);
						strcpy (players[size].name, buf);

						players[size].best_score=highscore;

						size+=1;
					}
					else
					{
						if (size<10)
							size+=1;

						for (int i=0; i<size; i++)					//поиск позиции куда вставить новый рекорд
						{
							if (highscore>=players[i].best_score)
							{
								pos=i;
								break;
							}
						}

						for (int i=0, j=0; j<size; i++)				//сохранение во временый массив нового списка рекордов
						{
							if (pos==i)
							{
								system ("cls");

								SetConsoleCursorPosition(16, 13);
								cout<<"ENTER YOUR NAME";
								SetConsoleCursorPosition(16, 15);
								cout<<"=> ";

								cin.getline (buf, 10);

								strcpy (tmp[j].name, buf);
								tmp[j].best_score=highscore;

								strcpy (tmp[j+1].name, players[i].name);
								tmp[j+1].best_score=players[i].best_score;

								j+=2;
								i+=1;
							}

							if (pos==-1 && j==size-1)
							{
								system ("cls");

								SetConsoleCursorPosition(16, 13);
								cout<<"ENTER YOUR NAME";
								SetConsoleCursorPosition(16, 15);
								cout<<"=> ";

								cin.getline (buf, 10);

								strcpy (tmp[size-1].name, buf);
								tmp[size-1].best_score=highscore;

								break;
							}

							strcpy (tmp[j].name, players[i].name);
							tmp[j].best_score=players[i].best_score;

							j+=1;
						}

						for (int i=0; i<size; i++)					//сохрание нового списка рекордов в структуру
						{
							players[i].best_score=tmp[i].best_score;
							strcpy (players[i].name, tmp[i].name);
						}
					}

					cin.ignore ();

					Save_scores (players, size);

					//------------------------------------------конец-------------------------------------------------
				}
			}
			SetConsoleCursorPosition(0, 29);
		}
	}
}