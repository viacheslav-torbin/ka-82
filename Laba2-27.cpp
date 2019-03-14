#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

class Owner
{
public:

	Owner();

	Owner(char* dataF, char* dataN, char* dataP);

	~Owner();

	Owner& SetName(char* dataN)
	{
		char* Name = new char[strlen(dataN) + 1];
		strcpy(Name, dataN);
		return *this;
	}

	char* GetName()
	{
		return Name;
	}

	Owner& SetForname(char* dataF)
	{
		char* Forname = new char[strlen(dataF) + 1];
		strcpy(Forname, dataF);
		return *this;
	}

	char* GetForname()
	{
		return Forname;
	}

	Owner& SetNumber(char* dataP)
	{
		char* Number = new char[strlen(dataP) + 1];
		strcpy(Number, dataP);
		return *this;
	}

	char* GetNumber()
	{
		return Number;
	}

	Owner(const Owner &other)
	{
		this->Name = new char[strlen(other.Name) + 1];
		strcpy(Name, other.Name);
		this->Forname = new char[strlen(other.Forname) + 1];
		strcpy(Forname, other.Forname);
		this->Number = new char[strlen(other.Number) + 1];
		strcpy(Number, other.Number);
	}

	void Print()
	{
		cout << this->Name << "\t" << this->Forname << "\t" << this->Number << "\t" << endl;
	}

	void Print2()
	{
		cout << "Name: " << this->Name << endl;
	}

private:
	char* Name;
	char* Forname;
	char* Number;
};

Owner::Owner(char* dataN, char* dataF, char* dataP)
{
	this->Name = new char[strlen(dataN) + 1];
	strcpy(this->Name, dataN);
	this->Forname = new char[strlen(dataF) + 1];
	strcpy(this->Forname, dataF);
	this->Number = new char[strlen(dataP) + 1];
	strcpy(Number, dataP);
}

Owner::Owner()
{
	this->Name = new char[7];
	strcpy(Name, "noname");
	this->Forname = new char[7];
	strcpy(Forname, "noname");
	this->Number = new char[7];
	strcpy(Number, "noname");
}

Owner::~Owner()
{
	delete[] Name;
	delete[] Forname;
	delete[] Number;
}

class EarthArea
{
public:

	EarthArea();

	EarthArea(char* dataC, double ValueX, double valueY, char* dataN, char* dataF, char* dataP);

	~EarthArea();

	EarthArea& SetCity(char* dataN)
	{
		char* City = new char[strlen(dataN)+1];
		strcpy(City, dataN);
		return *this;
	}

	char* GetCity()
	{
		return City;
	}

	EarthArea& SetSizeY(int valueY)
	{
		this->sizeY = valueY;
		return *this;
	}

	int GetSizeY()
	{
		return sizeY;
	}

	EarthArea& SetSizeX(int valueX)
	{
		this->sizeX = valueX;
		return *this;
	}

	int GetSizeX()
	{
		return sizeX;
	}

	EarthArea& SetOwnerr(char* dataN, char* dataF, char* dataP)
	{
		this->Ownerr.SetName(dataN);
		this->Ownerr.SetForname(dataF);
		this->Ownerr.SetNumber(dataP);
		return *this;
	}

	Owner GetOwnerr()
	{
		return Ownerr;
	}

	EarthArea(const EarthArea &other)
	{
		this->City = new char[strlen(other.City) + 1];
		strcpy(City, other.City);
		this->sizeY = other.sizeY;
		this->Ownerr = other.Ownerr;
		this->sizeX = other.sizeX;
	}

	void Print()
	{
		cout << City << "\t" << sizeY << "\t" << sizeX << "\t";
		this->Ownerr.Print();
		cout << endl;
	}

	void Print2()
	{
		cout << "City: " << this->City << endl;
	}

private:
	char* City;
	double sizeX, sizeY;
	Owner Ownerr;
};

EarthArea::EarthArea(char* dataC, double valueX, double valueY, char* dataN, char* dataF, char* dataP) :Ownerr(dataN,dataF,dataP)
{
	this->City = new char[strlen(dataC) + 1];
	strcpy(this->City, dataC);
	sizeX = valueX;
	sizeY = valueY;
}

EarthArea::EarthArea() :Ownerr()
{
	this->City = new char[7];
	strcpy(City, "noname");
	sizeY = 0;
	sizeX = 0;
}

EarthArea::~EarthArea()
{
	delete[] City;
}


int main()
{
	setlocale(LC_ALL, "RUS");

	char Name[40], Forname[40], Number[40];
	Owner q1;
	cout << "Enter name" << endl;
	cin >> Name;
	cout << "Enter forname" << endl;
	cin >> Forname;
	cout << "Enter number" << endl;
	cin >> Number;
	Owner q2(Name, Forname, Number);
	Owner q3(q2);
	q1.Print();
	q2.Print2();
	q3.Print();

	char City[40], Forname1[40], Number1[40], Name1[40];
	double vx, vy;
	EarthArea a1;
	cout << "Enter name" << endl;
	cin >> Name1;
	cout << "Enter forname" << endl;
	cin >> Forname1;
	cout << "Enter number" << endl;
	cin >> Number1;
	cout << "Enter city" << endl;
	cin >> City;
	cout << "Enter x" << endl;
	cin >> vx;
	cout << "Enter y" << endl;
	cin >> vy;
	EarthArea a2(City,vx,vy,Name1,Forname1,Number1);
	EarthArea a3(a2);
	a1.Print();
	a2.Print2();
	a3.Print();

	return 0;
}
