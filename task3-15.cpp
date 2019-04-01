#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

class Coor
{
public:
	Coor();
	Coor(double valueX, double valueY, int valueN);
	~Coor();

	double GetX()
	{
		return x;
	}

	Coor& SetX(double valueX)
	{
		this->x = valueX;
		return *this;
	}

	double GetY()
	{
		return y;
	}

	Coor& SetY(double valueY)
	{
		this->y = valueY;
		return *this;
	}

	double GetNumber()
	{
		return number;
	}

	Coor& SetNumber(double valueN)
	{
		this->number = valueN;
		return *this;
	}

	void Print()
	{
		cout << "x =\t" << x << "\t" << "y =\t" << y << "\t" << "number =\t" << number << endl;
	}

	Coor(const Coor &other)
	{
		this->x = other.x;
		this->y = other.y;
		this->number = other.number;
	}

	void Print2()
	{
		cout << "Coor(" << x << "," << y << ")   " << number << endl;
	}


protected:
	double x, y;
	int number;
};

Coor::Coor(double valueX, double valueY, int valueN)
{
	cout << "Konstructor Coor" << endl;
	x = valueX;
	y = valueY;
	number = valueN;
}

Coor::Coor()
{
	cout << "Konstructor Coor" << endl;
	x = 0;
	y = 0;
	number = 0;
}

Coor::~Coor()
{
	cout << "Destructor Coor" << endl;
}

class ClimatConditions
{
public:
	int Temp, Osvit, Kuslot, Volog;
	ClimatConditions();
	ClimatConditions(int valueT, int valueO, int valueK, int valueV);
	ClimatConditions(ClimatConditions &other);
	~ClimatConditions();

	ClimatConditions& SetTemp(int valueT)
	{
		this->Temp = valueT;
		return *this;
	}

	int GetTemp()
	{
		return this->Temp;
	}

	ClimatConditions& SetOsvit(int valueO)
	{
		this->Osvit = valueO;
		return *this;
	}

	int GetOsvit()
	{
		return this->Osvit;
	}

	ClimatConditions& SetKuslot(int valueK)
	{
		this->Kuslot = valueK;
		return *this;
	}

	int GetKuslot()
	{
		return this->Kuslot;
	}

	ClimatConditions& SetVolog(int valueV)
	{
		this->Volog = valueV;
		return *this;
	}

	int GetVolog()
	{
		return this->Volog;
	}

	void Show()
	{
		cout << this->Temp << "\t" << this->Osvit << "\t" << this->Kuslot << "\t" << this->Volog << endl;
	}

	void Print2()
	{
		cout << "Temp: " << this->Temp << endl;
	}
};

ClimatConditions::ClimatConditions()
{
	cout << "Konstructor ClimatConditions" << endl;
	this->Temp = 0;
	this->Osvit = 0;
	this->Kuslot = 0;
	this->Volog = 0;
}

ClimatConditions::ClimatConditions(int valueT, int valueO, int valueK, int valueV)
{
	cout << "Konstructor ClimatConditions" << endl;
	this->Temp = valueT;
	this->Osvit = valueO;
	this->Kuslot = valueK;
	this->Volog = valueV;
}

ClimatConditions::ClimatConditions(ClimatConditions &other)
{
	cout << "Konstructor ClimatConditions" << endl;
	this->Temp = other.Temp;
	this->Osvit = other.Osvit;
	this->Kuslot = other.Kuslot;
	this->Volog = other.Volog;
}

ClimatConditions::~ClimatConditions()
{
	cout << "Destructor ClimatConditions" << endl;
}

class ClimatConditionsWarmHouse:public ClimatConditions
{
public:
	ClimatConditionsWarmHouse();
	ClimatConditionsWarmHouse(int valueT, int valueO, int valueK, int valueV);
	ClimatConditionsWarmHouse(const ClimatConditionsWarmHouse& other);
	~ClimatConditionsWarmHouse();

	void Show()
	{
		if (this->Temp>WarmHouseMaxTemp)
		{
			cout << "Temperature exceed:  " << (this->Temp - WarmHouseMaxTemp) << endl;
		}
		if (this->Osvit > WarmHouseMaxOsvit)
		{
			cout << "Osvitlenist exceed:  " << (this->Osvit - WarmHouseMaxOsvit) << endl;
		}
		if (this->Kuslot > WarmHouseMaxKuslot)
		{
			cout << "Kuslotnist exceed:  " << (this->Kuslot - WarmHouseMaxKuslot) << endl;
		}
		if (this->Volog > WarmHouseMaxVolog)
		{
			cout << "Vologist exceed:  " << (this->Volog - WarmHouseMaxVolog) << endl;
		}
	}

private:
	static int OptCondWarmHouseTemp;
	static int OptCondWarmHouseOsvit;
	static int OptCondWarmHouseKuslot;
	static int OptCondWarmHouseVolog;

	static int WarmHouseMaxTemp;
	static int WarmHouseMaxOsvit;
	static int WarmHouseMaxKuslot;
	static int WarmHouseMaxVolog;

};

int ClimatConditionsWarmHouse::OptCondWarmHouseTemp=25;
int ClimatConditionsWarmHouse::OptCondWarmHouseOsvit=85;
int ClimatConditionsWarmHouse::OptCondWarmHouseKuslot=30;
int ClimatConditionsWarmHouse::OptCondWarmHouseVolog=40;

int ClimatConditionsWarmHouse::WarmHouseMaxTemp=50;
int ClimatConditionsWarmHouse::WarmHouseMaxOsvit=30;
int ClimatConditionsWarmHouse::WarmHouseMaxKuslot=80;
int ClimatConditionsWarmHouse::WarmHouseMaxVolog=55;

ClimatConditionsWarmHouse::ClimatConditionsWarmHouse()
{
	cout << "Konstructor ClimatConditionsWarmHouse" << endl;
}

ClimatConditionsWarmHouse::ClimatConditionsWarmHouse(int valueT, int valueO, int valueK, int valueV):ClimatConditions(valueT,valueO,valueK,valueV)
{
	cout << "Konstructor ClimatConditionsWarmHouse" << endl;
}

ClimatConditionsWarmHouse::ClimatConditionsWarmHouse(const ClimatConditionsWarmHouse& other):ClimatConditions(other.Temp,other.Osvit,other.Kuslot,other.Volog)
{
	cout << "Konstructor ClimatConditionsWarmHouse" << endl;
}

ClimatConditionsWarmHouse::~ClimatConditionsWarmHouse()
{
	cout << "Destructor ClimatConditionsWarmHouse" << endl;
}

class ClimatConditionsFarm:public ClimatConditions
{
public:
	ClimatConditionsFarm();
	ClimatConditionsFarm(int valueT, int valueO, int valueK, int valueV);
	ClimatConditionsFarm(const ClimatConditionsFarm& other);
	~ClimatConditionsFarm();

	static int FarmMaxTemp;
	static int FarmMaxOsvit;
	static int FarmMaxKuslot;
	static int FarmMaxVolog;

	void Show()
	{
		if (this->Temp > FarmMaxTemp)
		{
			cout << "Temperature exceed:  " << (this->Temp - FarmMaxTemp) << endl;
		}
		if (this->Osvit > FarmMaxOsvit)
		{
			cout << "Osvitlenist exceed:  " << (this->Osvit - FarmMaxOsvit) << endl;
		}
		if (this->Kuslot > FarmMaxKuslot)
		{
			cout << "Kuslotnist exceed:  " << (this->Kuslot - FarmMaxKuslot) << endl;
		}
		if (this->Volog > FarmMaxVolog)
		{
			cout << "Vologist exceed:  " << (this->Volog - FarmMaxVolog) << endl;
		}
	}
};

int ClimatConditionsFarm::FarmMaxTemp=30;
int ClimatConditionsFarm::FarmMaxOsvit=100;
int ClimatConditionsFarm::FarmMaxKuslot=40;
int ClimatConditionsFarm::FarmMaxVolog=50;

ClimatConditionsFarm::ClimatConditionsFarm()
{
	cout << "Konstructor ClimatConditionsFarm" << endl;
}

ClimatConditionsFarm::ClimatConditionsFarm(int valueT, int valueO, int valueK, int valueV):ClimatConditions(valueT, valueO, valueK, valueV)
{
	cout << "Konstructor ClimatConditionsFarm" << endl;
}

ClimatConditionsFarm::ClimatConditionsFarm(const ClimatConditionsFarm & other):ClimatConditions(other.Temp, other.Osvit, other.Kuslot, other.Volog)
{
	cout << "Konstructor ClimatConditionsFarm" << endl;
}

ClimatConditionsFarm::~ClimatConditionsFarm()
{
	cout << "Destructor ClimatConditionsFarm" << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	int num, temp, osvit, kuslot, volog;
	double vx, vy;
	ClimatConditions CC1;
	CC1.Show();

	ClimatConditionsFarm CCF1(100,100,100,100);
	CCF1.Show();

	ClimatConditionsWarmHouse CCWH1(100,100,100,100);
	CCWH1.Show();

	return 0;
}
