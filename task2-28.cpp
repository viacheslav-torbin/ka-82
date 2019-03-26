#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class description{

  char  *country,*climate,*species,*genus,*family;
  public:
    description();
    description(char*,char*,char*,char*,char*);
    ~description();
    description(description & obj): country(obj.country),climate(obj.climate),species(obj.species),genus(obj.genus),family(obj.family){cout<<"description constructor copy"<<endl;}
    char * get_country(){return country;};
    char * get_climate(){return climate;};
    char * get_species(){return species;};
    char * get_genus(){return genus;};
    char * get_family(){return family;};
    description& set_country(char*);
    description& set_climate(char*);
    description& set_biolagy_characteristics(char*,char*,char*);
        void print(){cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\ncountry-"<<country<<"\nclimate-"<<climate<<"\nbiolagy_characteristics:\nfamily-"<<family<<"\ngenus-"<<genus<<"\nspecies-"<<species<<"\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;}

};

description::description(char* co,char* cl,char* sp,char* ge,char* fa)
{
  country=new char[strlen(co)+1];
  climate=new char[strlen(cl)+1];
  species=new char[strlen(sp)+1];
  genus=new char[strlen(ge)+1];
  family=new char[strlen(fa)+1];
  strcpy(country,co);
  strcpy(climate,cl);
  strcpy(species,sp);
  strcpy(genus,ge);
  strcpy(family,fa);
  cout<<"description param constructor"<<endl;
}
description::description()
{
  country=new char[10];
  climate=new char[10];
  species=new char[10];
  genus=new char[8];
  family=new char[9];
  strcpy(country,"nocountry");
  strcpy(climate,"noclimate");
  strcpy(species,"nospecies");
  strcpy(genus,"nogenus");
  strcpy(family,"nofamily");
  cout<<"description default constructor"<<endl;
}
description::~description()
{
  if(country) delete[] country;
  if(climate) delete[]climate;
  if(species) delete[] species;
  if(genus) delete[] genus;
  if(family) delete[] family;
  cout<<"description default destructor"<<endl;
}
description& description::set_climate(char* cl)
{
  climate=new char[strlen(cl)+1];
  strcpy(climate,cl);
  return *this;
}
description& description::set_country(char* co)
{
  country=new char[strlen(co)+1];
  strcpy(country,co);
  return *this;
}
description& description::set_biolagy_characteristics(char* sp,char* ge,char* fa)
{
  species=new char[strlen(sp)+1];
  genus=new char[strlen(ge)+1];
  family=new char[strlen(fa)+1];
  strcpy(species,sp);
  strcpy(genus,ge);
  strcpy(family,fa);
  return *this;
}

class animal{
  char * name;
  description desc;
  int age;
public:
  animal();
  animal(description ,int,char*);
  ~animal();
  animal(animal&);
  char * get_name(){return name;};
  int  get_age(){return age;};
  description  get_description(){return desc;}
  char* get_country(){return desc.get_country();}
  void print(){cout<<"|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\nanimal name is "<<name<<"\nanimal age is "<<age<<"\ndescription:\ncountry-"<<desc.get_country()<<"\nclimate-"<<desc.get_climate()<<"\nbiolagy_characteristics:\nfamily-"<<desc.get_family()<<"\ngenus-"<<desc.get_genus()<<"\nspecies-"<<desc.get_species()<<"\n|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<endl;}
  void set_name(char*);
  void set_age(int);
  void set_description(char*,char*,char*,char*,char*);
  animal&  add_year(){age++;return *this;};
};

animal::animal()
{
  name=new char[7];
  strcpy(name,"noname");
	this->desc = description();
	this->age = -1;
  cout<<"animal default constructor"<<endl;
}
animal::animal(description descr,int a,char* n):/*desc(descr),*/age(a)
{
  name=new char[sizeof(n)+1];
  strcpy(name,n);
  this->desc=descr;
  cout<<"animal param constructor"<<endl;
}
animal::~animal()
{
  /*desc.~description();*/
  if(name) delete[] name;
  cout<<"animal default destructor"<<endl;
}
animal::animal(animal & a)
{
  cout<<"animal constructor copy"<<endl;
  name=new char[sizeof(a.name)+1];
  strcpy(name,a.name);
	this->age = a.age;
	this->desc.set_country(a.desc.get_country());
  this->set_description(a.desc.get_country(),a.desc.get_climate(),a.desc.get_species(),a.desc.get_genus(),a.desc.get_family());
}
void animal::set_name(char* n)
{
  name=new char[strlen(n)+1];
  strcpy(name,n);
}
void animal::set_age(int a){age=a;}
void animal::set_description(char* con,char* cli,char* spe,char* gen,char* fam)
{
  desc.set_country(con);
  desc.set_climate(cli);
  desc.set_biolagy_characteristics(spe,gen,fam);
}

  int main()
  {
  description h("USA","temperate climate","lagopus","Vulpes","Canidae"),f/*,j(h),d,*/;
  animal b(h,9,"arctic fox"),a,c(b);
  // d.print();
  // h.print();
  // j.print();
  // d.set_country("Ukraine");
  // d.set_climate("temperate climate");
  // d.set_biolagy_characteristics("lupus","Canis","Canidae");
  // cout<<d.get_climate()<<"\n"<<d.get_country()<<"\n"<<d.get_species()<<"\n"<<d.get_genus()<<"\n"<<d.get_family()<<endl;
  // d.print();

  a.print();
  b.print();
  c.add_year();
  c.print();

  a.set_age(15);
  a.set_name("wolf");
  a.set_description("Ukraine","temperate climate","lupus","Canis","Canidae");
  f=a.get_description();
  cout<<a.get_age()<<"\n"<<a.get_name()<<"\n"<<f.get_climate()<<"\n"<<f.get_country()<<"\n"<<f.get_species()<<"\n"<<f.get_genus()<<"\n"<<f.get_family()<<endl;
  a.print();
  return 0;
  }
