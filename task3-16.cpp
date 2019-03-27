#include <iostream>
#include <string.h>
using namespace std;

class Poem {
private:
  char *title;
  int size, payment;

public:
  Poem();
  // Poem(char *, int, int);
  Poem(const Poem &p) : Poem(p.title, p.size, p.payment){};
  char *getTitle() { return title; };
  int getSize() { return size; };
  int getPayment() { return payment; };
  void setTitle(char *);
  void setSize(int s) { size = s; };
  void setPayment(int pay) { payment = pay; };
  void print();
  ~Poem();
};

class Autor {
private:
  char *name, *surname;

public:
  Autor();
  Autor(char *, char *);
  Autor(const Autor &a) : Autor(a.name, a.surname){};
  void setName(char *);
  void setSurname(char *s);
  char *getName() { return name; };
  char *getSurname() { return surname; };
  void print();
  ~Autor();
};

class Music : public Poem {
private:
  float duration;
  Autor autor;

public:
  Music():Poem(), duration(-1.0), autor(){
    cout << "Music default constr." << endl;
  };
  Music(char *t, int s, int p, float d, Autor a)
      : Poem(t, s, p), duration(d), autor(a){
        cout << "Music param. contsr" << endl;
      };
  void setDuration(float d) { duration = d; };
  float getDuration() { return duration; };
  void print(){
    Poem::print();
    cout << "Duration:" << duration << endl;
    autor.print();
  };
};

class Book : public Poem {
private:
  int pages;
  Autor autor;

public:
  Book():Poem(), pages(-1), autor(){
    cout << "Book default constr." << endl;;
  };
  Book(char *t, int s, int pay, int pages, Autor a)
      : Poem(t, s, pay), pages(pages), autor(a){
        cout << "Book param constr." << endl;
    };
  ~Book(){cout << "Book destr." << endl;};
  void setPages(int p){pages = p;};
  int getPages(){return pages;};
  void print(){
    Poem::print();
    cout << "Pages:" << pages << endl;
    autor.print();
  };
};

int main() {
  char name[100], surname[100], title[100];
  int size, pages, payment;
  float duration;
  cout << "Default Music and Book" << endl;
  Music m1;
  m1.print();
  cout << endl;
  Book b1;
  b1.print();
  cout << endl;
  cout << "Parametrized Book and Music" << endl;
  cout << "Enter name and surname of autor" << endl;
  cin >> name >> surname;
  cout << "Enter title , size and payment" << endl;
  cin >> title >> size >> payment;
  cout << "Enter amount of pages and duration" << endl;
  cin >> pages >> duration;
  Autor a2(name, surname);
  Book b2(title, size, payment, pages, a2);
  b2.print();
  cout << endl;
  Music m2(title, size, payment, duration, a2);
  cout << endl;
  cout << "Copied Book and Music" << endl;
  Music m3 = m2;
  Book b3 = b2;
  m3.print();
  cout << endl;
  b3.print();
  cout << endl;
  return 0;
}

Poem::Poem() {
  cout << "Poem default constr." << endl;
  title = new char[5];
  strcpy(title, "None");
  size = -1;
  payment = -1;
}

Poem::Poem(char *title_, int size_, int payment_) {
  cout << "Poem param constr." << endl;
  title = new char[strlen(title_) + 1];
  strcpy(title, title_);
  size = size_;
  payment = payment_;
}

void Poem::setTitle(char *title_) {
  title = new char[strlen(title_) + 1];
  strcpy(title, title_);
};

Poem::~Poem() {
  cout << "Poem destr." << endl;
  delete[] title;
}

void Autor::setName(char *n) {
  name = new char[strlen(n)];
  strcpy(name, n);
};

void Autor::setSurname(char *s) {
  surname = new char[strlen(s)];
  strcpy(surname, s);
}

Autor::Autor(char *n, char *s) {
  cout << "Autor param constr." << endl;
  name = new char[strlen(n) + 1];
  strcpy(name, n);
  surname = new char[strlen(n) + 1];
  strcpy(surname, s);
};

void Autor::print(){
  cout << "Name:" << name << endl;
  cout << "Surname:" << surname << endl;
}

void Poem::print(){
  cout << "Title:" << title << endl;
  cout << "Size:" << size << endl;
  cout << "Payment:" << payment << endl;
}

Autor::Autor() {
  cout << "Autor defaulf constr." << endl;
  name = new char[5];
  strcpy(name, "None");
  surname = new char[5];
  strcpy(surname, "None");
}

Autor::~Autor() {
  cout << "Autor destr." << endl;
  delete[] name, surname;
}
