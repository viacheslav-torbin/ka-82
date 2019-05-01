// #include <conio.h>
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

class Date {
  int day, month, year;

public:
  int getDay() { return day; }
  int getMonth() { return month; }
  int getYear() { return year; }

  Date();
  Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
  }
  Date(Date &from) {
    day = from.getDay();
    month = from.getMonth();
    year = from.getYear();
  }
  int maxdays() {
    int max[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return max[month - 1];
  }

  Date &setDay(int d) {
    day = d;
    return *this;
  }
  Date &setMonth(int m) {
    month = m;
    return *this;
  }
  Date &setYear(int y) {
    year = y;
    return *this;
  }

  Date &operator++() {
    this->day++;
    return *this;
  }
  Date operator++(int value) {
    Date temp(*this);
    this->day++;
    return temp;
  }
  friend Date operator+(const Date &d1, const Date &d2) {
    Date d3;
    d3.year = d1.year + d2.year;
    if (d1.month + d2.month > 12) {
      d3.month = d1.month + d2.month - 12;
      d3.year++;
    } else {
      d3.month = d1.month + d2.month;
    }
    if (d1.day + d2.day > d3.maxdays()) {
      d3.day = d1.day + d2.day - d3.maxdays();
      d3.month++;
    } else {
      d3.day = d1.day + d2.day;
    }
    if (d3.month > 12) {
      d3.month - 12;
      d3.year++;
    };
		return d3;
  }
  bool operator==(const Date &other) {
    return ((this->day == other.day) && (this->month == other.month) &&
            (this->year == other.year));
  }
  friend ostream &operator<<(ostream &out, Date &outstream);
  friend istream &operator>>(istream &in, Date &instream);
  void printDate();
  void printClass() { cout << "Year : " << year << endl; }

};

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

  void printAddress() {
    cout << "Country: " << country << ", " << houseNum << "  " << street
         << " st. "
         << ", apatment # " << apartmentNum << endl;
  }
  void printClass() { cout << " Street: " << street << endl; }

  ~Address();
};

class PostSending {
  double cost;
  Address to;
  Date receipt;

public:
  PostSending();
  PostSending(char *myCountry, char *myStreet, int myHouseNum,
              int myApartmentNum, int d, int m, int y, double c);
  PostSending(PostSending &from);

  PostSending &setCost(double c) {
    cost = c;
    return *this;
  }
  PostSending &setAddr(Address a) {
    to = Address(a);
    return *this;
  }
  PostSending &setDate(Date rec) {
    receipt = Date(rec);
    return *this;
  }

  double getCost() { return cost; }
  bool operator==(const PostSending &other) {
    return ((this->cost == other.cost) && (this->to == other.to) &&
            (this->receipt == other.receipt));
  }

  Address &getAddr() { return to; }

  Date &getDate() { return receipt; }

  void printPostSending();
  void printClass();

};

class RecommendLetter : public PostSending {
  Date delivery;
  char *postman;

public:
  RecommendLetter();
  RecommendLetter(char *myCountry, char *myStreet, int myHouseNum,
                  int myApartmentNum, int recd, int recm, int recy, double c,
                  int deld, int delm, int dely, char *myPostman);
  RecommendLetter(RecommendLetter &from);

  RecommendLetter &setDeliveryDate(Date d) {
    delivery = Date(d);
    return *this;
  }
  RecommendLetter &setPostman(char *myPostman);

  Date &getDeliveryDate() { return delivery; }

  char *getPostman() { return postman; }

  void printRecommendLetter();
  void printClass();

  ~RecommendLetter();
};

class ParcelPost : public PostSending {
  int weight, width, height, deep;

public:
  ParcelPost();
  ParcelPost(char *myCountry, char *myStreet, int myHouseNum,
             int myApartmentNum, int d, int m, int y, double c, int myWeight,
             int myWidth, int myHeight, int myDeep);
  ParcelPost(ParcelPost &from);

  ParcelPost &setWeight(int w) {
    weight = w;
    return *this;
  }
  ParcelPost &setWidth(int w) {
    width = w;
    return *this;
  }
  ParcelPost &setHeight(int h) {
    height = h;
    return *this;
  }
  ParcelPost &setDeep(int d) {
    deep = d;
    return *this;
  }

  bool operator<(const ParcelPost &other) {
    return (this->weight < other.weight);
  }

  int getWeight() { return weight; }
  int getWidth() { return width; }
  int getHeight() { return height; }
  int getDeep() { return deep; }

  void printParcelPost();
  void printClass();
};

int main() {
	int dd, mm, yy;
	cout << "Usage of + and ++ on Data:" << endl;
  Date d1(5, 4, 2009);
  Date d2(6, 10, 2013);
  Date d3;
  cout << "D1 is :" << endl;
  d1.printDate();
  cout << "D2 is:" << endl;
  d2.printDate();
  cout << "D3 that is D1 + D2:" << endl;
  d3 = d1 + d2;
  d3.printDate();
  cout << "D1 ++" << endl;
  d1++;
  d1.printDate();
  cout << "++D2" << endl;
  ++d2;
  d2.printDate();
  ParcelPost p1("Ukraine", "Khersahik", 1, 100, 1, 5, 2010, 20.10, 50, 60, 70, 80);
	ParcelPost p2("Russia", "Khersahik", 5, 10, 13, 8, 2000, 2.137, 5, 6, 7, 8);
  cout << "Post p1" << endl;
	p1.printParcelPost();
	cout << "Post p2" << endl;
	p2.printParcelPost();
  cout << "p1 < p2 ? : " << (p1 < p2) << endl;
	PostSending s1, s2;
  cout << "s1 == s2 ? : " << (s1 == s2) << endl;
	cout << "Input of Date osing overloaded >>" << endl;
	cin >> d1;
  cout << "Output of Date using overloaded <<" << endl;
  cout << d1 << endl;
	Address a1;
	cout << "Input of Address using overloaded >>" << endl;
	cin >> a1;
	cout << "Output of Address using overloaded << " << endl;
	cout << a1;
  // getch();
  return 0;
}
ostream &operator<<(ostream &out, Date &outstream) {
  out << "day: " << outstream.day << endl;
  out << "month: " << outstream.month << endl;
  out << "year" << outstream.year << endl;
  return out;
}

istream &operator>>(istream &in, Date &instream) {
  cout << "day : ";
	in >> instream.day;
  cout << "month : ";
	in >> instream.month;
  cout << "year : ";
  in >> instream.year;
  return in;
}

ostream &operator<<(ostream &out, Address &outstream) {
  out << "Country : " << outstream.country << endl;
  out << "Street : " << outstream.street << endl;
  out << "Appartment number : " << outstream.apartmentNum << endl;
  out << "House number : "<< outstream.houseNum << endl;
  return out;
}

istream &operator>>(istream &in, Address &instream) {
  cout << "Country : ";
	in >> instream.country;
  cout << "Street : ";
	in >> instream.street;
  cout << "Apartment number : ";
	in >> instream.apartmentNum;
  cout << "House number: ";
  in >> instream.houseNum;
  return in;
}

Date::Date() {
  struct tm *ptr;
  time_t current;
  time(&current);
  ptr = localtime(&current);
  day = ptr->tm_mday;
  month = ptr->tm_mon + 1;
  year = ptr->tm_year;
}

void Date::printDate() {
  cout << "Delivery date: ";
  cout << day << "." << month << "." << year << endl;
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

Address::~Address() {
  if (country)
    delete[] country;
  if (street)
    delete[] street;
}

PostSending::PostSending() {
  cost = 0.0;
  to = Address();
  receipt = Date(1, 1, 1970);
}

PostSending::PostSending(char *myCountry, char *myStreet, int myHouseNum,
                         int myApartmentNum, int d, int m, int y, double c)
    : to(myCountry, myStreet, myHouseNum, myApartmentNum), receipt(d, m, y),
      cost(c) {
  cost = c;
}

PostSending::PostSending(PostSending &from) {
  to = Address(from.to);
  receipt = Date(from.receipt);
  cost = from.cost;
}

void PostSending::printPostSending() {
  cout << endl << "Post sending: " << endl;
  this->to.printAddress();
  this->receipt.printDate();
  cout << "Delivery price: " << cost << endl;
}

void PostSending::printClass() { this->to.printAddress(); }

RecommendLetter::RecommendLetter() {
  delivery = Date();

  postman = new char[10];
  strcpy(postman, "NoPostman");
}

RecommendLetter::RecommendLetter(char *myCountry, char *myStreet,
                                 int myHouseNum, int myApartmentNum, int recd,
                                 int recm, int recy, double c, int deld,
                                 int delm, int dely, char *myPostman)
    : PostSending(myCountry, myStreet, myHouseNum, myApartmentNum, recd, recm,
                  recy, c),
      delivery(deld, delm, dely) {
  postman = new char[strlen(myPostman) + 1];
  strcpy(postman, myPostman);
}

RecommendLetter::RecommendLetter(RecommendLetter &from)
    : PostSending(from.getAddr().getCountry(), from.getAddr().getStreet(),
                  from.getAddr().getHouse(), from.getAddr().getApartment(),
                  from.getDate().getDay(), from.getDate().getMonth(),
                  from.getDate().getYear(), from.getCost()) {
  this->setAddr(from.getAddr());
  this->setDate(from.getDate());
  this->setCost(from.getCost());
  delivery = Date(from.delivery);
  postman = new char[strlen(from.postman) + 1];
  strcpy(postman, from.postman);
}

RecommendLetter &RecommendLetter::setPostman(char *myPostman) {
  postman = new char[strlen(myPostman) + 1];
  strcpy(postman, myPostman);
}

void RecommendLetter::printRecommendLetter() {
  cout << "Recommend letter:" << endl;
  printPostSending();
  cout << "Postman " << postman << "\nSecond ";
  delivery.printDate();
  cout << endl;
}

void RecommendLetter::printClass() { this->getAddr().printAddress(); }

RecommendLetter::~RecommendLetter() {
  delete[] postman;
}

ParcelPost::ParcelPost() {
  PostSending();
  weight = width = height = deep = 0;
}

ParcelPost::ParcelPost(char *myCountry, char *myStreet, int myHouseNum,
                       int myApartmentNum, int d, int m, int y, double c,
                       int myWeight, int myWidth, int myHeight, int myDeep)
    : PostSending(myCountry, myStreet, myHouseNum, myApartmentNum, d, m, y, c) {
  width = myWidth;
  weight = myWeight;
  height = myHeight;
  deep = myDeep;
}

ParcelPost::ParcelPost(ParcelPost &from)
    : PostSending(from.getAddr().getCountry(), from.getAddr().getStreet(),
                  from.getAddr().getHouse(), from.getAddr().getApartment(),
                  from.getDate().getDay(), from.getDate().getMonth(),
                  from.getDate().getYear(), from.getCost()) {
  width = from.width;
  weight = from.weight;
  height = from.height;
  deep = from.deep;
}

void ParcelPost::printParcelPost() {
  cout << "Parcel post:" << endl;
  printPostSending();
  cout << "Weight: " << weight << ", " << width << " X " << height << " X "
       << deep << endl;
}

void ParcelPost::printClass() { this->getAddr().printAddress(); }
