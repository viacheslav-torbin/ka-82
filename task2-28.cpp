#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

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
		Description get_Descr(){return descr;}; 
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
		strcpy(name, "Noname");
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

int main(){
	char country[40], climate[40], species[40], genus[40], family[40];
	char name[40]; int age;
	Description D1;
	Animal An1;
		cout<<"Enter animal's name: ";
		cin>>name;
		cout<<"Enter animal's age: ";
		cin>>age;
		cout<<"Country of origin: ";
		cin>>country;
		cout<<"Climate zone: ";
		cin>>climate;
		cout<<"Species: ";
		cin>>species;
		cout<<"Genus: ";
		cin>>genus;
		cout<<"Family: ";
		cin>>family;
	Description D2(country, climate, species, genus, family);
	Animal An2(name, D2, age);
	Animal An3 = An2;
	
	cout<<"An1, An2, An3 before change:\n";
	An1.print_full();
	An2.print_full();
	An3.print_full();
	
	cout<<"\nEnter new description for An3:\n";
	cout<<"Name: ";
		cin>>name;
		cout<<"Age: ";
		cin>>age;
		cout<<"Country of origin: ";
		cin>>country;
		cout<<"Climate zone: ";
		cin>>climate;
		cout<<"Species: ";
		cin>>species;
		cout<<"Genus: ";
		cin>>genus;
		cout<<"Family: ";
		cin>>family;
	Description D3(country, climate, species, genus, family);
	An3.set_Name(name).set_Age(age).set_Descr(D3);
	
	cout<<"\nAn1, An2, An3 after change:\n";
	An1.print_full();
	An2.print_full();
	An3.print_full();
	
	cout<<"\nEnter animal number to increase its age: ";
	int ch; 
	choice: cin>>ch;
	switch (ch){
		case 1: {
			An1.add_Age();
			cout<<"New An1: \n";
			An1.print_full();
			break;
		}
		case 2: {
			An2.add_Age();
			cout<<"New An2: \n";
			An2.print_full();
			break;
		}
		case 3: {
			An3.add_Age();
			cout<<"New An3: \n";
			An3.print_full();
			break;
		}
		default: goto choice;
	}
	
	cout<<"\nAnimals info in short form:\n";
	An1.print_short();
	D1.print_short();
	An2.print_short();
	D2.print_full();
	An3.print_short();
	D3.print_full();
	
	system("pause");
	return 0;
}