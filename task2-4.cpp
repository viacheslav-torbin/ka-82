#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

class Date
{
public:

	Date();

	Date(char* dataD, char* dataM, int valueY);

	~Date();

	Date& SetDay(char* dataD)
	{
		char* Day = new char[strlen(dataD) + 1];
		strcpy(Day, dataD);
		return *this;
	}

	char* GetDay()
	{
		return Day;
	}

	Date& SetMounth(char* dataM)
	{
		char* Day = new char[strlen(dataM) + 1];
		strcpy(Day, dataM);
		return *this;
	}

	char* GetMounth()
	{
		return Mounth;
	}

	Date& SetYear(int valueL)
	{
		this->Year = valueL;
		return *this;
	}

	int GetYear()
	{
		return Year;
	}

	Date(const Date &other)
	{
		this->Day = new char[strlen(other.Day) + 1];
		strcpy(Day, other.Day);
		this->Mounth = new char[strlen(other.Mounth) + 1];
		strcpy(Mounth, other.Mounth);
		this->Year = other.Year;
	}

	void Print()
	{
		cout << this->Day << "\t" << this->Mounth << "\t" << this->Year << "\t" << endl;
	}

	void Print2()
	{
		cout << "Day: " << this->Day << endl;
	}

private:
	char* Day;
	char* Mounth;
	int Year;
};

Date::Date(char* dataD, char* dataM, int valueY)
{
	this->Day = new char[strlen(dataD) + 1];
	strcpy(this->Day, dataD);
	this->Mounth = new char[strlen(dataM) + 1];
	strcpy(this->Mounth, dataM);
	Year = valueY;
}

Date::Date()
{
	this->Day = new char[7];
	strcpy(Day, "noname");
	this->Mounth = new char[7];
	strcpy(Mounth, "noname");
	Year = 0;
}

Date::~Date()
{
	delete[] Day;
	delete[] Mounth;
}

class Koor
{
public:
	Koor();
	Koor(double valueX, double valueY, int valueN);
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

	double GetNumber()
	{
		return number;
	}

	Koor& SetNumber(double valueN)
	{
		this->number = valueN;
		return *this;
	}

	void Print()
	{
		cout << "x =\t" << x << "\t" << "y =\t" << y << "\t" << "number =\t" << number << endl;
	}

	Koor(const Koor &other)
	{
		this->x = other.x;
		this->y = other.y;
		this->number = other.number;
	}

	void Print2()
	{
		cout << "Koor(" << x << "," << y << ")   " << number << endl;
	}


private:
	double x, y;
	int number;
};

Koor::Koor(double valueX, double valueY,int valueN)
{
	x = valueX;
	y = valueY;
	number = valueN;
}

Koor::Koor()
{
	x = 0;
	y = 0;
	number = 0;
}

Koor::~Koor()
{
}

int main()
{
	setlocale(LC_ALL, "RUS");
	char Day[40], Mounth[40];
	int Year, num;
	double vx, vy;
	Date q1;
	cout << "Enter day" << endl;
	cin >> Day;
	cout << "Enter mounth" << endl;
	cin >> Mounth;
	cout << "Enter year" << endl;
	cin >> Year;
	Date q2(Day, Mounth, Year);
	Date q3(q2);
	q1.Print();
	q2.Print2();
	q3.Print();
	Koor k1;
	cout << "Enter X" << endl;
	cin >> vx;
	cout << "Enter Y" << endl;
	cin >> vy;
	cout << "Enter number" << endl;
	cin >> num;
	Koor k2(vx, vy, num);
	Koor k3(k2);
	k1.Print();
	k2.Print2();
	k3.Print();
}
