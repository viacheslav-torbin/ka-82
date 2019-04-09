#include<iostream>
#include<math.h>
#include<string.h>
#include<fstream>

using namespace std;

class Product
{
protected:
	char* prodname_;
	int cost_, quant_;
public:
	Product()
	{
		this->prodname_ = new char[7];
		strcpy(prodname_, "noname");
		this->cost_ = 0;
		this->quant_ = 0;
	}
	Product(char* prodnameInput, int costInput, int numberInput, char* nameInput, char* contryInput, char* quantInput)
	{
		this->prodname_ = new char[strlen(prodnameInput) + 1];
		strcpy(prodname_, nameInput);
		cost_ = costInput;
		quant_ = numberInput;
	}
	Product(const Product& copy)
	{
		this->prodname_ = new char[strlen(copy.prodname_) + 1];
		strcpy(prodname_, copy.prodname_);
		this->cost_ = copy.cost_;
		this->quant_ = copy.quant_;
	}
	~Product()
	{
		delete[] this->prodname_;
	}

	char* getName() { return prodname_; }
	int getCost() { return cost_; }
	int getQuant() { return quant_; }

	Product& setName(char* nameInput)
	{
		this->prodname_ = new char[strlen(nameInput) + 1];
		strcpy(prodname_, nameInput);
		return *this;
	}
	Product& setCost(int costInput)
	{
		cost_ = costInput;
		return *this;
	}
	Product& setQuant(int quantInput)
	{
		quant_ = quantInput;
		return *this;
	}
	Product& Set()
	{
		this->cost_ = 0;
		this->quant_ = 0;
		this->prodname_ = new char[7];
		strcpy(prodname_, "noinfo");
		return *this;
	}

	Product operator +(const Product& other) { Product temp; temp.quant_ = this->quant_ + other.quant_; return temp; }
	Product& operator +(int value)
	{
		for (int i = 0; i < value; i++)
		{
			this->quant_++;
		}
		return *this;
	}
	Product& operator ++() { this->quant_++; return *this; }
	Product operator ++(int value) { Product temp(*this); this->quant_++; return temp; }
	bool operator ==(const Product& other) { return ((this->cost_ == other.cost_) && (this->quant_ == other.quant_) && !(strcmp(this->prodname_, other.prodname_))); }
	bool operator <(const Product& other) { return (this->cost_ < other.cost_); }
	friend ostream& operator<< (ostream& out, Product& outstream);
	friend istream& operator>> (istream& in, Product& instream);
	Product& operator = (Product other)
	{
		delete[] this->prodname_;
		this->prodname_ = new char[strlen(other.prodname_) + 1];
		this->cost_ = other.cost_;
		strcpy(this->prodname_, other.prodname_);
		this->quant_ = other.quant_;
		return *this;
	}

	void Print()
	{
		cout << "Name: " << this->prodname_ << "\t" << "Cost: " << this->cost_ << "\t" << "quant: " << this->quant_ << endl;
	}
	virtual void PrintName()
	{
		cout << "Name: " << this->prodname_ << endl;
	}
	void Alarm() { cout << "Product" << endl; }
};

template <typename T>

int CheckMass(T a[], int size, T ch)
{
	int q;
	for (int i = 0; i < size; i++)
	{
		if (a[i] > ch)
			q++;
	}
	return q;
}

int main()
{
	int size,ch1;
	Product* mass = new Product[size];
	int * intmass = new int[size];
}
