#include <iostream>
#include <stdio.h>
#include <string.h>
// #include <conio.h>
#include <cstring>
#include <ctype.h>
#include <iostream>
//#include "Address.h"
//#include "Date.h"
//#include "PostOffice.h"

using namespace std;

class Date {
  int day;
  int month;
  int year;

public:
  Date(){};
  Date(int, int, int);
  ~Date();
  int getDay();
  int getMonth();
  int getYear();
  Date &setDay(int);
  Date &setMonth(int);
  Date &setYear(int);
};

class Address {
  char *city_name;
  char *street_name;
  int building_number;
  int apartment_number;

public:
  Address(){};
  Address(char *, char *, int, int);
  ~Address();
  Address(Address &);
  char *getCityName();
  char *getStreetName();
  int getBuildingNumber();
  int getApartmentNumber();
  Address &setCityName(char *);
  Address &setStreetName(char *);
  Address &setBuildingNumber(int);
  Address &setApartmentNumber(int);
};

class Delivery {
  Address ShippingAddress;
  Date ShippingDate;
  int shipping_cost;

public:
  Delivery(Address, Date, int);
  ~Delivery();
  int getShippingCost();
  char *getShippingAddressCityName();
  char *getShippingAddressStreetName();
  int getShippingAddressBuildingNumber();
  int getShippingAddressApartmentNumber();
  int getShippingDateDay();
  int getShippingDateMonth();
  int getShippingDateYear();
};

class Letter : public Delivery {
  char *postman_surname;

public:
  Letter(Address, Date, int, char *);
  ~Letter();
  char *getPostmanSurname();
};

class Parcel : public Delivery {
  int weight;
  int length;
  int width;
  int height;

public:
  Parcel(Address, Date, int, int, int, int, int);
  ~Parcel();
  int getParcelWeight();
  int getParcelLength();
  int getParcelWidth();
  int getParcelHeight();
};
int main() {
  int d, m, y, b, a, cost;
  char c[100], s[100];
  //	char answer = 'n';
  //	do{
  printf("\tDELIVERY\n");
  printf("Shipping Date:\n\t");
  scanf("%d.%d.%d", &d, &m, &y);
  Date Date1 = Date(d, m, y);
  printf("Shipping Address:\n");
  printf("\tCity: ");
  fflush(stdin);
  cin >> c;
  printf("\tStreet: ");
  fflush(stdin);
  cin >> s;
  printf("\tBuilding Number: ");
  cin >> b;
  printf("\tApartment Number: ");
  cin >> a;
  Address Address1(c, s, b, a);
  cout << "Shipping Cost:\n\t";
  cin >> cost;
  Delivery Delivery1(Address1, Date1, cost);
  //		cout<<"Is it letter or parcel (l or p)?   ";
  //		char ans;
  //		cin>>ans;
  //		if (ans=='l'){
  //			printf("\tLETTER\n");
  //			printf("Portman Surname:\n\t");
  //			char surname[100];
  //			fflush(stdin);
  //			gets(surname);
  //			Letter Letter1(Address1, Date1, cost, surname);
  //		}

  //		if (ans=='p'){
  printf("\tPARCEL\n");
  int wg, l, wd, h;
  printf("Weight:\n\t");
  cin >> wg;
  printf("Dimensions:\n\t");
  scanf("%d.%d.%d", &l, &wd, &h);
  Parcel Parcel1(Address1, Date1, cost, wg, l, wd, h);
  //		}
  //		printf("Do you want to enter one more delivery (y or n)?:  ");
  //		fflush(stdin);
  //		scanf("%c", &answer);
  //    	printf("\n");
  //	}while(tolower(answer) == 'y');
  //	int n=PostOffice.getCount();
  cout << "\n\tFULL INFO\n";
  //	for (int i=0; i<n; i++){
  printf("%d.%d.%d\n", Delivery1.getShippingDateDay(),
         Delivery1.getShippingDateMonth(), Delivery1.getShippingDateYear());
  printf("%d %s #%d, %s\n", Delivery1.getShippingAddressBuildingNumber(),
         Delivery1.getShippingAddressStreetName(),
         Delivery1.getShippingAddressApartmentNumber(),
         Delivery1.getShippingAddressCityName());
  //		if (ans=='l'){
  //			printf("Postman surname: %s\n",
  // Letter1.getPostmanSurname()); 			printf("Shipping cost: %d
  // grn\n", Letter1.getShippingCost());
  //		}
  //		if (ans=='p'){
  printf("Weight: %d", Parcel1.getParcelWeight());
  printf("Dimensions: %d\times%d\times%d\n", Parcel1.getParcelLength(),
         Parcel1.getParcelWidth(), Parcel1.getParcelHeight());
  printf("Shipping cost: %d grn\n", Parcel1.getShippingCost());
  //		}
  //	}
  //	printf("\n\n\tSUMMARY\n");
  //	printf("%d.%d.%d - %s - %d grn\n", Delivery1.getShippingDateDay(),
  // Delivery1.getShippingDateMonth(),  Delivery1.getShippingDateYear(),
  // Delivery1.getShippingAddressCityName(), Delivery1.getShippingCost());
  return 0;
}

Date::Date(int d, int m, int y) {
  day = d;
  month = m;
  year = y;
}

Date::~Date() {}

int Date::getDay() { return day; }

int Date::getMonth() { return month; }

int Date::getYear() { return year; }

Date &Date::setDay(int d) { day = d; }

Date &Date::setMonth(int m) { month = m; }

Date &Date::setYear(int y) { year = y; }

Address::Address(char *ct_name, char *st_name, int bld_number, int apr_number) {
  city_name = new char[strlen(ct_name) + 1];
  strcpy(city_name, ct_name);
  street_name = new char[strlen(st_name) + 1];
  strcpy(street_name, st_name);
  building_number = bld_number;
  apartment_number = apr_number;
}

Address::~Address() {
  delete[] street_name;
  delete[] city_name;
}

Address::Address(Address &A)
    : building_number(A.building_number), apartment_number(A.apartment_number) {
  city_name = new char[strlen(A.city_name) + 1];
  strcpy(city_name, A.city_name);
  street_name = new char[strlen(A.street_name) + 1];
  strcpy(street_name, A.street_name);
}

char *Address::getCityName() { return city_name; }

char *Address::getStreetName() { return street_name; }

int Address::getBuildingNumber() { return building_number; }

int Address::getApartmentNumber() { return apartment_number; }

Address &Address::setCityName(char *ct_name) {
  city_name = new char[strlen(ct_name) + 1];
  strcpy(city_name, ct_name);
}

Address &Address::setStreetName(char *st_name) {
  street_name = new char[strlen(st_name) + 1];
  strcpy(street_name, st_name);
}

Address &Address::setBuildingNumber(int bld_number) {
  building_number = bld_number;
}

Address &Address::setApartmentNumber(int apr_number) {
  apartment_number = apr_number;
}

Delivery::Delivery(Address A, Date D, int shp_cost) : ShippingAddress(A) {
  ShippingDate = D;
  shipping_cost = shp_cost;
}

Delivery::~Delivery() {}

int Delivery::getShippingCost() { return shipping_cost; }

char *Delivery::getShippingAddressCityName() {
  return ShippingAddress.getCityName();
}

char *Delivery::getShippingAddressStreetName() {
  return ShippingAddress.getStreetName();
}

int Delivery::getShippingAddressBuildingNumber() {
  return ShippingAddress.getBuildingNumber();
}

int Delivery::getShippingAddressApartmentNumber() {
  return ShippingAddress.getApartmentNumber();
}

int Delivery::getShippingDateDay() { return ShippingDate.getDay(); }

int Delivery::getShippingDateMonth() { return ShippingDate.getMonth(); }

int Delivery::getShippingDateYear() { return ShippingDate.getYear(); }

Letter ::Letter(Address A, Date D, int shp_cost, char *psm_suname)
    : Delivery(A, D, shp_cost) {
  postman_surname = new char[strlen(psm_suname) + 1];
  strcpy(postman_surname, psm_suname);
}

Letter::~Letter() { delete[] postman_surname; }

char *Letter::getPostmanSurname() { return postman_surname; }

Parcel::Parcel(Address A, Date D, int shp_cost, int wg, int l, int wd, int h)
    : Delivery(A, D, shp_cost), weight(wg), length(l), width(wd), height(h) {
  cout << "hy";
}

Parcel::~Parcel() {}

int Parcel::getParcelWeight() { return weight; }

int Parcel::getParcelLength() { return length; }

int Parcel::getParcelWidth() { return width; }

int Parcel::getParcelHeight() { return height; }
