// #include <conio.h>
#include <iostream>
#include <string>
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

  void setDay(int d) { day = d; }

  void setMonth(int m) { month = m; }

  void setYear(int y) { year = y; }

  Date &operator++() {
    this->day++;
    return *this;
  }

  Date operator++(int value) {
    Date temp(*this);
    this->day++;
    return temp;
  }
  bool operator==(const Date &d){
    return ((day == d.day) && (month == d.month) && (year == d.year));
  }
  friend ostream &operator<<(ostream &out, Date &outstream);
  friend istream &operator>>(istream &in, Date &instream);
  void printDate();
  void printClass() { cout << "Year : " << year << endl; }
};

class Address {
  string country, street;
  int houseNum, apartmentNum;

public:
  Address();
  Address(string myCountry, string myStreet, int myHouseNum, int myApartmentNum);
  Address(Address &from);

  void setCountry(string myCountry);
  void setStreet(string myStreet);
  void setHouse(int num) { houseNum = num; }
  void setApartment(int num) { apartmentNum = num; }

  int getHouse() { return houseNum; }
  int getApartment() { return apartmentNum; }

  bool operator==(const Address &other) {
    return ((this->houseNum == other.houseNum) &&
            (this->apartmentNum == other.apartmentNum) &&
            (this->country == other.country) &&
            (this->street == other.street));
  }
  friend ostream &operator<<(ostream &out, Address &outstream);
  friend istream &operator>>(istream &in, Address &instream);

  string getCountry() { return country; }
  string getStreet() { return street; }

  void printAddress() {
    cout << "Country: " << country << ", " << street << " st. "
         << "House :" << houseNum << ", apatment # " << apartmentNum << endl;
  }
  void printClass() { cout << " Street: " << street << endl; }

  ~Address();
};

class PostSending {
protected:
  double cost;
  Address to;
  Date receipt;

public:
  PostSending();
  friend ostream &operator<<(ostream &out, PostSending &p) {
    out << "Cost : " << p.cost << endl;
    out << "Adress : " << p.to << endl;
    out << "Date : " << p.receipt << endl;
    return out;
  }
  friend istream &operator>>(istream &in, PostSending &p) {
    cout << "Enter cost" << endl;
    in >> p.cost;
    cout << "Enter Address" << endl;
    in >> p.to;
    cout << "Enter Date" << endl;
    in >> p.receipt;
    return in;
  }
  PostSending(string myCountry, string myStreet, int myHouseNum,
              int myApartmentNum, int d, int m, int y, double c);
  PostSending(PostSending &from);

  void setCost(double c) {
    cost = c;
  }
  void setAddr(Address a) {
    to = Address(a);
  }
  void setDate(Date rec) {
    receipt = Date(rec);
  }

  double getCost() { return cost; }
  bool operator==(const PostSending &other) {
    return ((this->cost == other.cost) && (this->to == other.to) &&
            (this->receipt == other.receipt));
  }

  Address &getAddr() { return to; }

  Date &getDate() { return receipt; }

  void printPostSending();
  virtual void printClass();
  virtual ~PostSending(){};
};

class ParcelPost : public PostSending {
  int weight, width, height, deep;

public:
  ParcelPost();
  ParcelPost(string myCountry, string myStreet, int myHouseNum,
             int myApartmentNum, int d, int m, int y, double c, int myWeight,
             int myWidth, int myHeight, int myDeep);
  ParcelPost(ParcelPost &from);
  ParcelPost &setWeight(int w) {
    weight = w;
    return *this;
  };
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
  virtual void printClass();
};

class RecommendLetter : public PostSending {
public:
  RecommendLetter();
  RecommendLetter(string myCountry, string myStreet, int myHouseNum,
                  int myApartmentNum, int recd, int recm, int recy, double c,
                  int deld, int delm, int dely, string myPostman);
  RecommendLetter(RecommendLetter &from);
  RecommendLetter &setDeliveryDate(Date d) {
    delivery = Date(d);
    return *this;
  }
  void setPostman(string myPostman);

  Date &getDeliveryDate() { return delivery; }

  string getPostman() { return postman; }

  void printRecommendLetter();
  virtual void printClass();
  RecommendLetter(ParcelPost p);
  operator ParcelPost() {
    ParcelPost p;
    p.setWeight(0);
    p.setWidth(0);
    p.setHeight(0);
    p.setDeep(0);
    p.setAddr(this->to);
    p.setDate(this->receipt);
    p.setCost(0.0);
    return p;
  };
  virtual ~RecommendLetter();

private:
  Date delivery;
  string postman;
};

class Post {
private:
  int size;
  static int number;
  PostSending *storage;

public:
  Post();
  Post(int size);
  PostSending &operator[](int count) {
    if (count <= size) {
      return storage[size - 1];
    }
  }
  Post(const Post &p);
  ~Post() { delete[] storage; }
  void print() {
    cout << "Printing the post..." << endl;
    for (int i = 0; i < size; i++) {
      storage[i].printPostSending();
    }
  }
};

int main() {
  int count;
  cout << "Enter size of Post you want to create" << endl;
  cin >> count;
  Post P1(count);
  P1.print();
  cout << endl;
  PostSending a;
  RecommendLetter b;
  ParcelPost c;
  PostSending  * arr[3] = {&a, &b, &c};
  for (int i = 0; i < 3; i++) {
    arr[i]->printClass();
  }
  RecommendLetter r1("Ukraine", "Kreshatic", 1, 2, 3, 4, 5, 6.6, 11, 11, 2011, "NONE");
  ParcelPost p1("USA", "Groove str.", 1, 2, 3, 4, 5, 11.11, 14, 12, 2008, 12);
  cout << endl << "Start of the type conversations " << endl;
  cout << "Conversation of RecommendLetter to ParcelPost: " << endl;
  p1 = r1;
  p1.printClass();
  cout << endl;
  cout << "Conversation of ParcelPost to ReccomendLetter: " << endl;
  r1 = (RecommendLetter)p1;
  r1.printClass();
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
  out << "House number : " << outstream.houseNum << endl;
  return out;
}

istream &operator>>(istream &in, Address &instream) {
  cout << "Country : " << endl;
  in >> instream.country;
  cout << "Street : " << endl;
  in >> instream.street;
  cout << "Apartment number : " << endl;
  in >> instream.apartmentNum;
  cout << "House number: " << endl;
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
  country = "NoCountry";
  street = "NoStreet";
  houseNum = -1;
  apartmentNum = -1;
}

Address::Address(string myCountry, string myStreet, int myHouseNum,
                 int myApartmentNum) {
  country = myCountry;
  street = myStreet;
  houseNum = myHouseNum;
  apartmentNum = myApartmentNum;
}

Address::Address(Address &from) {
  country = from.country;
  street = from.street;
  houseNum = from.houseNum;
  apartmentNum = from.apartmentNum;
}

void Address::setCountry(string myCountry) {
  country = myCountry;
}

void Address::setStreet(string myStreet) {
  street =  myStreet;
}

Address::~Address() {}

PostSending::PostSending() {
  cost = 0.0;
  to = Address();
  receipt = Date(1, 1, 1970);
}

PostSending::PostSending(string myCountry, string myStreet, int myHouseNum,
                         int myApartmentNum, int d, int m, int y, double c)
    : to(myCountry, myStreet, myHouseNum, myApartmentNum), receipt(d, m, y),
      cost(c) {
  cost = c;
}

PostSending::PostSending(PostSending &from) {
  to = from.to;
  receipt = from.receipt;
  cost = from.cost;
}

void PostSending::printPostSending() {
  cout << endl << "Post sending: " << endl;
  this->to.printAddress();
  this->receipt.printDate();
  cout << "Delivery price: " << cost << endl;
}

void PostSending::printClass() {
  cout << "It's me, PostSending" << endl;
  this->to.printAddress();
}

RecommendLetter::RecommendLetter() {
  delivery = Date();
  postman = "NoPostman";
}

RecommendLetter::RecommendLetter(string myCountry, string myStreet,
                                 int myHouseNum, int myApartmentNum, int recd,
                                 int recm, int recy, double c, int deld,
                                 int delm, int dely, string myPostman)
    : PostSending(myCountry, myStreet, myHouseNum, myApartmentNum, recd, recm,
                  recy, c),
      delivery(deld, delm, dely) {
  postman = myPostman;
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
  postman = from.postman;
}

void RecommendLetter::setPostman(string myPostman) {
  postman = myPostman;
}

void RecommendLetter::printRecommendLetter() {
  cout << "Recommend letter:" << endl;
  printPostSending();
  cout << "Postman " << postman << "\nSecond ";
  delivery.printDate();
  cout << endl;
}

void RecommendLetter::printClass() {
  cout << "It's me, RecommendLetter" << endl;
  this->getAddr().printAddress();
  cout << "Postman: " << postman << endl;
}

RecommendLetter::~RecommendLetter() {}

ParcelPost::ParcelPost() {
  PostSending();
  weight = width = height = deep = 0;
}

ParcelPost::ParcelPost(string myCountry, string myStreet, int myHouseNum,
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

void ParcelPost::printClass() {
  cout << "It's me, ParcelPost" << endl;
  this->getAddr().printAddress();
  cout << "Weight:" << weight<< endl;
  cout << "Width:" << width << endl;
  cout << "Height:" << height << endl;
  cout << "Deep:" << deep << endl;
}

Post::Post() {
  size = 1;
  storage = new PostSending[size];
  PostSending storage[0];
};

int Post::number = 0;

Post::Post(int s) {
  this->size = s;
  char bttn;
  storage = new PostSending[size];
  for (int i = 0; i < this->size; i++) {
    cout << "Do you want to create default post sending (Y/N)" << endl;
    cin >> bttn;
    if (tolower(bttn) == tolower('N')) {
      cin >> storage[i];
    }
    number++;
  }
}

RecommendLetter::RecommendLetter(ParcelPost p) {
  this->cost = p.getCost();
  this->to = p.getAddr();
  this->receipt = p.getDate();
  this->delivery = Date();
  this->postman =  "None";
};

Post::Post(const Post &p) {
  this->size = p.size;
  this->storage = new PostSending[this->size];
  for (int i = 0; i < size; i++) {
    this->storage[i] = p.storage[i];
  };
};
