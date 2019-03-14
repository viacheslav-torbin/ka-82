#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

class Koor
{
public:
	Koor();
	Koor(double valueX, double valueY);
	~Koor();

	double GetX()
	{  
		return x;
	}

	Koor& SetX(double valueX)
	{
		this->x = valueX;
		return *this;
	}

	double GetY()
	{
		return y;
	}

	Koor& SetY(double valueY)
	{
		this->y = valueY;
		return *this;
	}

	void Print()
	{
		cout << "x =\t" << x << "\t" << "y =\t" << y << endl;
	}

	Koor(const Koor &other)
	{
		this->x = other.x;
		this->y = other.y;
	}

	void Print2()
	{
		cout << "Koor(" << x << "," << y << ")" << endl;
	}


private:
	double x, y;
};

Koor::Koor(double valueX, double valueY)
{
	x = valueX;
	y = valueY;
}

Koor::Koor()
{
	x = 0;
	y = 0;
}

Koor::~Koor()
{
}


class Qreacher
{
public:

	Qreacher();

	Qreacher(char* dataN, int valueA, double ValueX, double valueY);

	~Qreacher();

	Qreacher& SetName(char* dataN)
	{
		char* Name = new char[size];
		strcpy(Name, dataN);
		return *this;
	}

	char* GetName()
	{
		return Name;
	}

	Qreacher& SetAge(int valueA)
	{
		this->Age = valueA;
		return *this;
	}

	int GetAge()
	{
		return Age;
	}

	Qreacher& SetField(double valueX, double valueY)
	{
		this->Field.SetX(valueX);
		this->Field.SetY(valueY);
		return *this;
	}

	Koor GetField()
	{
		return Field;
	}

	Qreacher& Move()
	{
		double valueX, valueY;
		valueY = this->Field.GetY();
		valueX = this->Field.GetX();
		valueX++;
		valueY++;
		this->Field.SetX(valueX);
		this->Field.SetY(valueY);
		return *this;
	}

	Qreacher(const Qreacher &other)
	{
		this->Name = new char[strlen(other.Name)+1];
		strcpy(Name, other.Name);
		this->Age = other.Age;
		this->Field = other.Field;
		this->size = other.size;
	}

	void Print()
	{
		cout << Name << "\t" << Age << "\t";
		this->Field.Print();
		cout << endl;
	}

	void Print2()
	{
		cout << "Name: " << this->Name << endl;
	}

private:
	char* Name;
	int size;
	int Age;
	Koor Field;
};

Qreacher::Qreacher(char* dataN, int valueA, double valueX, double valueY):Field(valueX,valueY)
{
	this->size = strlen(dataN)+1;
	this->Name = new char[size];
	strcpy(this->Name, dataN);
	Age = valueA;
}

Qreacher::Qreacher():Field(0,0)
{
	this->Name = new char[7];
	strcpy(Name,"noname");
	Age = 0;
	size = 0;
}

Qreacher::~Qreacher()
{
	delete[] Name;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int vx, vy, va;
	double vqx, vqy;
	char l[40];
	Koor a;
	cout << "Enter x" << endl;
	cin >> vx;
	cout << "Enter Y" << endl;
	cin >> vy;
	Koor b(vx, vy);
	Koor c(b);
	a.Print();
	b.Print2();
	c.Print();
	Qreacher q1;
	cout << "Enter line" << endl;
	cin >> l;
	cout << "Enter age" << endl;
	cin >> va;
	cout << "Enter x" << endl;
	cin >> vqx;
	cout << "Enter Y" << endl;
	cin >> vqy;
	Qreacher q2(l,va,vqx,vqy);
	Qreacher q3(q2);
	q1.Print();
	q2.Print2();
	q3.Print();
}
