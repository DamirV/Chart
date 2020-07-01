#include "TPoint.h"
TPoint::TPoint(int _x, int _y)
{
	x = _x;
	y = _y;
	flag = false;
}

void TPoint::Move(Graphics^ gr, int dx, int dy)
{
	x += dx;
	y += dy;
}

void TPoint::Show(Graphics^ gr)
{
	gr->DrawEllipse(Pens::Black, x - 2, y - 2, 4, 4);
	visible = true;
}

void TPoint::Hide(Graphics^ gr)
{
	gr->DrawEllipse(Pens::White, x - 2, y - 2, 4, 4);
	visible = false;
}

int TPoint::GetX()
{
	return x;
}

int TPoint::GetY()
{
	return y;
}
void TPoint::SetX(int dx)
{
	x = dx;
}
void TPoint::SetY(int dy)
{
	y = dy;
}

bool TPoint::GetFlag()
{
	return flag;
}
void TPoint::SetFlag(bool b)
{
	flag = b;
}