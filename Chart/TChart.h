#pragma once

#include "TRoot.h"
#include "TPoint.h"
#include <string.h>

class TPoint;
class TChart;

struct TChartLine
{
	TChart *tc;
	TPoint *tf, *tl;
};

class TChart : public TRoot
{
private:
	bool fat;
	TStack<TChartLine> stc;

protected:
	TRoot *pFirst, *pLast;

public:
	TChart();
	void SetFirst(TRoot *p);
	void SetLast(TRoot *p);
	TRoot* Show(Graphics ^gr, TRoot *p);
	void Show(Graphics^ gr);
	void Hide(Graphics^ gr);
	void Move(Graphics^ gr, int dx, int dy);
	TChartLine Find(int _x, int _y);
	void FlagOfPoint();
	void Click(Graphics^ gr, int dx, int dy);
	void HideFatLines(Graphics^ gr);
};