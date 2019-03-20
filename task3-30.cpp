#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdio>
#include <stdio.h>
using namespace std;

class Publisher {
private:
	char *company;
	char *number;
	char *address;
public:
	Publisher();
	Publisher(char*, char*, char*);
	~Publisher();
	Publisher(Publisher& publ) :Publisher(publ.company, publ.number, publ.address) {};

	char* getCompany();
	char* getNumber();
	char* getAddress();
	void linePrint() {
		cout << "Company: " << company << "\nNumber: " << number << "\nAddress: " << address << endl;
	}
	void specialPrint() {
		cout << "Publisher: " << company << endl;
	}


	Publisher& setCompany(char*);
	Publisher& setNumber(char*);
	Publisher& setAddress(char*);

};
class PublishingHouse {
private:
	char *name;

	int price, number_of_papers, code;
	Publisher publisher;
public:
	PublishingHouse();
	~PublishingHouse();
	PublishingHouse(char*, int, int, int, Publisher);
	PublishingHouse(PublishingHouse& house) :PublishingHouse(house.name, house.price, house.number_of_papers, house.code, house.publisher) {};

	void line_print() {
		cout << "Name: " << name << "\nPrice: " << price << "\nNumber of papers: " << number_of_papers << "\nCode: " << code << endl;
		publisher.linePrint();
	}
	void special_print() {
		cout << "Publishing house: " << name << endl;
	}
	char* getName() {
		return name;
	}
	int getPrice() {
		return price;
	}
	int getPapers() {
		return number_of_papers;
	}
	int getCode() {
		return code;
	}
	Publisher getPublisher() {
		return publisher;
	}
	PublishingHouse& setName(char*);
	PublishingHouse& setPrice(int);
	PublishingHouse& setPapers(int);
	PublishingHouse& setCode(int);
	PublishingHouse& setPublisher(char*, char*, char*);

};
PublishingHouse& PublishingHouse::setName(char* n) {
	delete[] name;
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	return *this;
}
PublishingHouse& PublishingHouse::setPrice(int p) {
	price = p;
	return *this;
}
PublishingHouse& PublishingHouse::setPapers(int pap) {
	number_of_papers = pap;
	return *this;
}
PublishingHouse& PublishingHouse::setCode(int c) {
	code = c;
	return *this;
}
PublishingHouse& PublishingHouse::setPublisher(char* a, char *b, char *c) {
	publisher.setCompany(a);
	publisher.setNumber(b);
	publisher.setAddress(c);
	return *this;
}
PublishingHouse::PublishingHouse() :publisher()
{
	delete[] name;
	name = new char[7];
	strcpy(name, "noname");
	price = -1;
	number_of_papers = -1;
	this->code = -1;
}
PublishingHouse::~PublishingHouse() {
	delete[] name;
	cout << "sdjf";
}
PublishingHouse::PublishingHouse(char*n, int p, int num, int code, Publisher publ) :publisher(publ)
{
	name = new char[strlen(n) + 1];
	strcpy(name, n);
	price = p;
	number_of_papers = num;
	this->code = code;
}
Publisher& Publisher::setCompany(char*c) {
	delete[] company;
	company = new char[strlen(c) + 1];
	strcpy(company, c);
	return *this;
}
Publisher& Publisher::setNumber(char*n) {
	delete[] number;
	number = new char[strlen(n) + 1];
	strcpy(number, n);
	return *this;
}
Publisher& Publisher::setAddress(char*a) {
	delete[] address;
	address = new char[strlen(a) + 1];
	strcpy(address, a);
	return *this;
}
char* Publisher::getCompany() {
	return company;
}
char* Publisher::getNumber() {
	return number;
}
char* Publisher::getAddress() {
	return address;
}
Publisher::Publisher(char *c, char *n, char *a) {
	company = new char[strlen(c) + 1];
	number = new char[strlen(n) + 1];
	address = new char[strlen(a) + 1];
	strcpy(company, c);
	strcpy(number, n);
	strcpy(address, a);
}
Publisher::~Publisher() {
	delete[] company;
	delete[] number;
	delete[] address;
}
Publisher::Publisher() {
	char a[8] = "no name";
	char b[10] = "no number";
	char c[11] = "no address";
	company = new char[9];
	strcpy(company, a);
	number = new char[11];
	strcpy(number, b);
	address = new char[12];
	strcpy(address, c);
}
class Periodic :public PublishingHouse {
private:
	int periodicity;
	char * category;
	int edition;
public:
	Periodic();
	~Periodic();
	void printPeriod() {
		line_print();
		cout << "per: " << periodicity << " categ: " << category << " edition: " << edition << endl;
	}
};
Periodic::Periodic() {
	periodicity = -1;
	delete[] category;
	category = new char[11];
	strcpy(category, "no category");
	edition = -1;
}
Periodic::~Periodic() {
	delete[] category;
	cout << "";
}
int main() {
	Periodic a1;
	a1.printPeriod();
	return 0;
}
