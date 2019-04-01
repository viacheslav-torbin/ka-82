#include<iostream>
#include<math.h>
#include<string>
#include<fstream>

using namespace std;

class Nota
{
public:

	Nota();

	Nota(string dataN, string dataO, double valueL);

	~Nota();

	Nota& SetName(char* dataN)
	{
		Name = dataN;
		return *this;
	}

	string GetName()
	{
		return Name;
	}

	Nota& SetOktava(char* dataO)
	{
		Oktava = dataO;
		return *this;
	}

	string GetOktava()
	{
		return Oktava;
	}

	Nota& SetLenght(int valueL)
	{
		this->lenght = valueL;
		return *this;
	}

	int GetLenght()
	{
		return lenght;
	}

	Nota(const Nota &other)
	{
		this->Name = other.Name;
		this->Oktava = other.Oktava;
		this->lenght = other.lenght;
	}

	void Print()
	{
		cout << this->Name << "\t" << this->Oktava << "\t" << this->lenght << "\t" << endl;
	}

	void Print2()
	{
		cout << "Name: " << this->Name << endl;
	}

	Nota& operator ++()
	{
		this->lenght = this->lenght + 0.125;
		return *this;
	}

	Nota& operator ++(int value)
	{
		Nota temp(*this);
		this->lenght = this->lenght + 0.125;
		return temp;
	}

	Nota& operator --()
	{
		this->lenght = this->lenght - 0.125;
		return *this;
	}

	Nota& operator --(int value)
	{
		Nota temp(*this);
		this->lenght = this->lenght - 0.125;
		return temp;
	}

protected:
	string Name;
	string Oktava;
	double lenght;
};

Nota::Nota(string dataN, string dataO, double valueL)
{
	this->Name = dataN;
	this->Oktava = dataO;
	lenght = valueL;
}

Nota::Nota()
{
	this->Name = "noname";
	this->Oktava = "noname";
	lenght = 0;
}

Nota::~Nota()
{
}

class Voice : public Nota
{
public:
	Voice();
	Voice(double Frequency, int Number, string dataN, string dataO, double valueL);
	Voice(const Voice& other);
	~Voice();

	void PrintV()
	{
		this->Print();
		cout << this->Frequency << this->Number << endl;
	}

	friend ostream& operator<< (ostream& out, Voice& outstream);
	friend istream& operator>> (istream& in, Voice& instream);

	bool operator > (const Voice& other)
	{
		if (this->Frequency>other.Frequency)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool operator == (const Voice& other)
	{
		return ((this->Frequency == other.Frequency) && (this->lenght == other.lenght) && (this->Number == other.Number) && (this->Name == other.Name) && (this->Oktava == other.Oktava));
	}
private:
	double Frequency;
	int Number;
};

Voice::Voice()
{
	this->Number = 0;
	Frequency = 0;
}

Voice::Voice(double Frequency, int Number, string dataN, string dataO, double valueL) :Nota(dataN, dataO, valueL)
{
	this->Number = Number;
	this->Frequency = Frequency;
}

Voice::Voice(const Voice & other) :Nota(other.Name, other.Oktava, other.lenght)
{
	this->Number = other.Number;
	this->Frequency = other.Frequency;
}

Voice::~Voice()
{
}

class Picture : public Nota
{
public:
	Picture();
	Picture(int x, int y, int Number, double Frequency, string dataN, string dataO, double valueL);
	Picture(const Picture& other);
	~Picture();

	void PrintP()
	{
		this->Print();
		cout << "(" << x << "," << y << ")" << this->Number << endl;
	}

	bool operator == (const Picture& other)
	{
		return ((this->x == other.x) && (this->y == other.y) && (this->lenght == other.lenght) && (this->Number == other.Number) && (this->Name == other.Name) && (this->Oktava == other.Oktava));
	}

	friend ostream& operator<< (ostream& out, Picture& outstream);
	friend istream& operator>> (istream& in, Picture& instream);

private:
	int x, y;
	int  Number;
};

Picture::Picture()
{
	this->Number = 0;
	this->x = 0;
	this->y = 0;
}

Picture::Picture(int x, int y, int Number, double Frequency, string dataN, string dataO, double valueL) :Nota(dataN, dataO, valueL)
{
	this->x = x;
	this->Number = Number;
	this->y = y;
}

Picture::Picture(const Picture& other) :Nota(other.Name, other.Oktava, other.lenght)
{
	this->Number = other.Number;
	this->x = other.x;
	this->y = other.y;
}

Picture::~Picture()
{
}

ostream& operator << (ostream& out, Voice& outstream) {
	out << "Name: " << outstream.Name << endl;
	out << "Oktava: " << outstream.Oktava << endl;
	out << "Number: " << outstream.Number << endl;
	out << "lenght: " << outstream.lenght << endl;
	out << "Frequency: " << outstream.Frequency << endl;
	return out;
}

istream& operator >> (istream& in, Voice& instream) {
	cout << "Name" << endl;
	cout << "Oktava" << endl;
	cout << "Number" << endl;
	cout << "lenght" << endl;
	cout << "Frequency" << endl;
	in >> instream.Name;
	in >> instream.Oktava;
	in >> instream.Number;
	in >> instream.lenght;
	in >> instream.Frequency;
	return in;
}

ostream& operator << (ostream& out, Picture& outstream) {
	out << "Name: " << outstream.Name << endl;
	out << "Oktava: " << outstream.Oktava << endl;
	out << "Number: " << outstream.Number << endl;
	out << "lenght: " << outstream.lenght << endl;
	out << "(" << outstream.x << "," << outstream.y << ")" << endl;
	return out;
}

istream& operator >> (istream& in, Picture& instream) {
	cout << "Name" << endl;
	cout << "Oktava" << endl;
	cout << "Number" << endl;
	cout << "lenght" << endl;
	cout << "x" << endl;
	cout << "y" << endl;
	in >> instream.Name;
	in >> instream.Oktava;
	in >> instream.Number;
	in >> instream.lenght;
	in >> instream.x;
	in >> instream.y;
	return in;
}
int main()
{
	setlocale(LC_ALL, "RUS");
	double valueF1, valueF2;
	Nota q1;
	q1.Print();
	q1++;
	q1.Print();
	q1--;
	q1.Print();
	cout << endl << "End Nota test" << endl << endl;

	cout << "Enter 2 frequency " << endl;
	cin >> valueF1;
	cin >> valueF2;
	Voice V1(valueF1,0,"jbibib","jnjijnj",0);
	Voice V2(valueF2, 0, "jbibib", "jnjijnj", 0);
	bool b = V1 > V2;
	cout << "Operator >" << b << endl;
	bool a = V1 == V2;
	cout << "Operator ==" << a << endl;
	V1.PrintV();
	V2.PrintV();
	cin >> V1;
	cout << V1;
	cout << endl << "End voice test" << endl << endl;


	Picture P1,P2;
	bool c = P1 == P2;
	cout << "Operator ==" << c << endl;
	P1.PrintP();
	P2.PrintP();
	cin >> P1;
	cout << P1;
	cout << endl << "End picture test" << endl << endl;

	return 0;
}
