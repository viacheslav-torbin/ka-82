#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

//---CLASS DATE---
class Date{
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
};

Date::Date(){
	day = 1; month = 1; year = 1970;

	cout<<"		[SYSTEM] Date default constructor\n";
}

Date::Date(int d, int m, int y){
	day = d; month = m; year = y;

	cout<<"		[SYSTEM] Date parametric constructor\n";
}

Date::Date(Date&d){
	day = d.day; month = d.month; year = d.year;

	cout<<"		[SYSTEM] Date copy constructor\n";
}

Date::~Date(){
	cout<<"		[SYSTEM] Date destructor\n";
}

void Date::print(){
	cout<<day<<"."<<month<<"."<<year<<"\n";
}

//---CLASS DESCRIPTION---
class Description{
	private:
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
};

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

	cout<<"		[SYSTEM] Description default constructor\n";
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

	cout<<"		[SYSTEM] Description parametric constructor\n";
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

	cout<<"		[SYSTEM] Description copy constructor\n";
}

Description::~Description(){
	if (country) delete[] country;
	if (climate) delete[] climate;
	if (species) delete[] species;
	if (genus) delete[] genus;
	if (family) delete[] family;

	cout<<"		[SYSTEM] Description destructor\n";
}

void Description::print_full(){
	cout<<country<<", "<<climate<<", "<<species<<" "<<genus<<" "<<family<<"\n";
}

void Description::print_short(){
	cout<<"Description: "<<species<<"\n";
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
	private:
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
};

Animal::Animal(){
	name = new char[40];
		strcpy(name, "NoName");
	age = 0;

	cout<<"		[SYSTEM] Animal default constructor\n";
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

	cout<<"		[SYSTEM] Animal parametric constructor\n";
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

	cout<<"		[SYSTEM] Animal copy constructor\n";
}

Animal::~Animal(){
	if (name) delete[] name;

	cout<<"		[SYSTEM] Animal destructor\n";
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
};

Domestic::Domestic(){
	owner = new char[40];
	strcpy(owner, "NoOwner");

	cout<<"		[SYSTEM] Domestic animal default constructor\n";
}

Domestic::Domestic(char *n, Description d, int a, char *own, Date vac): Animal(n, d, a){
	owner = new char[strlen(own)+1];
	strcpy(owner, own);
	vaccination.set_Day(vac.get_Day());
	vaccination.set_Month(vac.get_Month());
	vaccination.set_Year(vac.get_Year());

	cout<<"		[SYSTEM] Domestic animal parametric constructor\n";
}

Domestic::Domestic(Domestic&d): Animal(d.get_Name(), d.get_Descr(), d.get_Age()){
	owner = new char[strlen(d.owner)+1];
	strcpy(owner, d.owner);
	vaccination.set_Day(d.vaccination.get_Day());
	vaccination.set_Month(d.vaccination.get_Month());
	vaccination.set_Year(d.vaccination.get_Year());

	cout<<"		[SYSTEM] Domestic animal copy constructor\n";
}

Domestic::~Domestic(){
	if (owner) delete[] owner;

	cout<<"		[SYSTEM] Domestic destructor\n";
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

	cout<<"		[SYSTEM] Wild animal default constructor\n";
}

Wild::Wild(char *n, Description d, int a, char *z, int p, int i): price(p), id(i), Animal(n, d, a) {
	zoo = new char[strlen(z)+1];
	strcpy(zoo, z);

	cout<<"		[SYSTEM] Wild animal parametric constructor\n";
}

Wild::Wild(Wild&w): Animal(w.get_Name(), w.get_Descr(), w.get_Age()){
	zoo = new char[strlen(w.zoo)+1];
	strcpy(zoo, w.zoo);
	price = w.price;
	id = w.id;

	cout<<"		[SYSTEM] Wild animal copy constructor\n";
}

Wild::~Wild(){
	if (zoo) delete[] zoo;

	cout<<"[SYSTEM] Wild animal destructor\n";
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
	char country1[40], climate1[40], species1[40], genus1[40], family1[40];
	char name1[40]; int age1;
	char owner[40]; int day, month, year;

	Domestic dom1; 
	cout<<"\nDomestic animal 1: \n"; dom1.print();

	cout<<"Enter domestic animal 2 name: ";
		cin>>name1;
		cout<<"Enter age: ";
		cin>>age1;

		cout<<"Country of origin: ";
		cin>>country1;
		cout<<"Climate zone: ";
		cin>>climate1;
		cout<<"Species: ";
		cin>>species1;
		cout<<"Genus: ";
		cin>>genus1;
		cout<<"Family: ";
		cin>>family1;

	Description descr1(country1, climate1, species1, genus1, family1);

	cout<<"Owner address: ";
	fflush(stdin);
	gets(owner);

	cout<<"Enter vaccination date (D, M, Y) via space: ";
	cin>>day>>month>>year;
	Date vac(day, month, year);

	Domestic dom2(name1, descr1, age1, owner, vac);
	cout<<"\nDomestic animal 2: \n"; dom2.print();

	Domestic dom3(dom2);
	cout<<"\nDomestic animal 3 (as copy of 2): \n"; dom3.print();

	char name_new[40];
	cout<<"Enter new name for domestic animal 3:";
	cin>>name_new;
	cout<<"Enter new age: ";
	cin>>age1;
	cout<<"Enter new vaccination date: ";
	cin>>day>>month>>year;

	dom3.set_Name(name_new).set_Age(age1);
	vac.set_Day(day).set_Month(month).set_Year(year);
	dom3.set_Date(vac);

	cout<<"\nDomestic animal 3 (new): \n";
	dom3.print();

	//vars for wild animal
	char country2[40], climate2[40], species2[40], genus2[40], family2[40];
	char name2[40]; int age2;
	char zoo[40]; int price, id;

	Wild w1;
	cout<<"\nWild animal 1: \n"; w1.print();

	cout<<"Enter wild animal 2 name: ";
		cin>>name2;
		cout<<"Enter age: ";
		cin>>age2;

		cout<<"Country of origin: ";
		cin>>country2;
		cout<<"Climate zone: ";
		cin>>climate2;
		cout<<"Species: ";
		cin>>species2;
		cout<<"Genus: ";
		cin>>genus2;
		cout<<"Family: ";
		cin>>family2;

	Description descr2(country2, climate2, species2, genus2, family2);

	cout<<"Zoo address: ";
	fflush(stdin);
	gets(zoo);
	cout<<"Enter price and ID: ";
	cin>>price>>id;

	Wild w2(name2, descr2, age2, zoo, price, id);
	cout<<"\nWild animal 2: \n"; w2.print();

	Wild w3(w2);
	cout<<"\nWild animal 3 (as copy of 2): \n"; w3.print();

	char name_new2[40];
	cout<<"Enter new name for wild animal 3: ";
	cin>>name_new2;
	cout<<"Enter new age: ";
	cin>>age2;
	cout<<"Enter new ID: ";
	cin>>id;

	w3.set_Id(id).set_Name(name_new2).set_Age(age2);

	cout<<"\nDomestic animal 3 (new): \n";
	w3.print();


	system("pause");
	return 0;
}