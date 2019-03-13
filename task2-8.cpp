#include <iostream>
#include <string.h>
using namespace std;

class Postachalnyk {
public:
  char *firmname;
  char *country;
  char *phonenumber;
  Postachalnyk();
  Postachalnyk(char *, char *, char *);
  Postachalnyk(const Postachalnyk &post)
      : Postachalnyk(post.firmname, post.country, post.phonenumber){};
  ~Postachalnyk();
  Postachalnyk &setname(char *);
  Postachalnyk &setcountry(char *);
  Postachalnyk &setphnumber(char *);
  char getname();
  char getcountry();
  char getphnumber();
  void print();
};

Postachalnyk::Postachalnyk() {
  firmname = new char[10];
  strcpy(firmname, "noname");
  country = new char[15];
  strcpy(country, "noname");
  phonenumber = new char[15];
  strcpy(phonenumber, "noname");
}

Postachalnyk::Postachalnyk(char *name, char *cOuntry, char *number) {
  firmname = new char[strlen(name) + 1];
  strcpy(firmname, name);
  country = new char[strlen(cOuntry) + 1];
  strcpy(country, cOuntry);
  phonenumber = new char[strlen(number) + 1];
  strcpy(phonenumber, number);
}

Postachalnyk::~Postachalnyk() {
  delete[] firmname;
  delete[] country;
  delete[] phonenumber;
}

Postachalnyk &Postachalnyk::setname(char *name) {
  delete[] firmname;
  firmname = new char[strlen(name) + 1];
  strcpy(firmname, name);
};

Postachalnyk &Postachalnyk::setcountry(char *cOuntry) {
  delete[] country;
  country = new char[strlen(cOuntry) + 1];
  strcpy(country, cOuntry);
};

Postachalnyk &Postachalnyk::setphnumber(char *number) {
  delete[] phonenumber;
  phonenumber = new char[strlen(number) + 1];
  strcpy(phonenumber, number);
};

char Postachalnyk::getname() { return *firmname; };

char Postachalnyk::getcountry() { return *country; };

char Postachalnyk::getphnumber() { return *phonenumber; };

void Postachalnyk::print() {
  cout << "Firm name " << firmname << "\nCountry " << country
       << "\nPhone number " << phonenumber << endl;
}

class Tovar {
  char *name;
  int price;
  int amount;

public:
  Tovar();
  Tovar(char *, int, int);
  Tovar(Tovar &);
  ~Tovar();
  Tovar &setname(char *);
  Tovar &setprice(int);
  Tovar &setamount(int);
  char *getname();
  int getprice();
  int getamount();
  void printf();
};

Tovar::Tovar() {
  name = new char[15];
  strcpy(name, "noname");
  price = 0;
  amount = 0;
}

Tovar::Tovar(char *title, int pRice, int aMount) {
  name = new char[strlen(title) + 1];
  strcpy(name, title);
  price = pRice;
  amount = aMount;
}

Tovar::Tovar(Tovar &a) {
  price = a.price;
  amount = a.amount;
  name = new char[strlen(a.name) + 1];
  strcpy(name, a.name);
}

Tovar::~Tovar() { delete[] name; };

Tovar &Tovar::setname(char *title) {
  delete[] name;
  name = new char[strlen(title) + 1];
  strcpy(name, title);
};

Tovar &Tovar::setprice(int pRice) { price = pRice; };

Tovar &Tovar::setamount(int aMount) { amount = aMount; };

char *Tovar::getname() { return name; };

int Tovar::getprice() { return price; };

int Tovar::getamount() { return amount; };

void Tovar::printf() {
  cout << "Name " << name << "\nPrice " << price << "\nAmount " << amount
       << endl;
};

int main() {
  int k;
  cout << "What class do you want to check?" << endl;
  cout << "1-Postachalnyk" << endl;
  cout << "2-Tovar" << endl;
  cin >> k;
  switch (k) {
  case 1: {
    char firmname[10];
    char country[15];
    char phonenumber[15];
    cout << "Enter company name, country, phone number: " << endl;
    cin >> firmname >> country >> phonenumber;
    Postachalnyk firm1(firmname, country, phonenumber);
    cout << "Constructed by constructor with params firm1:" << endl;
    firm1.print();
    Postachalnyk firm2;
    cout << "Default constructor firm2:" << endl;
    firm2.print();
    Postachalnyk firm3 = firm1;
    cout << "Copying constructor firm3:" << endl;
    firm3.print();
    break;
  }
  case 2: {
    char name[15];
    int p;
    int a;
    cout << "Enter tovar's name, price and amount" << endl;
    cin >> name >> p >> a;
    Tovar tovar1(name, p, a);
    cout << "Constructed by constructor with params tovar1:" << endl;
    tovar1.printf();
    Tovar tovar2;
    cout << "Default constructor firm2:" << endl;
    tovar2.printf();
    Tovar tovar3 = tovar1;
    cout << "Copying constructor firm3:" << endl;
    tovar3.printf();
    break;
  }
  }
  return 0;
}
