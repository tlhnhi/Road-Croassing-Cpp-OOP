#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include <thread>
#include <fstream>
#include <mmsystem.h>

using namespace std;

#define UP   87  // W
#define DOWN  83  // S
#define LEFT   65   // A
#define RIGHT   68  // D
#define OK   13   // enter

void color(int color);
void gotoxy(int x, int y);
void FixConsoleWindow();
void noCursorType();
void clrscr();

class CVEHICLE
{
public:
	virtual void move() = 0;
	virtual void updatePos(int mx) = 0;
	int getmX() { return mX; }
	int getmY() { return mY; }
	void crash();
protected:
	int mX, mY;
};

class CANIMAL
{
public:
	virtual void move() = 0;
	virtual void updatePos(int mx) = 0;
	int getmX() { return mX; }
	int getmY() { return mY; }
	virtual void talk() = 0;
protected:
	int mX, mY;
};

class CCAR : public CVEHICLE
{
public:
	CCAR() { mX = -23; mY = 22; }
	void move() { drawCar(mX, mY); }
	void updatePos(int mx) { mX = (mx >= -23) ? mx : (mx + 179); }
private:
	void drawCar(int, int);
};

class CTRUCK : public CVEHICLE
{
public:
	CTRUCK() { mX = -23; mY = 29; }
	void move() { drawTruck(mX, mY); }
	void updatePos(int mx) { mX = (mx >= -23) ? mx : (mx + 179); }
private:
	void drawTruck(int, int);
};

class CDINOSAUR : public CANIMAL
{
public:
	CDINOSAUR() { mX = -20; mY = 13; }
	void move() { drawDinosaur(mX, mY); }
	void updatePos(int mx) { mX = (mx >= -20) ? mx : (mx + 179); }
	void talk();
private:
	void drawDinosaur(int, int);
};

class CBIRD : public CANIMAL
{
public:
	CBIRD() { mX = -16; mY = 6; }
	void move() { drawBird(mX, mY); }
	void updatePos(int mx) { mX = (mx >= -16) ? mx : (mx + 179); }
	void talk();
private:
	void drawBird(int, int);
};

class CPEOPLE
{
public:
	void drawPeople();
	void clear();
	void updatePos(int mx, int my);
	int getX() { return mX; }
	int getY() { return mY; }
	bool isImpact(const int &sound, CCAR* cc);
	bool isImpact(const int &sound, CTRUCK* ct);
	bool isImpact(const int &sound, CDINOSAUR* cd);
	bool isImpact(const int &sound, CBIRD* cb);
private:
	int mX = 76, mY = 35;
	bool state = true;
};

class CGAME
{
public:
	CGAME();
	~CGAME();
	int menu();
	int continueMenu();
	void loading();
	void newGame();
	void info();
	void update();
	void drawBird();
	void drawDinosaur();
	void drawCar();
	void drawTruck();
	void updatePeople(const int &move);
	void clearPeople();
	void drawPeople();
	void Reset();
	bool Win();
	bool Lose(const int &sound);
	int getLevel() { return level; }
	void trafficLight();
	void loadGame();
	void reloadGame();
	void saveGame();
	void settings(int &d, int &s);
	void quitGame();
private:
	CPEOPLE cp;
	CBIRD *cb;
	CDINOSAUR *cd;
	CCAR *cc;
	CTRUCK *ct;
	int level, pc, pt;
};

void musicOpening();