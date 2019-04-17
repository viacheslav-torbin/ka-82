#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

//---CLASS DATE---
class Date{
	protected:
		int day, month, year;
	public:
		Date();
		Date(int d, int m, int y);
		Date(Date&d);
		~Date();
		Date& set_Day(int d){day = d; return *this;};
		Date& set_Month(int m){month = m; return *this;};
		Date& set_Year(int y){year = y; return *this;};
		int get_Day(){return day;};
		int get_Month(){return month;};
		int get_Year(){return year;};
		void print();

		friend ostream& operator<<(ostream&, Date&);
		friend istream& operator>>(istream&, Date&);
		Date& operator=(Date&);
};

// overloaded cout
ostream& operator<<(ostream &out, Date &d){
	out<<d.day<<"."<<d.month<<"."<<d.year<<endl;
	return out;
}
// overloaded cin
istream& operator>>(istream &in, Date &d){
	in>>d.day>>d.month>>d.year;
	return in;
}

// overloaded =
Date& Date::operator=(Date&d){
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;

}

Date::Date(){
	day = 1; month = 1; year = 1970;
}

Date::Date(int d, int m, int y){
	day = d; month = m; year = y;
}

Date::Date(Date&d){
	day = d.day; month = d.month; year = d.year;
}

Date::~Date(){
}

void Date::print(){
	cout<<day<<"."<<month<<"."<<year<<endl;
}

//---CLASS DESCRIPTION---
class Description{
	protected:
		char *country, *climate;
		char *species, *genus, *family;
	public:
		Description();
		Description(char *cntry, char *clm, char *sp, char *g, char *f);
		Description(Description&d);
		~Description();
		char *get_Country(){return country;};
		char *get_Climate(){return climate;};
		char *get_Species(){return species;};
		char *get_Genus(){return genus;};
		char *get_Family(){return family;};
		void print_full();
		void print_short();
		Description& set_Country(char *cntry);
		Description& set_Climate(char *clm);
		Description& set_Species(char *sp);
		Description& set_Genus(char *g);
		Description& set_Family(char *f);

		bool operator==(Description&);
		friend ostream& operator<<(ostream&, Description&);
		friend istream& operator>>(istream&, Description&);
		Description& operator=(Description&);
};

// overloaded ==
bool Description::operator==(Description&d){
	return !(strcmp(this->country, d.country)&&strcmp(this->climate, d.climate)&&strcmp(this->species, d.species)&&strcmp(this->genus, d.genus)&&strcmp(this->family, d.family));
}
// overloaded cout
ostream& operator<<(ostream &out, Description &d){
	out<<d.country<<", "<<d.climate<<", "<<d.species<<" "<<d.genus<<" "<<d.family;
	return out;
}
// overloaded cin
istream& operator>>(istream &in, Description &d){
	in>>d.country>>d.climate>>d.species>>d.genus>>d.family;
	return in;
}
// overloaded =
Description& Description::operator=(Description&d){
	country = new char[strlen(d.country)+1];
		strcpy(country, d.country);
	climate = new char[strlen(d.climate)+1];
		strcpy(climate, d.climate);
	species = new char[strlen(d.species)+1];
		strcpy(species, d.species);
	genus = new char[strlen(d.genus)+1];
		strcpy(genus, d.genus);
	family = new char[strlen(d.family)+1];
		strcpy(family, d.family);

	return *this;
}

Description::Description(){
	country = new char[40];
		strcpy(country, "Country");
	climate = new char[40];
		strcpy(climate, "Climate");
	species = new char[40];
		strcpy(species, "Species");
	genus = new char[40];
		strcpy(genus, "Genus");
	family = new char[40];
		strcpy(family, "Family");
}

Description::Description(char *cntry, char *clm, char *sp, char *g, char *f){
	country = new char[strlen(cntry)+1];
		strcpy(country, cntry);
	climate = new char[strlen(clm)+1];
		strcpy(climate, clm);
	species = new char[strlen(sp)+1];
		strcpy(species, sp);
	genus = new char[strlen(g)+1];
		strcpy(genus, g);
	family = new char[strlen(f)+1];
		strcpy(family, f);
}

Description::Description(Description&d){
	country = new char[strlen(d.country)+1];
		strcpy(country, d.country);
	climate = new char[strlen(d.climate)+1];
		strcpy(climate, d.climate);
	species = new char[strlen(d.species)+1];
		strcpy(species, d.species);
	genus = new char[strlen(d.genus)+1];
		strcpy(genus, d.genus);
	family = new char[strlen(d.family)+1];
		strcpy(family, d.family);
}

Description::~Description(){
	if (country) delete[] country;
	if (climate) delete[] climate;
	if (species) delete[] species;
	if (genus) delete[] genus;
	if (family) delete[] family;
}

void Description::print_full(){
	cout<<country<<", "<<climate<<", "<<species<<" "<<genus<<" "<<family<<endl;
}

void Description::print_short(){
	cout<<"Description: "<<species<<endl;
}

Description& Description::set_Country(char *cntry){
	delete[] country;
	country = new char[strlen(cntry)+1];
	strcpy(country, cntry);
	return *this;
}
Description& Description::set_Climate(char *clm){
	delete[] climate;
	climate = new char[strlen(clm)+1];
	strcpy(climate, clm);
	return *this;
}
Description& Description::set_Species(char *sp){
	delete[] species;
	species = new char[strlen(sp)+1];
	strcpy(species, sp);
	return *this;
}
Description& Description::set_Genus(char *g){
	delete[] genus;
	genus = new char[strlen(g)+1];
	strcpy(genus, g);
	return *this;
}
Description& Description::set_Family(char *f){
	delete[] family;
	family = new char[strlen(f)+1];
	strcpy(family, f);
	return *this;
}

//---CLASS ANIMAL--
class Animal{
	protected:
		char *name;
		Description descr;
		int age;
	public:
		Animal();
		Animal(char *n, Description d, int a);
		Animal(Animal&a);
		~Animal();
		char *get_Name(){return name;};
		Description& get_Descr(){return descr;}; 
		int get_Age(){return age;};
		void print_full();
		void print_short();
		Animal& set_Name(char *n);
		Animal& set_Descr(Description d);
		Animal& set_Age(int a);
		void add_Age() {age++;};

		Animal operator++(int);
		bool operator<(Animal&);
		bool operator==(Animal&);
		friend ostream& operator<<(ostream&, Animal&);
		friend istream& operator>>(istream&, Animal&);
		Animal& operator=(Animal&);
};
// overloaded ++
Animal Animal::operator++(int a){
	Animal old(*this);
	this->age++;
	return old;
}
// overloaded <
bool Animal::operator<(Animal&b){
	return (this->age < b.age);
}
// overloaded ==
bool Animal::operator==(Animal&b){
	return (!(strcmp(this->name, b.name))&&(this->age == b.age)&&(this->descr == b.descr));
}
// overloaded cout
ostream& operator<<(ostream &out, Animal &a){
	out<<a.name<<", "<<a.age<<"\n"<<a.descr;
	return out;
}
// overloaded cin
istream& operator>>(istream &in, Animal &a){
	in>>a.name>>a.descr>>a.age;
	return in;
}
// overloaded =
Animal& Animal::operator=(Animal&a){
	name = new char[strlen(a.name)+1];
	strcpy(name, a.name);
	descr = a.descr;
	age = a.age;
}

Animal::Animal(){
	name = new char[40];
		strcpy(name, "NoName");
	age = 0;
}

Animal::Animal(char *n, Description d, int a){
	name = new char[strlen(n)+1];
	strcpy(name, n);
	descr.set_Country(d.get_Country());
	descr.set_Climate(d.get_Climate());
	descr.set_Species(d.get_Species());
	descr.set_Genus(d.get_Genus());
	descr.set_Family(d.get_Family());
	age = a;
}

Animal::Animal(Animal&a){
	name = new char[strlen(a.name)+1];
	strcpy(name, a.name);
	descr.set_Country(a.descr.get_Country());
	descr.set_Climate(a.descr.get_Climate());
	descr.set_Species(a.descr.get_Species());
	descr.set_Genus(a.descr.get_Genus());
	descr.set_Family(a.descr.get_Family());
	age = a.age;
}

Animal::~Animal(){
	if (name) delete[] name;
}

void Animal::print_full(){
	cout<<name<<", "<<age<<"\n";
	descr.print_full();
}

void Animal::print_short(){
	cout<<"Animal: "<<name<<"\n";
}

Animal& Animal::set_Name(char *n){
	delete[] name;
	name = new char[strlen(n)+1];
	strcpy(name, n);
	return *this;
}

Animal& Animal::set_Descr(Description d){
	descr.set_Country(d.get_Country());
	descr.set_Climate(d.get_Climate());
	descr.set_Species(d.get_Species());
	descr.set_Genus(d.get_Genus());
	descr.set_Family(d.get_Family());
	return *this;
}

Animal& Animal::set_Age(int a){
	age = a;
	return *this;
}

//---CLASS DOMESTIC---
class Domestic: public Animal{
	protected:
		char *owner;
		Date vaccination;
	public:
		Domestic();
		Domestic(char *n, Description d, int a, char *own, Date vac);
		Domestic(Domestic&d);
		~Domestic();
		char *get_Owner(){return owner;};
		Date &get_Date(){return vaccination;};
		Domestic& set_Owner(char *own);
		Domestic& set_Date(Date vac);
		void print();

		friend ostream& operator<<(ostream&, Domestic&);
		friend istream& operator>>(istream&, Domestic&);
		Domestic& operator=(Domestic&);
};

// overloaded cout
ostream& operator<<(ostream &out, Domestic &d){
	out<<d.name<<", "<<d.age<<"\n"<<d.descr<<"\n"<<"Owner address: "<<d.owner<<"\nVaccination date: "<<d.vaccination;
	return out;
}
// overloaded cin
istream& operator>>(istream &in, Domestic &d){
	in>>d.name>>d.age>>d.descr>>d.owner>>d.vaccination;
	return in;
}
// overloaded =
Domestic& Domestic::operator=(Domestic&d){
	name = new char[strlen(d.name)+1];
	strcpy(name, d.name);
	descr = d.descr;
	age = d.age;
	owner = new char[strlen(d.owner)+1];
	strcpy(owner, d.owner);
	vaccination = d.vaccination;

	return *this;
}

Domestic::Domestic(){
	owner = new char[40];
	strcpy(owner, "NoOwner");
}

Domestic::Domestic(char *n, Description d, int a, char *own, Date vac): Animal(n, d, a){
	owner = new char[strlen(own)+1];
	strcpy(owner, own);
	vaccination.set_Day(vac.get_Day());
	vaccination.set_Month(vac.get_Month());
	vaccination.set_Year(vac.get_Year());
}

Domestic::Domestic(Domestic&d): Animal(d.get_Name(), d.get_Descr(), d.get_Age()){
	owner = new char[strlen(d.owner)+1];
	strcpy(owner, d.owner);
	vaccination.set_Day(d.vaccination.get_Day());
	vaccination.set_Month(d.vaccination.get_Month());
	vaccination.set_Year(d.vaccination.get_Year());
}

Domestic::~Domestic(){
	if (owner) delete[] owner;
}

Domestic& Domestic::set_Owner(char *own){
	delete[] owner;
	owner = new char[strlen(own)+1];
	strcpy(owner, own);

	return *this;
}

Domestic& Domestic::set_Date(Date vac){
	vaccination.set_Day(vac.get_Day());
	vaccination.set_Month(vac.get_Month());
	vaccination.set_Year(vac.get_Year());

	return *this;
}

void Domestic::print(){
	Animal::print_full();
	cout<<"Owner address: "<<owner<<"\nVaccination date: ";
	vaccination.print(); cout<<"\n";
}
//---CLASS WILD---
class Wild: public Animal{
		char *zoo;
		int price, id;
	public:
		Wild();
		Wild(char *n, Description d, int a, char *z, int p, int i);
		Wild(Wild&w);
		~Wild();
		char *get_Address(){return zoo;};
		int get_Price(){return price;};
		int get_Id(){return id;};
		Wild& set_Address(char *z);
		Wild& set_Price(int p){price = p; return *this;};
		Wild& set_Id(int i){id = i; return *this;};
		void print();
};

Wild::Wild(){
	zoo = new char[40];
	strcpy(zoo, "NoZoo");
	price = 0; id = 0;
}

Wild::Wild(char *n, Description d, int a, char *z, int p, int i): price(p), id(i), Animal(n, d, a) {
	zoo = new char[strlen(z)+1];
	strcpy(zoo, z);
}

Wild::Wild(Wild&w): Animal(w.get_Name(), w.get_Descr(), w.get_Age()){
	zoo = new char[strlen(w.zoo)+1];
	strcpy(zoo, w.zoo);
	price = w.price;
	id = w.id;
}

Wild::~Wild(){
	if (zoo) delete[] zoo;
}

Wild& Wild::set_Address(char *z){
	delete[] zoo;
	zoo = new char[strlen(z)+1];
	strcpy(zoo, z);

	return *this;
}

void Wild::print(){
	Animal::print_full();
	cout<<"Zoo: "<<zoo<<"\nPrice: "<<price<<"\nID: "<<id<<"\n";
}

int main(){
	// vars for domestic animal
	char country1[40] = "Ukraine", 
	climate1[40] = "Continental", 
	species1[40] = "C.Lupus", 
	genus1[40] = "Canis", 
	family1[40] = "Canidae";
	char name1[40] = "Bob"; 
	int age1 = 3;
	char owner[40] = "Kyiv"; int day=31, month=8, year=2018;


	Description descr1(country1, climate1, species1, genus1, family1);

	Date vac(day, month, year);

	Domestic dom1(name1, descr1, age1, owner, vac);
	Domestic dom2; dom2 = dom1;
	cout<<"Domestic animal 1: \n"<<dom1<<endl;
	dom1++;
	cout<<"Domestic animal 1 (++): \n"<<dom1<<endl;

	cout<<"Domestic animal 2 = initial Domestic animal 1:"<<endl;
	cout<<dom2<<endl;
	cout<<"Domestic animal 2 < Domestic animal 1? "<<(dom2<dom1)<<endl;
	cout<<"Domestic animal 2 == Domestic animal 1? "<<(dom2==dom1)<<endl<<endl;

	Domestic dom3;
	cout<<"Domestic animal 3:"<<endl;
	cout<<"Enter name, age, country, climate, species, genus, family, owner, date (3 int)"<<endl;
	cin>>dom3;
	cout<<dom3;

	system("pause");
	return 0;
}