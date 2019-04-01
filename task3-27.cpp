#include<iostream>
#include<math.h>
#include<string>
#include<fstream>

using namespace std;

class Owner
{
public:

	Owner();

	Owner(string dataF, string dataN, string dataP);

	~Owner();

	Owner& SetName(string dataN)
	{
		name = dataN;
		return *this;
	}

	string GetName()
	{
		return name;
	}

	Owner& SetForname(string dataF)
	{
		forname = dataF;
		return *this;
	}

	string GetForname()
	{
		return forname;
	}

	Owner& SetNumber(string dataP)
	{
		number = dataP;
		return *this;
	}

	string GetNumber()
	{
		return number;
	}

	Owner(const Owner &other)
	{
		cout << " Constuktor Owner " << endl;
		this->name = other.name;
		this->forname = other.forname;
		this->number = other.number;
	}

	void Print()
	{
		cout << this->name << "\t" << this->forname << "\t" << this->number << "\t" << endl;
	}

	void Print2()
	{
		cout << "name: " << this->name << endl;
	}

protected:
	string name,forname,number;
};

Owner::Owner(string dataN, string dataF, string dataP)
{
	cout << " Constuktor Owner " << endl;
	this->name = dataN;
	this->forname = dataF;
	this->number = dataP;
}

Owner::Owner()
{
	cout << " Constuktor Owner " << endl;
	this->name = "noname";
	this->forname = "noname";
	this->number = "noname";
}

Owner::~Owner()
{
	cout << " Destuktor Owner " << endl;
}

class EarthArea
{
public:

	EarthArea();

	EarthArea(string dataC, double ValueX, double valueY, string dataN, string dataF, string dataP);

	~EarthArea();

	EarthArea& SetCity(char* dataN)
	{
		char* City = dataN;
		return *this;
	}

	string GetCity()
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
		cout << " Constuktor EarthArea " << endl;
		this->City = other.City;
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

protected:
	string City;
	double sizeX, sizeY;
	Owner Ownerr;
};

EarthArea::EarthArea(string dataC, double ValueX, double valueY, string dataN, string dataF, string dataP) :Ownerr(dataN, dataF, dataP)
{
	cout << " Constuktor EarthArea " << endl;
	this->City = dataC;
	this->sizeX = ValueX;
	this->sizeY = valueY;
}

EarthArea::EarthArea() :Ownerr()
{
	cout << " Constuktor EarthArea " << endl;
	this->City = "noname";
	sizeY = 0;
	sizeX = 0;
}

EarthArea::~EarthArea()
{
	cout << " Destuktor EarthArea " << endl;
}

class FarmingArea: public EarthArea
{
public:
	FarmingArea();
	FarmingArea(string dataC, double ValueX, double valueY, string dataN, string dataF, string dataP,char valueET, int valueRA);
	FarmingArea(const FarmingArea& other);
	~FarmingArea();

	void Print()
	{
		cout << City << "\t" << sizeY << "\t" << sizeX << "\t" << earthtype << "\t" << recultivationage << endl;
		this->Ownerr.Print();
		cout << endl;
	}

protected:
	char earthtype;
	int recultivationage;
};

FarmingArea::FarmingArea()
{
	this->earthtype = 'A';
	this->recultivationage = 0;
	cout << " Constuktor FarmingArea " << endl;
}

FarmingArea::FarmingArea(string dataC, double ValueX, double valueY, string dataN, string dataF, string dataP, char valueET, int valueRA):EarthArea(dataC,ValueX,valueY,dataN,dataF,dataP)
{

	cout << " Constuktor FarmingArea " << endl;
}

FarmingArea::FarmingArea(const FarmingArea& other)
{
	cout << " Constuktor FarmingArea " << endl;
	this->City = other.City;
	this->sizeY = other.sizeY;
	this->Ownerr = other.Ownerr;
	this->sizeX = other.sizeX;
	this->earthtype = other.earthtype;
	this->recultivationage = other.recultivationage;
}

FarmingArea::~FarmingArea()
{
	cout << " Destuktor FarmingArea " << endl;
}

class ForBuild:public EarthArea
{
public:
	ForBuild();
	ForBuild(string dataC, double ValueX, double valueY, string dataN, string dataF, string dataP, bool valueNet, double valueA, double valueCost);
	ForBuild(const ForBuild& other);
	~ForBuild();

	void Print()
	{
		cout << City << "\t" << sizeY << "\t" << sizeX << "\t" << ingenierNet << "\t" << away << "\t" << cost << endl;
		this->Ownerr.Print();
		cout << endl;
	}

protected:
	bool ingenierNet;
	double away, cost;
};

ForBuild::ForBuild()
{
	this->ingenierNet = 0;
	this->away = 0;
	this->cost = 0;
	cout << " Constuktor ForBuild " << endl;
}

ForBuild::ForBuild(string dataC, double ValueX, double valueY, string dataN, string dataF, string dataP, bool valueNet, double valueA, double valueCost) :EarthArea(dataC, ValueX, valueY, dataN, dataF, dataP)
{
	this->ingenierNet = valueNet;
	this->away = valueA;
	this->cost = valueCost;
	cout << " Constuktor ForBuild " << endl;
}

ForBuild::ForBuild(const ForBuild& other)
{
	this->City = other.City;
	this->sizeY = other.sizeY;
	this->Ownerr = other.Ownerr;
	this->sizeX = other.sizeX;
	this->ingenierNet = other.ingenierNet;
	this->away = other.away;
	this->cost = other.cost;
	cout << " Constuktor ForBuild " << endl;
}

ForBuild::~ForBuild()
{
	cout << " Destuktor ForBuild " << endl;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	FarmingArea FA1;
	FA1.Print();

	ForBuild FB1;
	FB1.Print();

	return 0;
}
