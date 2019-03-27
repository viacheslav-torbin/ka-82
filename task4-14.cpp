#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

class Coor
{

public:
	Coor();
	Coor(double valueX, double valueY);
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

	void Print()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}

	Coor(const Coor &other)
	{
		this->x = other.x;
		this->y = other.y;
	}

	bool operator == (const Coor & other)
	{
		return ((this->x == other.x) && (this->y == other.y));
	}
public:
	double x, y;
};

Coor::Coor(double valueX, double valueY)
{
	x = valueX;
	y = valueY;
}

Coor::Coor()
{
	x = 0;
	y = 0;
}

Coor::~Coor()
{
}

class ExistenceLifeForm
{
public:

	ExistenceLifeForm();

	ExistenceLifeForm(char* dataN, int valueA, double ValueX, double valueY);

	ExistenceLifeForm(const ExistenceLifeForm &other)
	{
		this->Name = new char[strlen(other.Name) + 1];
		strcpy(Name, other.Name);
		this->Age = other.Age;
		this->Coordinat = other.Coordinat;
	}

	~ExistenceLifeForm();

	virtual void Move() = 0;

	void Print()
	{
		cout << Name << "\t" << Age << "\t";
		this->Coordinat.Print();
		cout << endl;
	}

protected:
	char* Name;
	int Age;
	Coor Coordinat;
};

ExistenceLifeForm::ExistenceLifeForm(char* dataN, int valueA, double valueX, double valueY) :Coordinat(valueX, valueY)
{
	this->Name = new char[strlen(dataN) + 1];
	strcpy(this->Name, dataN);
	Age = valueA;
}

ExistenceLifeForm::ExistenceLifeForm() :Coordinat(0, 0)
{
	this->Name = new char[7];
	strcpy(Name, "noname");
	Age = 0;
}

ExistenceLifeForm::~ExistenceLifeForm()
{
	delete[] Name;
}

class Creature : public ExistenceLifeForm, public Coor
{
public:
	Creature();
	Creature(char* dataN, int valueA, double valueX, double valueY);
	Creature(Creature &other);
	~Creature();

	void Print()
	{
		cout << Name << "\t" << Age << "\t" << LifeStatus;
		this->Coordinat.Print();
		cout << endl;
	}

	void Move() = 0;
	bool LifeStatus;
};

Creature::Creature()
{
	this->LifeStatus = 1;
}

Creature::Creature(char * dataN, int valueA, double valueX, double valueY) :ExistenceLifeForm(dataN, valueA, valueX, valueY)
{
	this->LifeStatus = 1;
}

Creature::Creature(Creature & other)
{
	this->Name = new char[strlen(other.Name) + 1];
	this->Age = other.Age;
	strcpy(this->Name, other.Name);
	this->Coordinat = other.Coordinat;
	this->LifeStatus = 1;
}

Creature::~Creature()
{
}

class Plant : public ExistenceLifeForm
{
public:
	Plant(char * dataN, int valueA, double valueX, double valueY);
	Plant();
	Plant(Plant &other);
	void Move()
	{
		this->Print();
	}
	~Plant();
	void Print()
	{
		this->Coordinat.Print();
		cout << endl;
	}
};

Plant::Plant(char * dataN, int valueA, double valueX, double valueY) :ExistenceLifeForm(dataN, valueA, valueX, valueY)
{
}

Plant::Plant()
{
}

Plant::Plant(Plant & other)
{
	this->Name = new char[strlen(other.Name) + 1];
	this->Age = other.Age;
	strcpy(this->Name, other.Name);
	this->Coordinat = other.Coordinat;
}

Plant::~Plant()
{
}

class UnMovedObject : public ExistenceLifeForm
{
public:
	UnMovedObject();
	UnMovedObject(char * dataN, int valueA, double valueX, double valueY);
	UnMovedObject(UnMovedObject &other);
	~UnMovedObject();

	bool operator == (const UnMovedObject & other1)
	{
		return ((this->Age == other1.Age) && (this->Coordinat == other1.Coordinat) && !(strcmp(this->Name, other1.Name)));
	}

	void Move()
	{
		this->Print();
	}
	void Print()
	{
		cout << Name << endl;
		this->Coordinat.Print();
		cout << endl;
	}

};

UnMovedObject::UnMovedObject()
{
}

UnMovedObject::UnMovedObject(char * dataN, int valueA, double valueX, double valueY) : ExistenceLifeForm(dataN, valueA, valueX, valueY)
{
}

UnMovedObject::UnMovedObject(UnMovedObject &other)
{
	this->Name = new char[strlen(other.Name) + 1];
	this->Age = other.Age;
	strcpy(this->Name, other.Name);
	this->Coordinat = other.Coordinat;
}

UnMovedObject::~UnMovedObject()
{
}

class Predator;

class Herbivorous : public Creature
{
public:
	Herbivorous();
	Herbivorous(char * dataN, int valueA, double valueX, double valueY);
	Herbivorous(Herbivorous &other);
	~Herbivorous();
	friend void operator - (Herbivorous& Her, Predator& Pre);

	friend Predator;
	void Move()
	{
		this->Coordinat.x++;
		this->Coordinat.y++;
		this->Age++;
		if (Age < this->MaxAgeHerbivous)
		{
			this->LifeStatus = 1;
		}
		else
		{
			this->LifeStatus = 0;
		}
	}

	void Print()
	{
		cout << this->Name << "\t" << this->Age << "\t" << this->LifeStatus << endl;
		this->Coordinat.Print();
		cout << endl;
	}

	Herbivorous& operator ++()
	{
		this->Age++;

		return *this;
	}

	Herbivorous operator ++(int value)
	{
		Herbivorous temp(*this);
		this->Age++;

		return temp;
	}


	friend ostream& operator<< (ostream& out, Herbivorous& outstream);
	friend istream& operator>> (istream& in, Herbivorous& instream);

protected:
	static int MaxAgeHerbivous;
};

Herbivorous::Herbivorous()
{
	this->MaxAgeHerbivous = 50;
}

Herbivorous::Herbivorous(char * dataN, int valueA, double valueX, double valueY) : Creature(dataN, valueA, valueX, valueY)
{
}

Herbivorous::Herbivorous(Herbivorous &other)
{
	this->Name = new char[strlen(other.Name) + 1];
	this->Age = other.Age;
	strcpy(this->Name, other.Name);
	this->Coordinat = other.Coordinat;
}

Herbivorous::~Herbivorous()
{
}

int Herbivorous::MaxAgeHerbivous = 50;

class Predator : public Creature
{
public:
	Predator();
	Predator(char * dataN, int valueA, double valueX, double valueY);
	Predator(Predator &other);
	~Predator();

	friend void operator - (Herbivorous& Her, Predator& Pre);

	void Print()
	{
		cout << this->Name << "\t" << this->Age << "\t" << this->LifeStatus << endl;
		this->Coordinat.Print();
		cout << endl;
	}

	friend Herbivorous;

	void Move()
	{
		this->Coordinat.x++;
		this->Coordinat.y++;
		this->Age++;
		if (Age < this->MaxAgePredator)
		{
			this->LifeStatus = 1;
		}
		else
		{
			this->LifeStatus = 0;
		}
	}

	Predator& operator ++()
	{
		this->Age++;
		return *this;
	}

	Predator operator ++(int value)
	{
		Predator temp(*this);
		this->Age++;
		return temp;
	}

	friend ostream& operator<< (ostream& out, Predator& outstream);
	friend istream& operator>> (istream& in, Predator& instream);
protected:
	static int MaxAgePredator;
};

int Predator::MaxAgePredator = 100;

Predator::Predator()
{
}

Predator::Predator(char * dataN, int valueA, double valueX, double valueY) : Creature(dataN, valueA, valueX, valueY)
{
	
}

Predator::Predator(Predator &other)
{
	this->Name = new char[strlen(other.Name) + 1];
	this->Age = other.Age;
	strcpy(this->Name, other.Name);
	this->Coordinat = other.Coordinat;
}

Predator::~Predator()
{
}

ostream& operator << (ostream& out, Predator& outstream) {
	out << "Name: " << outstream.Name << endl;
	out << "Age: " << outstream.Age << endl;
	out << "(" << outstream.Coordinat.x << "," << outstream.Coordinat.y << ")" << endl;
	return out;
}

istream& operator >> (istream& in, Predator& instream) {
	cout << "Name" << endl;
	cout << "Age" << endl;
	cout << "x" << endl;
	cout << "y" << endl;
	in >> instream.Name;
	in >> instream.Age;
	in >> instream.Coordinat.x;
	in >> instream.Coordinat.y;
	return in;
}

ostream& operator << (ostream& out, Herbivorous& outstream) {
	out << "Name: " << outstream.Name << endl;
	out << "Age: " << outstream.Age << endl;
	out << "(" << outstream.Coordinat.x << "," << outstream.Coordinat.y << ")" << endl;
	return out;
}

istream& operator >> (istream& in, Herbivorous& instream) {
	cout << "Name" << endl;
	cout << "Age" << endl;
	cout << "x" << endl;
	cout << "y" << endl;
	in >> instream.Name;
	in >> instream.Age;
	in >> instream.Coordinat.x;
	in >> instream.Coordinat.y;
	return in;
}

void operator-(Herbivorous & Her, Predator & Pre)
{
	Her.LifeStatus = 0;
	Pre.Age++;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	UnMovedObject Un1;
	UnMovedObject Un2(Un1);
	bool b = (Un1 == Un2);
	cout << "Operator ==" << b << endl;
	cout << endl << "End UnMovedObject test" << endl << endl;

	Predator Pre1;
	Pre1.Print();
	Pre1++;
	Pre1.Print();
	cin >> Pre1;
	cout << Pre1;
	cout << endl << "End Predator test" << endl << endl;

	Herbivorous Her;
	Her.Print();
	Her++;
	Her.Print();
	cin >> Her;
	cout << Her;
	cout << endl << "End Herbivorous test" << endl << endl;

	return 0;
}