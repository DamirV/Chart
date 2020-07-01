template <class T>

class TStack
{
private:
	int Size;
	int MaxSize;
	T *Mas;

public:
	TStack(int _MaxSize = 100)
	{
		if (_MaxSize <= 0)
			throw 0;

		MaxSize=_MaxSize;
		Size=0;
		Mas=new T[MaxSize+1];
	}


	~TStack()
	{
		delete[] Mas;
	}

	TStack(const TStack& ts)
	{
		MaxSize=ts.MaxSize;
		Size=ts.Size;
		Mas = new T[MaxSize+1];

		for (int i = 1; i <= Size; i++)
		{
			Mas[i] = ts.Mas[i];
		}

	}

	bool IsEmpty()
	{
		if(Size==0)
			return true;
		else
			return false;
	}


	bool IsFull()
	{
		if(Size==MaxSize)
			return true;
		else
			return false;
	}

	void Clr()
	{
		Size=0;
	}

	void Push(T t)
	{
		if (this->IsFull()) 
			throw 0;

		Size++;
		Mas[Size] = t;
	}

	T Top()
	{
		if (IsEmpty()) throw 0;

		return Mas[Size];
	}

	T Pop()
	{
		if (IsEmpty()) throw 0;

		Size--;
		return Mas[Size + 1];
	}

};

