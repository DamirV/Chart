#pragma once
#include "TRoot.h"
using namespace System::Drawing;

class TPoint : public TRoot
{
protected:
	int x, y;
	bool flag;

public:
	TPoint(int _x, int _y);
	void Show(Graphics^ gr);
	void Hide(Graphics^ gr);
	void Move(Graphics^ gr, int dx, int dy);
	int GetX();
	int GetY();
	void SetX(int dx);
	void SetY(int dy);
	bool GetFlag();
	void SetFlag(bool b);
};