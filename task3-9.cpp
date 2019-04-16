#include <iostream>
#define _KP3_
#include "task2-9.cpp"

using namespace std;

class Artwork : public Exhibit
{
	private:
		int year;
		int price;
		char* author;
		
	public:
		Artwork(const char*,int,int,int,const char*,const char*,int,int,int,const char*);
		Artwork():Artwork("default name",0,0,0,"Default city","Default street",-1,1900,0,"unknown"){};
		Artwork(const Artwork&a);
		~Artwork();
		void linePrint();
		
		int getYear(){return year;}
		int getPrice(){return price;}
		const char* getAuthor(){return author;}
		
		Artwork& setYear(int y){year=y; return *this;}
		Artwork& setPrice(int p){price=p; return *this;}
		Artwork& setAuthor(char* author)
			{
				delete [] author;
				this->author = new char[strlen(author)+1];
				strcpy(this->author,author);
				return *this;
			}
};

Artwork::Artwork(const char*name, int l, int w, int h, const char* city ,const char* street, int number, int year, int price, const char* author):Exhibit(name,l,w,h,city,street,number)
{
	#ifndef _KP4_
	cout << "Inherited class object constructor called\n";
	#endif
	this->year = year;
	this->price = price;
	this->author = new char[strlen(author)+1];
	strcpy(this->author,author);
}

Artwork::Artwork(const Artwork&a):Exhibit(a)
{
	this->year = a.year;
	this->price = a.price;
	this->author = new char[strlen(a.author)+1];
	strcpy(this->author,a.author);
}

Artwork::~Artwork()
{
	#ifndef _KP4_
	cout << "Inherited class object destructor called\n";
	#endif
	
	delete [] author;
}

void Artwork::linePrint()
{
	printf("\nName: %s\nSize: %dx%dx%d\nYear: %d\nPrice: %d\nAuthor: %s \nAddress: ", this->getName(), this->getLength(), this->getWidth(), this->getHeight(), year, price, author);
	this->getAddress().linePrint();
	cout<<"\n";
}


class IndustrialGoods:public Exhibit
{
	private:
		int category;
		int price;
		char* firm;
	public:
		IndustrialGoods(const char*,int,int,int,const char*,const char*,int, int,int,const char*);
		IndustrialGoods():IndustrialGoods("default name",0,0,0,"Default city","Default street",-1,1,0,"unknown"){};
		IndustrialGoods(const IndustrialGoods&a);
		~IndustrialGoods();
		void linePrint();
		
		int getCategory(){return category;}
		int getPrice(){return price;}
		const char* getFirm(){return firm;}
		
		IndustrialGoods& setCategory(int c){category=c; return *this;}
		IndustrialGoods& setPrice(int p){price=p; return *this;}
		IndustrialGoods& setFirm(char* firm)
			{
				delete [] firm;
				this->firm = new char[strlen(firm)+1];
				strcpy(this->firm,firm);
				return *this;
			}
};

IndustrialGoods::IndustrialGoods(const char*name, int l, int w, int h, const char* city ,const char* street, int number, int category, int price, const char* firm):Exhibit(name,l,w,h,city,street,number)
{
	this->category = category;
	this->price = price;
	this->firm = new char[strlen(firm)+1];
	strcpy(this->firm,firm);
}

IndustrialGoods::IndustrialGoods(const IndustrialGoods&a):Exhibit(a)
{
	this->category = a.category;
	this->price = a.price;
	this->firm = new char[strlen(firm)+1];
	strcpy(this->firm,firm);
}

IndustrialGoods::~IndustrialGoods()
{
	delete [] firm;
}

void IndustrialGoods::linePrint()
{
	printf("\nName: %s\nSize: %dx%dx%d\nCategory: %d\nPrice: %d\nFirm: %s \nAddress: ", this->getName(), this->getLength(), this->getWidth(), this->getHeight(), category, price, firm);
	this->getAddress().linePrint();
}



#ifndef _KP4_
int main()
{
	Artwork a1;
	a1.linePrint();
	
	//IndustrialGoods g1("Engine",20,10,32,"Kharkiv","Industrialna",10,23,2000,"KHTZ corporation");
	//g1.linePrint();
	
	
}
#endif
