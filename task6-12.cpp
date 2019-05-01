#include <iostream>
#include <string.h>
#include <time.h>

using  namespace std;

class Address {
  char *country, *street;
  int houseNum, apartmentNum;

public:
  Address();
  Address(char *myCountry, char *myStreet, int myHouseNum, int myApartmentNum);
  Address(Address &from);

  Address &setCountry(char *myCountry);
  Address &setStreet(char *myStreet);
  Address &setHouse(int num) {
    houseNum = num;
    return *this;
  }
  Address &setApartment(int num) {
    apartmentNum = num;
    return *this;
  }

  int getHouse() { return houseNum; }
  int getApartment() { return apartmentNum; }

  bool operator==(const Address &other) {
    return ((this->houseNum == other.houseNum) &&
            (this->apartmentNum == other.apartmentNum) &&
            !(strcmp(this->country, other.country)) &&
            !(strcmp(this->street, other.street)));
  }
  friend ostream &operator<<(ostream &out, Address &outstream);
  friend istream &operator>>(istream &in, Address &instream);

  char *getCountry() { return country; }
  char *getStreet() { return street; }

  void printAddress();
  void printClass() { cout << " Street: " << street << endl; }

  ~Address();
};

template <typename T>

bool are_equal(T a[], T b[], int size){
  for (int i = 0; i < size; i++) {
    if (!(a[i] == b[i])){
      return 0;
    }
  }
  return 1;
}


int main() {
  Address a1[6], a2[6];
  cout << are_equal(a1, a2, 6) << endl;
  return 0;
}

void Address::printAddress() {
  cout << "Country: " << country << ", " << houseNum << "  " << street
       << " st. "
       << ", apatment # " << apartmentNum << endl;
}


istream &operator>>(istream &in, Address &instream) {
  cout << "Country : " << endl;
	in >> instream.country;
  cout << "Street : " << endl;
	in >> instream.street;
  fflush(stdin);
  cout << "Apartment number : " << endl;
	in >> instream.apartmentNum;
  cout << "House number: " << endl;
  in >> instream.houseNum;
  return in;
}

ostream &operator<<(ostream &out, Address &outstream) {
  out << "Country : " << outstream.country << endl;
  out << "Street : " << outstream.street << endl;
  out << "Appartment number : " << outstream.apartmentNum << endl;
  out << "House number : "<< outstream.houseNum << endl;
  return out;
}

Address::~Address() {
  delete[] country;
  delete[] street;
}

Address::Address() {
  country = new char[10];
  strcpy(country, "NoCountry");
  street = new char[9];
  strcpy(street, "NoStreet");
  houseNum = -1;
	apartmentNum = -1;
}

Address::Address(char *myCountry, char *myStreet, int myHouseNum,
                 int myApartmentNum) {
  country = new char[strlen(myCountry) + 1];
  strcpy(country, myCountry);
  street = new char[strlen(myStreet) + 1];
  strcpy(street, myStreet);
  houseNum = myHouseNum;
  apartmentNum = myApartmentNum;
}

Address::Address(Address &from) {
  country = new char[strlen(from.country) + 1];
  strcpy(country, from.country);

  street = new char[strlen(from.street) + 1];
  strcpy(street, from.street);

  houseNum = from.houseNum;
  apartmentNum = from.apartmentNum;
}

Address &Address::setCountry(char *myCountry) {
  delete[] country;
  country = new char[strlen(myCountry) + 1];
  strcpy(country, myCountry);
  return *this;
}

Address &Address::setStreet(char *myStreet) {
  delete[] street;
  street = new char[strlen(myStreet) + 1];
  strcpy(street, myStreet);
  return *this;
}
