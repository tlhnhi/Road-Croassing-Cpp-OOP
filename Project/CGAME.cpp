#include "Header.h"

void updateMenu(int step)
{
	switch (step)
	{
	case 1:
		gotoxy(69, 12);
		cout << char(218);
		for (int i = 0; i < 14; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(69, 13);
		cout << char(179) << "   NEW GAME   " << char(179) << endl;
		gotoxy(69, 14);
		cout << char(192);
		for (int i = 0; i < 14; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	case 2:
		gotoxy(69, 15);
		cout << char(218);
		for (int i = 0; i < 14; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(69, 16);
		cout << char(179) << "   LOAD GAME  " << char(179) << endl;
		gotoxy(69, 17);
		cout << char(192);
		for (int i = 0; i < 14; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	case 3:
		gotoxy(69, 18);
		cout << char(218);
		for (int i = 0; i < 14; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(69, 19);
		cout << char(179) << "   SETTINGS   " << char(179) << endl;
		gotoxy(69, 20);
		cout << char(192);
		for (int i = 0; i < 14; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	case 4:
		gotoxy(69, 21);
		cout << char(218);
		for (int i = 0; i < 14; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(69, 22);
		cout << char(179) << "   QUIT GAME  " << char(179) << endl;
		gotoxy(69, 23);
		cout << char(192);
		for (int i = 0; i < 14; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	}
}
int CGAME::menu()
{
	color(13);
	gotoxy(31, 5);
	cout << "______________________________     __________________________________________________   _________" << endl;
	gotoxy(31, 6);
	cout << "___ __  \\_  __ \\__    |__  __ \\    __  ____/__ __  \\_  __ \\_  ___ / _ ___/___  _/ __ | / /_ ____/" << endl;
	gotoxy(31, 7);
	cout << "__ /_/  /  / / /_  /| |_  / / /    _  /    __ /_/  /  / / /____ \\_____ \\  __  / __   |/ /_ / __" << endl;
	gotoxy(31, 8);
	cout << "_  _, _// /_/ /_  ___ |  /_/ /     / /___  _  _, _// /_/ /____/ /____/ / __/ /  _  /|  // /_/ / " << endl;
	gotoxy(31, 9);
	cout << "/_/ |_| \\____/ /_/  |_/_____/      \\____/  /_/ |_| \\____/ /____/ /____/ /____/  /_/ |_/ \\____/" << endl;

	updateMenu(1);
	color(8);
	updateMenu(2);
	updateMenu(3);
	updateMenu(4);

	int step = 1;
	bool stop = false;
	do
	{
		char move = toupper(_getch());
		switch (move)
		{
		case UP:
			color(8);
			updateMenu(step);
			color(13);
			step--;
			if (!step) step = 4;
			updateMenu(step);
			break;
		case DOWN:
			color(8);
			updateMenu(step);
			color(13);
			step++;
			if (step > 4) step = 1;
			updateMenu(step);
			break;
		case OK:
			clrscr();
			stop = true;
			break;
		}
	} while (!stop);
	color(7);
	return step;
}

void updateContinueMenu(int step)
{
	switch (step)
	{
	case 1:
		gotoxy(64, 17);
		cout << char(218);
		for (int i = 0; i < 9; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(64, 18); 
		cout << char(179) << "    NO   " << char(179) << endl;
		gotoxy(64, 19);
		cout << char(192);
		for (int i = 0; i < 9; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	case 2:
		gotoxy(77, 17);
		cout << char(218);
		for (int i = 0; i < 9; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(77, 18);
		cout << char(179) << "    NO   " << char(179) << endl;
		gotoxy(77, 19);
		cout << char(192);
		for (int i = 0; i < 9; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	}
}
int CGAME::continueMenu()
{
	color(15);
	gotoxy(64, 15);
	cout << "Do you want to continue?" << endl;
	color(13);
	updateContinueMenu(1);
	color(8);
	updateContinueMenu(2);

	int step = 1;
	bool stop = false;
	do
	{
		char move = toupper(_getch());
		switch (move)
		{
		case LEFT:
			color(8);
			updateContinueMenu(step);
			color(13);
			step--;
			if (!step) step = 2;
			updateContinueMenu(step);
			break;
		case RIGHT:
			color(8);
			updateContinueMenu(step);
			color(13);
			step++;
			if (step > 2) step = 1;
			updateContinueMenu(step);
			break;
		case OK:
			clrscr();
			stop = true;
			break;
		}
	} while (!stop);
	color(7);
	return step;
}

CGAME::CGAME()
{
	cb = NULL;
	cd = NULL;
	cc = NULL;
	ct = NULL;
	level = 3;
}
CGAME::~CGAME()
{
	delete[] cb;
	delete[] cd;
	delete[] cc;
	delete[] ct;
}

void CGAME::loading()
{
	gotoxy(72, 15);
	cout << "LOADING...";
	gotoxy(67, 16);
	cout << char(218);
	for (int i = 0; i < 17; i++) cout << char(196);
	cout << char(191);
	gotoxy(67, 17);
	cout << char(179);
	gotoxy(85, 17);
	cout << char(179);
	gotoxy(67, 18);
	cout << char(192);
	for (int i = 0; i < 17; i++) cout << char(196);
	cout << char(217) << endl;
	gotoxy(68, 17);
	color(11);
	for (int i = 0; i < 17; i++)
	{
		cout << char(219);
		Sleep(70);
	}
	clrscr();
}

void CGAME::newGame()
{
	if (cb) delete[] cb;
	cb = new CBIRD[level];
	if (cd) delete[] cd;
	cd = new CDINOSAUR[level];
	if (cc) delete[] cc;
	cc = new CCAR[level];
	if (ct) delete[] ct;
	ct = new CTRUCK[level];
	pc = pt = 0;

	for (int i = 1; i < level; i++)
	{
		cb[i].updatePos(cb[i - 1].getmX() + (180 / level));
		cd[i].updatePos(cd[i - 1].getmX() + (180 / level));
		cc[i].updatePos(cc[i - 1].getmX() + (180 / level));
		ct[i].updatePos(ct[i - 1].getmX() + (180 / level));
	}
}
void CGAME::info()
{
	gotoxy(0,0);
	cout << "Level: " << level - 2 << endl;
	cout << "Press 'P' to Pause." << endl;
	cout << "Press 'L' to Save." << endl;
	cout << "Press 'T' to Load." << endl;
}

void CGAME::update()
{
	cb[0].updatePos((cb[0].getmX() - 3) + (180 / level) * (cb[0].getmX() <= -16));
	cd[0].updatePos((cd[0].getmX() + 2) - (180 / level) * (cd[0].getmX() >= (180 / level) - 20));
	if (pc >= 0) cc[0].updatePos((cc[0].getmX() - 2) + (180 / level) * (cc[0].getmX() <= -22));
	if (pt >= 0) ct[0].updatePos((ct[0].getmX() + 1) - (180 / level) * (ct[0].getmX() >= (180 / level) - 22));
	pc++;
	if (pc == 30) pc = -20;
	pt++;
	if (pt == 40) pt = -20;
	for (int i = 1; i < level; i++)
	{ 
		cb[i].updatePos(cb[i - 1].getmX() + (180 / level));
		cd[i].updatePos(cd[i - 1].getmX() + (180 / level));
		cc[i].updatePos(cc[i - 1].getmX() + (180 / level));
		ct[i].updatePos(ct[i - 1].getmX() + (180 / level));
	}
}
void CGAME::drawBird()
{
	for (int i = 0; i < level; i++) cb[i].move();
}
void CGAME::drawDinosaur()
{
	for (int i = 0; i < level; i++) cd[i].move();
}
void CGAME::drawCar()
{
	for (int i = 0; i < level; i++) cc[i].move();
}
void CGAME::drawTruck()
{
	for (int i = 0; i < level; i++) ct[i].move();
}

void CGAME::updatePeople(const int &move)
{
	switch (move)
	{
	case UP:
		cp.updatePos(cp.getX(), cp.getY() - 1);
		break;
	case DOWN:
		cp.updatePos(cp.getX(), cp.getY() + 1);
		break;
	case LEFT:
		cp.updatePos(cp.getX() - 1, cp.getY());
		break;
	case RIGHT:
		cp.updatePos(cp.getX() + 1, cp.getY());
		break;
	}
}
void CGAME::clearPeople()
{
	cp.clear();
}
void CGAME::drawPeople()
{
	cp.drawPeople();
}

void CGAME::Reset()
{
	level = 3;
	newGame();
	cp.updatePos(76, 35);
	clrscr();
}

bool CGAME::Win()
{
	if (cp.getY() < 3)
		if (level == 6) return true;
		else
		{
			level++;
			newGame();
			Sleep(300);
			cp.updatePos(76, 35);
			clrscr();
			info();
		}
	return false;
}
bool CGAME::Lose(const int &sound)
{
	if (cp.getY() < 12 && cp.getY() > 3)
		for (int i = 0; i < level; i++)
			if (cp.getX() > cb[i].getmX() - 4 && cp.getX() < cb[i].getmX() + 18)
				if (cp.isImpact(sound, &cb[i])) return true;
	if (cp.getY() < 19 && cp.getY() > 9)
		for (int i = 0; i < level; i++)
			if (cp.getX() > cd[i].getmX() - 4 && cp.getX() < cd[i].getmX() + 22)
				if (cp.isImpact(sound, &cd[i])) return true;
	if (cp.getY() < 26 && cp.getY() > 17)
		for (int i = 0; i < level; i++)
			if (cp.getX() > cc[i].getmX() - 4 && cp.getX() < cc[i].getmX() + 24)
				if (cp.isImpact(sound, &cc[i])) return true;
	if (cp.getY() < 34 && cp.getY() > 24)
		for (int i = 0; i < level; i++)
			if (cp.getX() > ct[i].getmX() - 4 && cp.getX() < ct[i].getmX() + 24)
				if (cp.isImpact(sound, &ct[i])) return true;
	return false;
}

void drawTrafficLight(int x, int y, bool red)
{
	gotoxy(x, y);
	color(6);
	cout << char(218);
	for (int i = 0; i < 5; i++) cout << char(196);
	cout << char(191) << endl;
	gotoxy(x, y+1);
	cout << char(179) << " ";
	if (red)
	{
		color(4);
		cout << char(178) << " ";
		color(8);
		cout << char(178) << " ";
		color(6);
		cout << char(179) << endl;
	}
	else
	{
		color(8);
		cout << char(178) << " ";
		color(10);
		cout << char(178) << " ";
		color(6);
		cout << char(179) << endl;
	}
	gotoxy(x, y+2);
	cout << char(192);
	for (int i = 0; i < 5; i++) cout << char(196);
	cout << char(217) << endl;
	color(8);
}
void CGAME::trafficLight()
{
	drawTrafficLight(0, 19, (pc < 0));
	drawTrafficLight(146, 26, (pt < 0));
}

string getPath()
{
	gotoxy(47, 13);
	cout << char(218);
	for (int i = 0; i < 60; i++) cout << char(196);
	cout << char(191) << endl;
	gotoxy(47, 14);
	cout << char(179) << "File name (*.rcr):                                          " << char(179) << endl;
	gotoxy(47, 15);
	cout << char(179) << char(218);
	for (int i = 0; i < 58; i++) cout << char(196);
	cout << char(191);
	cout << char(179) << endl;
	gotoxy(47, 16);
	cout << char(179) << char(179);
	for (int i = 0; i < 58; i++) cout << " ";
	cout << char(179) << char(179) << endl;
	gotoxy(47, 17);
	cout << char(179) << char(192);
	for (int i = 0; i < 58; i++) cout << char(196);
	cout << char(217) << char(179) << endl;
	gotoxy(47, 18);
	cout << char(192);
	for (int i = 0; i < 60; i++) cout << char(196);
	cout << char(217) << endl;
	string path;
	color(3);
	gotoxy(50, 16);
	getline(cin, path);
	if (path == "") getline(cin, path);
	color(7);
	return path;
}
void CGAME::reloadGame()
{
	clrscr();
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
	info();
	drawBird();
	drawDinosaur();
	drawCar();
	drawTruck();
	trafficLight();
	drawPeople();
}
void CGAME::loadGame()
{
	string path = getPath();
	if (path.find(".rcr") == string::npos) path += ".rcr";
	ifstream fin;
	fin.open(path, ios::binary);
	if (!fin.is_open())
	{
		clrscr();
		gotoxy(60, 16);
		cout << "Cannot open file!";
		Sleep(1000);
	}
	else
	{
		int temp1, temp2;
		fin >> temp1 >> temp2 >> level;
		cp.updatePos(temp1, temp2);
		if (cb) delete[] cb;
		cb = new CBIRD[level];
		if (cd) delete[] cd;
		cd = new CDINOSAUR[level];
		if (cc) delete[] cc;
		cc = new CCAR[level];
		if (ct) delete[] ct;
		ct = new CTRUCK[level];
		fin >> pc >> pt;
		fin >> temp1 >> temp2;
		cb[0].updatePos(temp1);
		cd[0].updatePos(temp2);
		fin >> temp1 >> temp2;
		cc[0].updatePos(temp1);
		ct[0].updatePos(temp2);
		for (int i = 1; i < level; i++)
		{
			cb[i].updatePos(cb[i - 1].getmX() + (180 / level));
			cd[i].updatePos(cd[i - 1].getmX() + (180 / level));
			cc[i].updatePos(cc[i - 1].getmX() + (180 / level));
			ct[i].updatePos(ct[i - 1].getmX() + (180 / level));
		}
		fin.close();
	}
	reloadGame();
}
void CGAME::saveGame()
{
	string path = getPath();
	if (path.find(".rcr") == string::npos) path += ".rcr";
	ofstream fout;
	fout.open(path, ios::binary);
	if (!fout.is_open())
	{
		clrscr();
		cout << "Cannot open file!";
		Sleep(1000);
	}
	else
	{
		fout << cp.getX() << " " << cp.getY() << " " << level << endl;
		fout << pc << " " << pt << endl;
		fout << cb[0].getmX() << " " << cd[0].getmX() << " " << cc[0].getmX() << " " << ct[0].getmX();
		fout.close();
	}
	clrscr();
	if (continueMenu() == 1)
		reloadGame();
	else exit(0);
}

void updateDifficulty(int step)
{
	switch (step)
	{
	case 1:
		gotoxy(76, 15);
		cout << char(218);
		for (int i = 0; i < 10; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(76, 16);
		cout << char(179) << "   EASY   " << char(179) << endl;
		gotoxy(76, 17);
		cout << char(192);
		for (int i = 0; i < 10; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	case 2:
		gotoxy(76, 15);
		cout << char(218);
		for (int i = 0; i < 10; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(76, 16);
		cout << char(179) << "  MEDIUM  " << char(179) << endl;
		gotoxy(76, 17);
		cout << char(192);
		for (int i = 0; i < 10; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	case 3:
		gotoxy(76, 15);
		cout << char(218);
		for (int i = 0; i < 10; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(76, 16);
		cout << char(179) << "   HARD   " << char(179) << endl;
		gotoxy(76, 17);
		cout << char(192);
		for (int i = 0; i < 10; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	}
}
void updateSound(int step)
{
	switch (step)
	{
	case 1:
		gotoxy(76, 19);
		cout << char(218);
		for (int i = 0; i < 10; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(76, 20);
		cout << char(179) << "    ON    " << char(179) << endl;
		gotoxy(76, 21);
		cout << char(192);
		for (int i = 0; i < 10; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	case 2:
		gotoxy(76, 19);
		cout << char(218);
		for (int i = 0; i < 10; i++) cout << char(196);
		cout << char(191) << endl;
		gotoxy(76, 20);
		cout << char(179) << "    OFF   " << char(179) << endl;
		gotoxy(76, 21);
		cout << char(192);
		for (int i = 0; i < 10; i++) cout << char(196);
		cout << char(217) << endl;
		break;
	}
}
void updateSettings(int step)
{
	switch (step)
	{
	case 1:
		gotoxy(62, 16);
		cout << "DIFFICULTY: <";
		gotoxy(89, 16);
		cout << ">";
		break;
	case 2:
		gotoxy(64, 20);
		cout << "SOUND:    <";
		gotoxy(89, 20);
		cout << ">";
		break;
	}
}
void CGAME::settings(int &d, int &s)
{
	color(13);
	updateSettings(1);
	color(8);
	updateSettings(2);

	color(11);
	int step = 1;
	updateDifficulty(d);
	updateSound(s);
	bool stop = false;
	do
	{
		char move = toupper(_getch());
		switch (move)
		{
		case UP:
			color(8);
			updateSettings(step);
			color(13);
			step--;
			if (!step) step = 2;
			updateSettings(step);
			break;
		case DOWN:
			color(8);
			updateSettings(step);
			color(13);
			step++;
			if (step > 2) step = 1;
			updateSettings(step);
			break;
		case LEFT:
			color(11);
			if (step == 1)
			{
				d--;
				if (!d) d = 3;
				updateDifficulty(d);
			}
			if (step == 2)
			{
				s--;
				if (!s) s = 2;
				updateSound(s);
			}
			break;
		case RIGHT:
			color(11);
			if (step == 1)
			{
				d++;
				if (d > 3) d = 1;
				updateDifficulty(d);
			}
			if (step == 2)
			{
				s++;
				if (s > 2) s = 1;
				updateSound(s);
			}
			break;
		case OK:
			clrscr();
			stop = true;
			break;
		}
	} while (!stop);
	color(7);
}

void CGAME::quitGame()
{
	exit(0);
}