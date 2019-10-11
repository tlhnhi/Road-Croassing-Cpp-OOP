#include "Header.h"

void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void noCursorType()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE hConsoleOut;
	COORD Home = { 0, 0 };
	DWORD dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void CCAR::drawCar(int x, int y)
{
	color(12);
	string str = "       ________        ";
	if (x > 0)
	{
		gotoxy(x, y);
		if (x < 153) if (x > 131) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y);
		cout << str.substr(-x) << endl;
	}

	str = " _____//__||_\\ \\____   ";
	if (x > 0)
	{
		gotoxy(x, y + 1);
		if (x < 153) if (x > 131) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 1);
		cout << str.substr(-x) << endl;
	}

	str = " )__ __ _______ __ _\\  ";
	if (x > 0)
	{
		gotoxy(x, y + 2);
		if (x < 153) if (x > 131) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 2);
		cout << str.substr(-x) << endl;
	}

	str = "    (__)       (__)    ";
	if (x > 0)
	{
		gotoxy(x, y + 3);
		if (x < 153) if (x > 131) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 3);
		cout << str.substr(-x) << endl;
	}
	color(7);
}
void CTRUCK::drawTruck(int x, int y)
{
	color(9);
	string str = "  __________           ";
	if (x > 0)
	{
		gotoxy(x, y);
		if (x < 153) if (x > 130) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y);
		cout << str.substr(-x) << endl;
	}

	str = " |          |_____     ";
	if (x > 0)
	{
		gotoxy(x, y + 1);
		if (x < 153) if (x > 130) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 1);
		cout << str.substr(-x) << endl;
	}

	str = " |   __     | |__\\\\__  ";
	if (x > 0)
	{
		gotoxy(x, y + 2);
		if (x < 153) if (x > 130) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 2);
		cout << str.substr(-x) << endl;
	}

	str = " |__/  \\____|__ __ _(  ";
	if (x > 0)
	{
		gotoxy(x, y + 3);
		if (x < 153) if (x > 130) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 3);
		cout << str.substr(-x) << endl;
	}

	str = "    \\__/       (__)    ";
	if (x > 0)
	{
		gotoxy(x, y + 4);
		if (x < 153) if (x > 130) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 4);
		cout << str.substr(-x) << endl;
	}
	color(7);
}
void CDINOSAUR::drawDinosaur(int x, int y)
{
	color(10);
	string str = "                 __  ";
	if (x > 0)
	{
		gotoxy(x, y);
		if (x < 153) if (x > 133) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y);
		cout << str.substr(-x) << endl;
	}

	str = "                /._) ";
	if (x > 0)
	{
		gotoxy(x, y + 1);
		if (x < 153) if (x > 133) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 1);
		cout << str.substr(-x) << endl;
	}

	str = "       _ ---- _/ /   ";
	if (x > 0)
	{
		gotoxy(x, y + 2);
		if (x < 153) if (x > 133) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 2);
		cout << str.substr(-x) << endl;
	}

	str = "      /         /    ";
	if (x > 0)
	{
		gotoxy(x, y + 3);
		if (x < 153) if (x > 133) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 3);
		cout << str.substr(-x) << endl;
	}

	str = "   __/ (  | (  |     ";
	if (x > 0)
	{
		gotoxy(x, y + 4);
		if (x < 153) if (x > 133) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 4);
		cout << str.substr(-x) << endl;
	}

	str = "  /--   |_|  |_|     ";
	if (x > 0)
	{
		gotoxy(x, y + 5);
		if (x < 153) if (x > 133) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 5);
		cout << str.substr(-x) << endl;
	}
	color(7);
}
void CBIRD::drawBird(int x, int y)
{
	color(15);
	string str = "   ___  ______   ";
	if (x > 0)
	{
		gotoxy(x, y);
		if (x < 153) if (x > 138) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y);
		cout << str.substr(-x) << endl;
	}

	str = "   _\\~\\/   ~/   ";
	if (x > 0)
	{
		gotoxy(x, y + 1);
		if (x < 153) if (x > 138) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 1);
		cout << str.substr(-x) << endl;
	}

	str = " <(.\\_/  ~/     ";
	if (x > 0)
	{
		gotoxy(x, y + 2);
		if (x < 153) if (x > 138) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 2);
		cout << str.substr(-x) << endl;
	}

	str = "   \\____/=*     ";
	if (x > 0)
	{
		gotoxy(x, y + 3);
		if (x < 153) if (x > 138) cout << str.substr(0, 152 - x + 1) << endl;
		else cout << str << endl;
	}
	else
	{
		gotoxy(0, y + 3);
		cout << str.substr(-x) << endl;
	}
}

void musicOpening()
{
	PlaySound(TEXT("Test.wav"), NULL, SND_LOOP);
}
void CVEHICLE::crash()
{
	PlaySound(TEXT("CVEHICLE.wav"), NULL, SND_SYNC);
}
void CDINOSAUR::talk()
{
	PlaySound(TEXT("CDINOSAUR.wav"), NULL, SND_SYNC);
}
void CBIRD::talk() 
{ 
	PlaySound(TEXT("CBIRD.wav"), NULL, SND_SYNC);
}