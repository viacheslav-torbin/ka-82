#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Location {
	float x;
	float y;
	int type;

public:

	Location()
	{
		this->x = 0;
		this->y = 0;
		this->type = 0;
	}

	Location(float x, float y, int ptype)
	{
		this->x = x;
		this->y = y;
		this->type = ptype;
	}

	~Location()
	{
	}

	Location(const Location & copy)
	{
		this->x = copy.x;
		this->y = copy.y;
		this->type = copy.type;
	}

	void SetX(float x)
	{
		this->x = x;
	}

	float GetX()
	{
		return this->x;
	}

	void SetY(float y)
	{
		this->y = y;
	}

	float GetY()
	{
		return this->y;
	}

	void SetType(int type)
	{
		this->type = type;
	}

	int GetType()
	{
		return this->type;
	}

	void Print1()
	{
		cout << this->GetX() << "\t" << this->GetY() << "\t" << this->GetType() << endl;
	}

	void Print2()
	{
		cout << "Location" << "\t" << this->GetType() << endl;
	}
};

class Product
{
	char* name;
	float price;
	int quantity;
	Location location;

public:

	Product()
	{
		Location location;
		name = new char[7];
		strcpy(this->name, "Noname");
		this->price = 0;
		this->quantity = 0;
	}

	Product(float x, float y, int type, char* pname, float price, int quantity) :location(x, y, type)
	{
		name = new char[strlen(pname) + 1];
		this->price = price;
		this->quantity = quantity;
		strcpy(this->name, pname);
	}

	~Product()
	{
		delete[] name;

	}

	Product(const Product & copy)
	{
		name = new char[strlen(copy.name) + 1];
		this->price = copy.price;
		this->quantity = copy.quantity;
		strcpy(this->name, copy.name);
		this->location = copy.location;
	}

	void SetPrice(float price)
	{
		this->price = price;
	}

	float GetPrice()
	{
		return this->price;
	}

	void SetQuantity(int quantity)
	{
		this->quantity = quantity;
	}

	int GetQuantity()
	{
		return this->quantity;
	}

	void SetName(char* pname)
	{
		this->name = new char[strlen(pname) + 1];
		strcpy(this->name, pname);
	}

	char* GetName()
	{
		return this->name;
	}

	void Print_all()
	{
		this->location.Print1();
		cout << this->GetName() << "\t" << this->GetPrice() << "\t" << this->GetQuantity() << endl;
	}

	void Print_main()
	{
		this->location.Print2();
		cout << "Product" << "\t" << this->GetName() << endl;
	}
};

int main()
{

	setlocale(LC_ALL, "RUS");
	int types;
	float x, y, price;

	Location L1;
	cout << "Enter X, Y, type" << endl;
	cin >> x;
	cin >> y;
	cin >> types;
	Location L2(x, y, types);
	Location L3(L2);
	L1.Print1();
	L2.Print2();
	L3.Print1();

	char pname[40];
	int quan;
	Product P1;
	cout << "Enter X,Y, type, name, quan, price" << endl;
	cin >> x;
	cin >> y;
	cin >> types;
	cin >> pname;
	cin >> price;
	cin >> quan;
	Product P2(x, y, types, pname, price, quan);
	Product P3(P2);
	P1.Print_all();
	P2.Print_main();
	P3.Print_all();
	system("pause");
	return 0;
}
