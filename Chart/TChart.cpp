#include "TChart.h"

TChart::TChart()
{
	pFirst = pLast = NULL;
	fat = false;
}

void TChart::SetFirst(TRoot *p)
{
	TPoint *tp = dynamic_cast<TPoint *>(p);
	if (tp == NULL)
	{
		TChart *tc = dynamic_cast<TChart *>(p);
		if (tc != NULL)
		{
			pFirst = tc;
		}
	}
	else
	{
		pFirst = tp;
	}
}

void TChart::SetLast(TRoot *p)
{
	TPoint *tp = dynamic_cast<TPoint *>(p);
	if (tp == NULL)
	{
		TChart *tc = dynamic_cast<TChart *>(p);
		if (tc != NULL)
		{
			pLast = tc;
		}
	}
	else
	{
		pLast = tp;
	}
}

void TChart::Click(Graphics^ gr, int dx, int dy)
{
	Pen^ penBlack = gcnew Pen(Color:: Black, 5.0f);
	Pen^ penWhite = gcnew Pen(Color::White, 5.0f);
	TRoot *tmp;
	TPoint *tp;
	TChartLine curr;
	TStack<TChartLine> stack;
	curr.tc = this;
	curr.tf = curr.tl = NULL;

	stack.Clr();
	stack.Push(curr);

	while (!stack.IsEmpty())
	{
		curr = stack.Pop();

		while (curr.tf == NULL)
		{
			tmp = curr.tc->pFirst;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tf = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
			}
		}

		if (curr.tl == NULL)
		{
			tmp = curr.tc->pLast;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tl = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
				curr.tf = NULL;
				stack.Push(curr);
			}
		}

		if (curr.tf&&curr.tl)
		{
			if ((abs((curr.tf->GetX() + curr.tl->GetX()) / 2 - dx) <= 20) && (abs((curr.tf->GetY() + curr.tl->GetY()) / 2 - dy) <= 20))
			{
				if (curr.tc->fat)
				{
					curr.tc->fat = false;
					gr->DrawLine(penWhite, curr.tf->GetX(), curr.tf->GetY(), curr.tl->GetX(), curr.tl->GetY());
					return;
				}
				curr.tc->fat = true;
				gr->DrawLine(penBlack, curr.tf->GetX(), curr.tf->GetY(), curr.tl->GetX(), curr.tl->GetY());
				return;
			}


			tp = curr.tl;
			if (!stack.IsEmpty())
			{
				curr = stack.Pop();
				if (curr.tf == NULL)
				{
					curr.tf = tp;
				}
				else
				{
					curr.tl = tp;
				}
				stack.Push(curr);
			}
		}
	}
}

TRoot* TChart::Show(Graphics ^gr, TRoot *p)
{
	TPoint *pointF, *pointL;
	TChart *tc;
	pointF = dynamic_cast<TPoint*>(p);
	if (pointF != NULL)
	{
		return p;
	}
	else
	{
		tc = dynamic_cast<TChart*>(p);
		pointF = dynamic_cast<TPoint*>(Show(gr, tc->pFirst));
		pointL = dynamic_cast<TPoint*>(Show(gr, tc->pLast));
		gr->DrawLine(Pens::Black, pointF->GetX(), pointF->GetY(), pointL->GetX(), pointL->GetY());
	}
	return (TRoot*)pointF;
}


void TChart::Show(Graphics ^ gr) {
	Pen^ penBlack = gcnew Pen(Color::Black, 5.0f);
	TRoot *tmp;
	TPoint *tp;
	TChartLine curr;
	TStack<TChartLine> stack;
	curr.tc = this;
	curr.tf = curr.tl = NULL;

	stack.Clr();
	stack.Push(curr);

	while (!stack.IsEmpty())
	{
		curr = stack.Pop();

		while (curr.tf == NULL)
		{
			tmp = curr.tc->pFirst;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tf = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
			}
		}

		if (curr.tl == NULL)
		{
			tmp = curr.tc->pLast;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tl = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
				curr.tf = NULL;
				stack.Push(curr);
			}
		}

		if (curr.tf&&curr.tl)
		{
			curr.tf->Show(gr);
			curr.tl->Show(gr);
			if (curr.tc->fat)
			{
				gr->DrawLine(penBlack, curr.tf->GetX(), curr.tf->GetY(), curr.tl->GetX(), curr.tl->GetY());
			}
			else
			{
				gr->DrawLine(Pens::Black, curr.tf->GetX(), curr.tf->GetY(), curr.tl->GetX(), curr.tl->GetY());
			}

			tp = curr.tl;
			if (!stack.IsEmpty())
			{
				curr = stack.Pop();
				if (curr.tf == NULL)
				{
					curr.tf = tp;
				}
				else
				{
					curr.tl = tp;
				}
				stack.Push(curr);
			}
		}
	}
}

void TChart::FlagOfPoint()
{
	TRoot *tmp;
	TPoint *tp;
	TChartLine curr;
	TStack<TChartLine> stack;
	curr.tc = this;
	curr.tf = curr.tl = NULL;

	stack.Clr();
	stack.Push(curr);

	while (!stack.IsEmpty())
	{
		curr = stack.Pop();

		while (curr.tf == NULL)
		{
			tmp = curr.tc->pFirst;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tf = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
			}
		}

		if (curr.tl == NULL)
		{
			tmp = curr.tc->pLast;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tl = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
				curr.tf = NULL;
				stack.Push(curr);
			}
		}

		if (curr.tf&&curr.tl)
		{
			curr.tf->SetFlag(false);
			curr.tl->SetFlag(false);
			tp = curr.tl;
			if (!stack.IsEmpty())
			{
				curr = stack.Pop();
				if (curr.tf == NULL)
				{
					curr.tf = tp;
				}
				else
				{
					curr.tl = tp;
				}
				stack.Push(curr);
			}
		}
	}
}
void TChart::Hide(Graphics^ gr)
{
	Pen^ penWhite = gcnew Pen(Color::White, 5.0f);
	TRoot *tmp;
	TPoint *tp;
	TChartLine curr;
	TStack<TChartLine> stack;
	curr.tc = this;
	curr.tf = curr.tl = NULL;

	stack.Clr();
	stack.Push(curr);

	while (!stack.IsEmpty())
	{
		curr = stack.Pop();

		while (curr.tf == NULL)
		{
			tmp = curr.tc->pFirst;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tf = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
			}
		}

		if (curr.tl == NULL)
		{
			tmp = curr.tc->pLast;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tl = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
				curr.tf = NULL;
				stack.Push(curr);
			}
		}

		if (curr.tf&&curr.tl)
		{
			curr.tf->Hide(gr);
			curr.tl->Hide(gr);
			if (curr.tc->fat)
			{
				gr->DrawLine(penWhite, curr.tf->GetX(), curr.tf->GetY(), curr.tl->GetX(), curr.tl->GetY());
			}
			else
			{
				gr->DrawLine(Pens::White, curr.tf->GetX(), curr.tf->GetY(), curr.tl->GetX(), curr.tl->GetY());
			}

			tp = curr.tl;
			if (!stack.IsEmpty())
			{
				curr = stack.Pop();
				if (curr.tf == NULL)
				{
					curr.tf = tp;
				}
				else
				{
					curr.tl = tp;
				}
				stack.Push(curr);
			}
		}
	}

}

void TChart::HideFatLines(Graphics^ gr)
{
	Pen^ penWhite = gcnew Pen(Color::White, 5.0f);
	TRoot *tmp;
	TPoint *tp;
	TChartLine curr;
	TStack<TChartLine> stack;
	curr.tc = this;
	curr.tf = curr.tl = NULL;

	stack.Clr();
	stack.Push(curr);

	while (!stack.IsEmpty())
	{
		curr = stack.Pop();

		while (curr.tf == NULL)
		{
			tmp = curr.tc->pFirst;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tf = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
			}
		}

		if (curr.tl == NULL)
		{
			tmp = curr.tc->pLast;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tl = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
				curr.tf = NULL;
				stack.Push(curr);
			}
		}

		if (curr.tf&&curr.tl)
		{
			
			if (curr.tc->fat)
			{
				curr.tf->Hide(gr);
				curr.tl->Hide(gr);
				gr->DrawLine(penWhite, curr.tf->GetX(), curr.tf->GetY(), curr.tl->GetX(), curr.tl->GetY());
			}

			tp = curr.tl;
			if (!stack.IsEmpty())
			{
				curr = stack.Pop();
				if (curr.tf == NULL)
				{
					curr.tf = tp;
				}
				else
				{
					curr.tl = tp;
				}
				stack.Push(curr);
			}
		}
	}
}
void TChart::Move(Graphics^ gr, int dx, int dy)
{
	TRoot *tmp;
	TPoint *tp;
	TChartLine curr;
	TStack<TChartLine> stack;
	curr.tc = this;
	curr.tf = curr.tl = NULL;

	stack.Clr();
	stack.Push(curr);

	while (!stack.IsEmpty())
	{
		curr = stack.Pop();

		while (curr.tf == NULL)
		{
			tmp = curr.tc->pFirst;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tf = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
			}
		}

		if (curr.tl == NULL)
		{
			tmp = curr.tc->pLast;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tl = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
				curr.tf = NULL;
				stack.Push(curr);
			}
		}

		if (curr.tf&&curr.tl)
		{
			//curr.tf->Hide(gr);
			//curr.tl->Hide(gr);
			//gr->DrawLine(Pens::White, curr.tf->GetX(), curr.tf->GetY(), curr.tl->GetX(), curr.tl->GetY());
			this->Hide(gr);

			if (curr.tf->GetFlag() == false)
			{
				curr.tf->Move(gr, dx, dy);
				curr.tf->SetFlag(true);
			}
			if (curr.tl->GetFlag() == false)
			{
				curr.tl->Move(gr, dx, dy);
				curr.tl->SetFlag(true);
			}

			//curr.tf->Show(gr);
			//curr.tl->Show(gr);
			//gr->DrawLine(Pens::Black, curr.tf->GetX(), curr.tf->GetY(), curr.tl->GetX(), curr.tl->GetY());
			tp = curr.tl;
			if (!stack.IsEmpty())
			{
				curr = stack.Pop();
				if (curr.tf == NULL)
				{
					curr.tf = tp;
				}
				else
				{
					curr.tl = tp;
				}
				stack.Push(curr);
			}
		}
	}
	this->FlagOfPoint();
	this->Show(gr);
}

TChartLine TChart::Find(int _x, int _y)
{
	TRoot *tmp;
	TPoint *tp;
	TChartLine curr;
	TChartLine currNULL;
	TStack<TChartLine> stack;
	curr.tc = this;
	currNULL.tf = currNULL.tl = curr.tf = curr.tl = NULL;

	stack.Clr();
	stack.Push(curr);

	while (!stack.IsEmpty())
	{
		curr = stack.Pop();

		while (curr.tf == NULL)
		{
			tmp = curr.tc->pFirst;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tf = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
			}
		}

		if (curr.tl == NULL)
		{
			tmp = curr.tc->pLast;
			tp = dynamic_cast<TPoint*> (tmp);
			if (tp != NULL)
			{
				curr.tl = tp;
			}
			else
			{
				stack.Push(curr);
				curr.tc = dynamic_cast<TChart*> (tmp);
				curr.tf = NULL;
				stack.Push(curr);
			}
		}

		if (curr.tf&&curr.tl)
		{

			if (abs(curr.tf->GetX() - _x) < 20 && abs(curr.tf->GetY() - _y) < 20)
			{

				curr.tl = NULL;
				return curr;
			}

			if (abs(curr.tl->GetX() - _x) < 20 && abs(curr.tl->GetY() - _y) < 20)
			{

				curr.tf = NULL;
				return curr;
			}


			tp = curr.tl;
			if (!stack.IsEmpty())
			{
				curr = stack.Pop();

				if (curr.tf == NULL)
				{
					curr.tf = tp;
				}
				else
				{
					curr.tl = tp;
				}
				stack.Push(curr);
			}

		}


	}
	return currNULL;
}