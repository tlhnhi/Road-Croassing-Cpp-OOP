#include "Header.h"

void CPEOPLE::drawPeople()
{
	color(14);
	gotoxy(mX, mY);
	cout << "_O_";
	gotoxy(mX + 1, mY + 1);
	cout << char(219);
	gotoxy(mX, mY + 2);
	cout << "/ \\";
	color(7);
}
void CPEOPLE::clear()
{
	color(14);
	gotoxy(mX - 1, mY - 1);
	cout << "     ";
	gotoxy(mX - 1, mY);
	cout << " _O_ ";
	gotoxy(mX - 1, mY + 1);
	cout << "  " << char(219) << "  ";
	gotoxy(mX - 1, mY + 2);
	cout << " / \\ ";
	gotoxy(mX - 1, mY + 3);
	cout << "     ";
	color(7);
}
void CPEOPLE::updatePos(int mx, int my)
{
	if (mx > 6 && mx < 144) mX = mx;
	if (my > 0 && my < 36) mY = my;
}

bool impact(int tlX1, int tlY1, int brX1, int brY1, int tlX2, int tlY2, int brX2, int brY2)
{
	if (((tlX1 >= tlX2) && (tlX1 <= brX2) && (tlY1 >= tlY2) && (tlY1 <= brY2))
		|| ((tlX2 >= tlX1) && (tlX2 <= brX1) && (tlY2 >= tlY1) && (tlY2 <= brY1))
		|| ((tlX1 >= tlX2) && (tlX1 <= brX2) && (brY1 >= tlY2) && (brY1 <= brY2))
		|| ((tlX2 >= tlX1) && (tlX2 <= brX1) && (brY2 >= tlY1) && (brY2 <= brY1)))
		return true;
	return false;
}
bool CPEOPLE::isImpact(const int &sound, CCAR* cc)
{
	if ((impact(mX, mY, mX + 2, mY + 2, cc->getmX() + 6, cc->getmY() + 1, cc->getmX() + 14, cc->getmY() + 1))
		|| (impact(mX, mY, mX + 2, mY + 2, cc->getmX() + 1, cc->getmY() + 2, cc->getmX() + 20, cc->getmY() + 2))
		|| (impact(mX, mY, mX + 2, mY + 2, cc->getmX() + 4, cc->getmY() + 3, cc->getmX() + 7, cc->getmY() + 3))
		|| (impact(mX, mY, mX + 2, mY + 2, cc->getmX() + 15, cc->getmY() + 3, cc->getmX() + 18, cc->getmY() + 3)))
	{
		if (sound == 1) cc->crash();
		return true;
	}
	return false;
}
bool CPEOPLE::isImpact(const int &sound, CTRUCK* ct)
{
	if ((impact(mX, mY, mX + 2, mY + 2, ct->getmX() + 1, ct->getmY() + 1, ct->getmX() + 13, ct->getmY() + 1))
		|| (impact(mX, mY, mX + 2, mY + 2, ct->getmX() + 1, ct->getmY() + 2, ct->getmX() + 19, ct->getmY() + 2))
		|| (impact(mX, mY, mX + 2, mY + 2, ct->getmX() + 1, ct->getmY() + 3, ct->getmX() + 20, ct->getmY() + 3))
		|| (impact(mX, mY, mX + 2, mY + 2, ct->getmX() + 4, ct->getmY() + 4, ct->getmX() + 7, ct->getmY() + 4))
		|| (impact(mX, mY, mX + 2, mY + 2, ct->getmX() + 15, ct->getmY() + 4, ct->getmX() + 18, ct->getmY() + 4)))
	{
		if (sound == 1) ct->crash();
		return true;
	}
	return false;
}
bool CPEOPLE::isImpact(const int &sound, CDINOSAUR* cd)
{
	if ((impact(mX, mY, mX + 2, mY + 2, cd->getmX() + 16, cd->getmY() + 1, cd->getmX() + 19, cd->getmY() + 1))
		|| (impact(mX, mY, mX + 2, mY + 2, cd->getmX() + 15, cd->getmY() + 2, cd->getmX() + 17, cd->getmY() + 2))
		|| (impact(mX, mY, mX + 2, mY + 2, cd->getmX() + 6, cd->getmY() + 3, cd->getmX() + 16, cd->getmY() + 3))
		|| (impact(mX, mY, mX + 2, mY + 2, cd->getmX() + 3, cd->getmY() + 4, cd->getmX() + 15, cd->getmY() + 4))
		|| (impact(mX, mY, mX + 2, mY + 2, cd->getmX() + 2, cd->getmY() + 5, cd->getmX() + 15, cd->getmY() + 5)))
	{
		if (sound == 1) cd->talk();
		return true;
	}
	return false;
}
bool CPEOPLE::isImpact(const int &sound, CBIRD* cb)
{
	if ((impact(mX, mY, mX + 2, mY + 2, cb->getmX() + 3, cb->getmY() + 1, cb->getmX() + 13, cb->getmY() + 1))
		|| (impact(mX, mY, mX + 2, mY + 2, cb->getmX() + 1, cb->getmY() + 2, cb->getmX() + 10, cb->getmY() + 2))
		|| (impact(mX, mY, mX + 2, mY + 2, cb->getmX() + 3, cb->getmY() + 3, cb->getmX() + 10, cb->getmY() + 3)))
	{ 
		if (sound == 1) cb->talk();
		return true;
	} 
	return false;
}
