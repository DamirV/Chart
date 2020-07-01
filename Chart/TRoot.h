#pragma once
#include <cmath>
#include "TStack.h"
using namespace System::Drawing;

class TRoot {
protected:
	bool visible, active;

public:
	TRoot();
	~TRoot();
	virtual void Show(Graphics^ gr) = 0;
	virtual void Hide(Graphics^ gr) = 0;
	virtual void Move(Graphics^ gr, int dx, int dy) = 0;
	
};