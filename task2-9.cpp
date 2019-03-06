#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

class Address
{
	char * city;
	char * street;
	int number;
	
	public:
		/* constructors & destructors */
		Address(const char*city,const char*street,int number);
		Address():Address("Default city","Default street",-1){};
		Address(const Address &adr):Address(adr.city,adr.street,adr.number){}; //copy constructor;
		~Address();	//destructor
		
		/* methods */
		const char* getCity(){return city;};
		const char* getStreet(){return street;};
		int getNumber(){return number;};
		
		Address& setCity(const char*city);
		Address& setStreet(const char*street);
		Address& setNumber(int number);
		
		void linePrint(){
			printf("%s %s %d\n",this->city, this->street, this->number);};
			
		void objPrint(){
			printf("Adress: %s, %d\n",this->street, this->number);};
			
		Address& operator =(Address adr)
		{
			this->setCity(adr.city);
			this->setStreet(adr.street);
			this->setNumber(adr.number);
			return *this;
		}

};
	
	Address::Address(const char* city ,const char* street, int number)
	{
		this->city = new char[strlen(city)];
		strcpy(this->city,city);
		
		this->street = new char[strlen(street)];
		strcpy(this->street,street);
		
		this->number = number;
	}
	
	Address::~Address()
	{
		delete [] this->city;
		delete [] this->street;
	}
	
	/* setters */
	Address& Address::setCity(const char*city)
	{
		delete [] this->city;
		this->city = new char[strlen(city)];
		strcpy(this->city,city);
		return *this;
	}
	
	Address& Address::setStreet(const char*street)
	{
		delete [] this->street;
		this->street = new char[strlen(street)];
		strcpy(this->street,street);
		return *this;
	}
	
	Address& Address::setNumber(int n)
	{
		this->number=n;
		return *this;
	}


class Exhibit
{
	char * name;
	int length, width, height;
	Address address;
	
	public:
		/* constructors & destructors */
		Exhibit(const char*,int,int,int,Address);
		Exhibit():Exhibit("Thing",0,0,0,Address()){};
		Exhibit(const Exhibit&e):Exhibit(e.name,e.length,e.width,e.height,e.address){};
		~Exhibit();
		
		/* methods */
		int getLength(){return length;};
		int getWidth(){return width;};
		int getHeight(){return height;};
		const char* getName(){return name;};
		const Address getAddress(){return address;};
		
		Exhibit& setLength(int);
		Exhibit& setWidth(int);
		Exhibit& setHeight(int);
		Exhibit& setName(const char*);
		Exhibit& setAddress(const Address);
		
		void linePrint(){
			printf("%s %d %d %d ",this->name, this->length, this->width, this->height);
			address.linePrint();};
			
		void objPrint(){
			printf("exhibit %s\n",this->name);};
			
};

Exhibit::Exhibit(const char*name, int l, int w, int h, Address adr)
{
	this->name = new char[strlen(name)];
	strcpy(this->name,name);
	this->length = l;
	this->width = w;
	this->height = h;
	this->address = adr;
}

Exhibit::~Exhibit()
{
	delete [] name;
}

/* setters */
Exhibit& Exhibit::setLength(int l)
{
	this->length = l;
	return *this;
}

Exhibit& Exhibit::setWidth(int w)
{
	this->width = w;
	return *this;
}

Exhibit& Exhibit::setHeight(int h)
{
	this->height = h;
	return *this;
}

Exhibit& Exhibit::setName(const char* name)
{
	strcpy(this->name,name);
	return *this;
}

Exhibit& Exhibit::setAddress(const Address adr)
{
	this->address = adr;
	return *this;
}





/************************************************************************************************************/
int main()
{
	puts("Firstly, let's create an adress object with parameterized constructor.\nEnter city, street and number:");
	
	char city[40];		gets(city);
	char street[40];	gets(street);
	int number;			scanf("%d",&number);
	
	Address adr1(city,street,number);
	adr1.linePrint();
	
	puts("\nSecond object will be created with default constructor");
	Address adr2;
	adr2.objPrint();
	
	puts("\nThird object will be created with copy constructor");
	Address adr3 = adr1;
	adr3.linePrint();
	
	puts("\nChanging properties");
	adr3.setCity("Kharkiv");
	adr3.setStreet("Shevchenka");
	adr3.setNumber(12);
	adr3.linePrint();
	
	puts("\nPress any key...");
	getch();
	system("cls");
	getchar();
	
	
	puts("Exhibit class\nFirst object will be created with parameterized constructor\nEnter name and size(l,w,h):");
	char name[40];		gets(name);
	int l,w,h;			scanf("%d%d%d",&l,&w,&h);
	Exhibit exhibit1(name,l,w,h,adr1);
	exhibit1.objPrint();
	
	puts("\nSecond object will be created with default constructor");
	Exhibit exhibit2;
	exhibit2.linePrint();
	
	puts("\nThird object will be created with copy constructor");
	Exhibit exhibit3 = exhibit1;
	exhibit3.linePrint();
	
}
