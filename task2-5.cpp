#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

class Nota
{
public:

	Nota();

	Nota(char* dataN, char* dataO, int valueL);

	~Nota();

	Nota& SetName(char* dataN)
	{
		char* Name = new char[strlen(dataN)+1];
		strcpy(Name, dataN);
		return *this;
	}

	char* GetName()
	{
		return Name;
	}

	Nota& SetOktava(char* dataO)
	{
		char* Name = new char[strlen(dataO)+1];
		strcpy(Name, dataO);
		return *this;
	}

	char* GetOktava()
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
		this->Name = new char[strlen(other.Name) + 1];
		strcpy(Name, other.Name);
		this->Oktava = new char[strlen(other.Oktava) + 1];
		strcpy(Oktava, other.Oktava);
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

private:
	char* Name;
	char* Oktava;
	int lenght;
};

Nota::Nota(char* dataN, char* dataO, int valueL)
{
	this->Name = new char[strlen(dataN) + 1];
	strcpy(this->Name, dataN);
	this->Oktava = new char[strlen(dataO) + 1];
	strcpy(this->Oktava, dataO);
	lenght = valueL;
}

Nota::Nota()
{
	this->Name = new char[7];
	strcpy(Name, "noname");
	this->Oktava = new char[7];
	strcpy(Oktava, "noname");
	lenght = 0;
}

Nota::~Nota()
{
	delete[] Name;
	delete[] Oktava;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	char Name[40], Oktava[40];
	int lenght;
	Nota q1;
	cout << "Enter name" << endl;
	cin >> Name;
	cout << "Enter oktava" << endl;
	cin >> Oktava;
	cout << "Enter lenght" << endl;
	cin >> lenght;
	Nota q2(Name,Oktava,lenght);
	Nota q3(q2);
	q1.Print();
	q2.Print2();
	q3.Print();
}
