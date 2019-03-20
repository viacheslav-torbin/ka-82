#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include<ctype.h>
#include <cstring>
#include <iostream>

using namespace std;

class Date{
	int day;
	int month;
	int year;
	public:
		Date(){
		};
		Date(int , int , int );
		~Date();
		int getDay();
		int getMonth();
		int getYear();
		Date& setDay(int );
		Date& setMonth(int );
		Date& setYear(int );
};

class Address{
	char* city_name;
	char* street_name;
	int building_number;
	int apartment_number;
	public:
		Address(){
		};
		Address(char* , char*, int , int );
		~Address();
		Address(Address& );
		char* getCityName();
		char* getStreetName();
		int getBuildingNumber();
		int getApartmentNumber();
		Address& setCityName(char* );
		Address& setStreetName(char* );
		Address& setBuildingNumber(int );
		Address& setApartmentNumber(int );
		
};

class Delivery{
	Address ShippingAddress;
	Date ShippingDate;
	int shipping_cost;
	public:
		Delivery( Address, Date, int );
		~Delivery();
		int getShippingCost();
		char* getShippingAddressCityName();
		char* getShippingAddressStreetName();
		int getShippingAddressBuildingNumber();
		int getShippingAddressApartmentNumber();
		int getShippingDateDay();
		int getShippingDateMonth();
		int getShippingDateYear();
};

class Letter : public Delivery{
	char* postman_surname;
	public:
		Letter(Address, Date, int, char*);
		~Letter();
		char* getPostmanSurname();
};

class Parcel : public Delivery{
	int weight;
	int length;
	int width;
	int height;
	public:
		Parcel(Address, Date, int, int, int,int, int);
		~Parcel();
		int getParcelWeight();
		int getParcelLength();
		int getParcelWidth();
		int getParcelHeight();
};
int main(){
	int d,m,y,b,a, cost;
	char c[100],s[100];
		printf("\tLETTER\n");
		printf("Shipping Date:\n\t");
		scanf("%d.%d.%d", &d, &m, &y);
		Date Date1= Date(d, m, y);
		printf("Shipping Address:\n");
		printf("\tCity: ");
		fflush(stdin);
		gets(c);
		printf("\tStreet: ");
		fflush(stdin);
		gets(s);
		printf("\tBuilding Number: ");
		cin>>b;
		printf("\tApartment Number: ");
		cin>>a;
		Address Address1(c, s, b, a);
		cout<<"Shipping Cost:\n\t";
		cin>>cost;
		printf("Portman Surname:\n\t");
		char surname[100];
		fflush(stdin);
		gets(surname);
		Letter Letter1(Address1, Date1, cost, surname);
		cout<<"\n";
		printf("\tPARCEL\n");
		printf("Shipping Date:\n\t");
		scanf("%d.%d.%d", &d, &m, &y);
		Date Date2= Date(d, m, y);
		printf("Shipping Address:\n");
		printf("\tCity: ");
		fflush(stdin);
		gets(c);
		printf("\tStreet: ");
		fflush(stdin);
		gets(s);
		printf("\tBuilding Number: ");
		cin>>b;
		printf("\tApartment Number: ");
		cin>>a;
		Address Address2(c, s, b, a);
		cout<<"Shipping Cost:\n\t";
		cin>>cost;
		int wg, l, wd, h;
		printf("Weight:\n\t");
		cin>>wg;
		printf("Dimensions:\n\t");
		scanf("%d*%d*%d",&l, &wd, &h);
		Parcel Parcel1(Address2, Date2, cost, wg, l, wd, h);
		cout<<"\n\tFULL INFO";
			cout<<"\n";
			cout<<"\n\tLETTER\n";
			printf("%d.%d.%d\n", Letter1.getShippingDateDay(), Letter1.getShippingDateMonth(), Letter1.getShippingDateYear());
			printf("%d %s #%d, %s\n",Letter1.getShippingAddressBuildingNumber(), Letter1.getShippingAddressStreetName(), Letter1.getShippingAddressApartmentNumber(),Letter1.getShippingAddressCityName());
			printf("Postman surname: %s\n", Letter1.getPostmanSurname());
			printf("Shipping cost: %d grn\n", Letter1.getShippingCost());
			
			cout<<"\n";
			cout<<"\n\tPARCEL\n";
			printf("%d.%d.%d\n", Parcel1.getShippingDateDay(), Parcel1.getShippingDateMonth(), Parcel1.getShippingDateYear());
			printf("%d %s #%d, %s\n",Parcel1.getShippingAddressBuildingNumber(), Parcel1.getShippingAddressStreetName(), Parcel1.getShippingAddressApartmentNumber(),Parcel1.getShippingAddressCityName());
			printf("Weight: %d\n", Parcel1.getParcelWeight());
			printf("Dimensions: %d*%d*%d\n", Parcel1.getParcelLength(), Parcel1.getParcelWidth(), Parcel1.getParcelHeight());
			printf("Shipping cost: %d grn\n", Parcel1.getShippingCost());
	getch();
	return 0;	
}

Date::Date(int d, int m, int y){
	day=d;
	month=m;
	year=y;
}

Date::~Date(){
	
}

int Date::getDay(){
	return day;
}

int Date::getMonth(){
	return month;
}

int Date::getYear(){
	return year;
}

Date& Date::setDay(int d){
	day=d;
}

Date& Date::setMonth(int m){
	month=m;
}

Date& Date::setYear(int y){
	year=y;
}

Address::Address(char* ct_name, char* st_name, int bld_number, int apr_number){
	city_name=new char[strlen(ct_name)+1];
	strcpy(city_name, ct_name);
	street_name=new char[strlen(st_name)+1];
	strcpy(street_name, st_name);
	building_number=bld_number;
	apartment_number=apr_number;
}

Address::~Address(){
	delete[] street_name;
	delete[] city_name;
	
}

Address::Address(Address& A):building_number(A.building_number),apartment_number(A.apartment_number){
	city_name=new char[strlen(A.city_name)+1];
	strcpy(city_name,A.city_name);
	street_name=new char[strlen(A.street_name)+1];
	strcpy(street_name, A.street_name);
	
}

char* Address::getCityName(){
	return city_name;
}

char* Address::getStreetName(){
	return street_name;
}

int Address::getBuildingNumber(){
	return building_number;
}

int Address::getApartmentNumber(){
	return apartment_number;
}

Address& Address::setCityName(char* ct_name){
	city_name=new char[strlen(ct_name)+1];
	strcpy(city_name, ct_name);
}

Address& Address::setStreetName(char* st_name){
	street_name=new char[strlen(st_name)+1];
	strcpy(street_name, st_name);
}

Address& Address::setBuildingNumber(int bld_number){
	building_number=bld_number;	
}

Address& Address::setApartmentNumber(int apr_number){
	apartment_number=apr_number;	
}

Delivery::Delivery(Address A, Date D, int shp_cost ):ShippingAddress(A){
	ShippingDate=D;
	shipping_cost=shp_cost;	
}


Delivery::~Delivery(){
		
}

int Delivery::getShippingCost(){
	return shipping_cost;
}

char* Delivery::getShippingAddressCityName(){
	return ShippingAddress.getCityName();
}

char* Delivery::getShippingAddressStreetName(){
	return ShippingAddress.getStreetName();
}

int Delivery::getShippingAddressBuildingNumber(){
	return ShippingAddress.getBuildingNumber();
}

int Delivery::getShippingAddressApartmentNumber(){
	return ShippingAddress.getApartmentNumber();
}

int Delivery::getShippingDateDay(){
	return ShippingDate.getDay();
}

int Delivery::getShippingDateMonth(){
	return ShippingDate.getMonth();
}

int Delivery::getShippingDateYear(){
	return ShippingDate.getYear();
}

Letter ::Letter (Address A, Date D, int shp_cost, char* psm_suname):Delivery(A,D,shp_cost){
	postman_surname= new char[strlen(psm_suname)+1];
	strcpy(postman_surname,psm_suname);
}

Letter::~Letter(){
	delete[]postman_surname;
}

char* Letter::getPostmanSurname(){
	return postman_surname;
}

Parcel::Parcel(Address A, Date D, int shp_cost, int wg, int l, int wd, int h):Delivery(A, D, shp_cost), weight(wg), length(l), width(wd), height(h){
}

Parcel::~Parcel(){
	
}

int Parcel::getParcelWeight(){
	return weight;
}

int Parcel::getParcelLength(){
	return length;
}

int Parcel::getParcelWidth(){
	return width;
}

int Parcel::getParcelHeight(){
	return height;
}

