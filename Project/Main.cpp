#include "Header.h"

CGAME cg;
bool GameOver = false, moved = false, pause = false;
int difficulty = 2, sound = 1;

void ExitGame(thread *t)
{
	clrscr();
	GameOver = true;
	if (t->joinable())
	{
		t->join();
		if (cg.Win())
		{
			color(10);
			gotoxy(48, 15);
			cout << "__     ______  _    _    __          _______ _   _      _ " << endl;
			gotoxy(48, 16);
			cout << "\\ \\   / / __ \\| |  | |   \\ \\        / /_   _| \\ | |    | |" << endl;
			gotoxy(48, 17);
			cout << " \\ \\_/ / |  | | |  | |    \\ \\  /\\  / /  | | |  \\| |    | |" << endl;
			gotoxy(48, 18);
			cout << "  \\   /| |  | | |  | |     \\ \\/  \\/ /   | | |     |    | |" << endl;
			gotoxy(48, 19);
			cout << "   | | | |__| | |__| |      \\  /\\  /   _| |_| |\\  |    |_|" << endl;
			gotoxy(48, 20);
			cout << "   |_|  \\____/ \\____/        \\/  \\/   |_____|_| \\_|    (_)" << endl;
		}
		else
		{
			color(4);
			gotoxy(44, 15);
			cout << "  _____          __  __ ______      ______      ________ _____  " << endl;
			gotoxy(44, 16);
			cout << " / ____|   /\\   |  \\/  |  ____|    / __ \\ \\    / /  ____|  __ \\ " << endl;
			gotoxy(44, 17);
			cout << "| |  __   /  \\  | \\  / | |__      | |  | \\ \\  / /| |__  | |__) |" << endl;
			gotoxy(44, 18);
			cout << "| | |_ | / /\\ \\ | |\\/| |  __|     | |  | |\\ \\/ / |  __| |  _  / " << endl;
			gotoxy(44, 19);
			cout << "| |__| |/ ____ \\| |  | | |____    | |__| | \\  /  | |____| | \\ \\ " << endl;
			gotoxy(44, 20);
			cout << " \\_____/_/    \\_\\_|  |_|______|    \\____/   \\/   |______|_|  \\_\\" << endl;
		}
		color(7);
		Sleep(1500);
		clrscr();
		if (cg.continueMenu() == 1)
			GameOver = false;
		else 
			GameOver = true;
		cg.Reset();
	}
}

void SubThread()
{
	do
	{
		if (!pause)
		{
			if (moved)
			{
				moved = false;
				cg.clearPeople();
				if (cg.Win() || cg.Lose(sound)) break;
			}
			color(8);
			gotoxy(0, 5);
			for (int i = 0; i < 153; i++) cout << char(196);
			gotoxy(0, 12);
			for (int i = 0; i < 153; i++) cout << char(196);
			gotoxy(7, 19);
			for (int i = 0; i < 146; i++) cout << char(196);
			gotoxy(0, 26);
			for (int i = 0; i < 146; i++) cout << char(196);
			gotoxy(0, 34);
			for (int i = 0; i < 153; i++) cout << char(196);
			color(7);

			if (moved)
			{
				moved = false;
				cg.clearPeople();
				if (cg.Win() || cg.Lose(sound)) break;
			}
			cg.drawPeople();

			cg.update();
			cg.trafficLight();
			if (moved)
			{
				moved = false;
				cg.clearPeople();
				if (cg.Win() || cg.Lose(sound)) break;
			}

			cg.drawBird();
			if (moved)
			{
				moved = false;
				cg.clearPeople();
				if (cg.Win() || cg.Lose(sound)) break;
			}

			cg.drawDinosaur();
			if (moved)
			{
				moved = false;
				cg.clearPeople();
				if (cg.Win() || cg.Lose(sound)) break;
			}

			cg.drawCar();
			if (moved)
			{
				moved = false;
				cg.clearPeople();
				if (cg.Win() || cg.Lose(sound)) break;
			}

			cg.drawTruck();
			if (moved)
			{
				moved = false;
				cg.clearPeople();
				if (cg.Win() || cg.Lose(sound)) break;
			}

			if (cg.Lose(sound)) break;

			cg.drawPeople();
			for (int i = 0; i < 15 - difficulty*5; i++)
			{
				Sleep(20);
				if (moved)
				{
					moved = false;
					cg.clearPeople();
					if (cg.Win() || cg.Lose(sound)) break;
				}
			}
		}
	} while (!GameOver);
	cg.drawPeople();
	GameOver = true;
}

int main()
{
	FixConsoleWindow();

	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1500, 860, TRUE);
	noCursorType();
	
	//thread tM(musicOpening);
	int c;
	do
	{
		GameOver = false;
		c = cg.menu();
		if (c == 2)
		{
			GameOver = false;
			cg.loadGame();
		}
		if (c == 1 || c == 2)
		{
			do
			{
				if (c != 2) cg.newGame();
				cg.loading();
				cg.info();
				thread t(SubThread);
				while (!GameOver)
				{
					if (!moved)
					{
						char move = toupper(_getch());
						switch (move)
						{
						case UP: case DOWN: case LEFT: case RIGHT:
							if (pause) pause = false;
							else
							{
								cg.updatePeople(move);
								moved = true;
							}
							break;
						case 'P':
							pause = !pause;
							break;
						case 'L':
							pause = true;
							Sleep(300);
							cg.saveGame();
							break;
						case 'T':
							pause = true;
							Sleep(300);
							cg.loadGame();
							break;
						}
					}
				}
				if (GameOver) ExitGame(&t);
			} while (!GameOver);
		}
		else if (c == 3)
			cg.settings(difficulty, sound);
		else if (c == 4)
			cg.quitGame();
	} while (GameOver || c == 3);
	return 0;
}