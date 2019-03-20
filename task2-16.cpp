#include <iostream>
#include <string.h>
using namespace std;

class Poem {
private:
  char *title;
  int pages, payment;

public:
  Poem();
  Poem(char *, int, int);
  Poem(const Poem &p) : Poem(p.title, p.pages, p.payment){};
  ~Poem() { delete title; };
  char *getTitle() { return title; };
  int getPages() { return pages; };
  int getPayment() { return payment; };
  void setTitle(char *title_) {
    title = new char[strlen(title_) + 1];
    strcpy(title, title_);
  }
  void setPages(int p) { pages = p; };
  void setPayment(int pay) { payment = pay; };
};

Poem::Poem() {
  title = new char[5];
  strcpy(title, "None");
  pages = -1;
  payment = -1;
}

Poem::Poem(char *title_, int pages_, int payment_) {
  title = new char[strlen(title_) + 1];
  strcpy(title, title_);
  pages = pages_;
  payment = payment_;
}

class Autor {
private:
  char *name, *surname;
  Poem p;

public:
  Autor();
  Autor(char *n, char *s, Poem poem){
    this->name = new char[strlen(n) + 1];
    strcpy(this->name, n);
    this->surname = new char[strlen(n) + 1];
    strcpy(this->surname, s);
    this->p = poem;
    // this->p.setTitle(poem.getTitle());
  }
  void setName(char *n) {
    name = new char[strlen(n)];
    strcpy(name, n);
  };
  void setSurname(char *s) {
    surname = new char[strlen(s)];
    strcpy(surname, s);
  };
  char *getName() { return name; };
  char *getSurname() { return surname; };
  Poem getPoem() { return p; };
  void full_print();
  void short_print();
};

void Autor::full_print() {
  cout << "Name:" << Autor::getName() << "\nSurname:" << Autor::getSurname()
       << "\nTitle:" << Autor::getPoem().getTitle()
       << "\nPages:" << Autor::getPoem().getPages()
       << "\nPrice:" << Autor::getPoem().getPayment() << endl;
};

void Autor::short_print() {
  cout << "Surname:" << Autor::getSurname()
       << "\nTitle:" << Autor::getPoem().getTitle()
       << "\nPages:" << Autor::getPoem().getPages() << endl;
}

Autor::Autor() {
  name = new char[5];
  strcpy(name, "None");
  surname = new char[5];
  strcpy(surname, "None");
  p = Poem();
}

int main() {
  char name[15], surname[15], title[15];
  int pay, pages;
  cout << "Enter title, size and price of poem" << endl;
  cin >> title >> pages >> pay;
  Poem p1(title, pages, pay);
  cout << "Enter name and surname of autor" << endl;
  cin >> name >> surname;
  Autor a1(name, surname, p1);
  Autor a2;
  Autor a3 = a1;
  cout << "Paramatrized class\n" << endl;
  a1.full_print();
  cout << "Default class\n" << endl;
  a2.full_print();
  cout << "Copied class\n";
  a3.full_print();
  cout << "Example ofshorten print" << endl;
  a1.short_print();
  return 0;
}
