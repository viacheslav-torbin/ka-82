#include <iostream>
#include <string.h>
using namespace std;

class Poem {
private:
  char *title;
  int size, payment;

public:
  Poem();
  Poem(char *, int, int);
  Poem(const Poem &p) : Poem(p.title, p.size, p.payment){};
  char *getTitle() { return title; };
  int getSize() { return size; };
  int getPayment() { return payment; };
  void setTitle(char *);
  void setSize(int s) { size = s; };
  void setPayment(int pay) { payment = pay; };
  void print();
  Poem operator+(Poem);
  friend ostream &operator<<(ostream &out, Poem &p) {
    out << "Title: " << p.title << "\n"
        << "Size: " << p.size << "\n"
        << "Payment: " << p.payment << endl;
  }
  friend istream &operator>>(istream &in, Poem &p) {
    in >> p.title >> p.size >> p.payment;
  }
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
  bool operator==(Autor &a) {
    return ((strcmp(this->name, a.name) == 0) &&
            (strcmp(this->surname, a.surname) == 0));
  }
  ~Autor();
  friend ostream &operator<<(ostream &out, Autor &a) {
    return out << "Name: " << a.name << "\n"
               << "Surname: " << a.surname << endl;
  }
  friend istream &operator>>(istream &in, Autor &a) {
    return in >> a.name >> a.surname;
  }
};

class Music : public Poem {
private:
  float duration;
  Autor autor;

public:
  Music() : Poem(), duration(-1.0), autor(){};
  Music(char *t, int s, int p, float d, Autor a)
      : Poem(t, s, p), duration(d), autor(a){};
  void setDuration(float d) { duration = d; };
  float getDuration() { return duration; };
  void print() {
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
  Book() : Poem(), pages(-1), autor(){};
  Book(char *t, int s, int pay, int pages, Autor a)
      : Poem(t, s, pay), pages(pages), autor(a){};
  ~Book(){};
  void setPages(int p) { pages = p; };
  int getPages() { return pages; };
  Book &operator++(int i) {
    this->pages++;
    return *this;
  }
  Book &operator++() {
    this->pages = ++pages;
    return *this;
  }
  bool operator<(Book b) { return (this->pages < b.pages); }
  void print() {
    Poem::print();
    cout << "Pages:" << pages << endl;
    autor.print();
  };
};

int main() {
  Poem p1("First poem", 0, 10);
  Poem p2("Second poem", 10, 0);
  cout << "p1" << endl;
  p1.print();
  cout << "p2" << endl;
  p2.print();
  Poem p3;
  p3 = p1 + p2;
  cout << "p3" << endl;
  p3.print();
  Book b1;
  cout << "b1" << endl;
  b1.print();
  cout << "b1++ and ++b1" << endl;
  b1++;
  b1.print();
  ++b1;
  b1.print();
  Book b2;
  cout << "b1 < b2 : " << (b1 < b2) << endl;
  Autor a1, a2;
  cout << "a1 == a2 : " << (a1 == a2) << endl;
  cout << "Entering p1 using overloaded >>" << endl;
  cin >> p1;
  cout << "Poem p1 ( using overloaded << ) " << endl;
  cout << p1 << endl;
  cout << "Entering a1 using overloaded >>" << endl;
  cin >> a1;
  cout << "Autor a1 ( using overloaded << ) " << endl;
  cout << a1 << endl;

  return 0;
}

Poem::Poem() {
  title = new char[5];
  strcpy(title, "None");
  size = -1;
  payment = -1;
}

Poem::Poem(char *title_, int size_, int payment_) {
  title = new char[strlen(title_) + 1];
  strcpy(title, title_);
  size = size_;
  payment = payment_;
}

void Poem::setTitle(char *title_) {
  title = new char[strlen(title_) + 1];
  strcpy(title, title_);
};

Poem::~Poem() { delete[] title; }

void Autor::setName(char *n) {
  name = new char[strlen(n)];
  strcpy(name, n);
};

void Autor::setSurname(char *s) {
  surname = new char[strlen(s)];
  strcpy(surname, s);
}

Autor::Autor(char *n, char *s) {
  name = new char[strlen(n) + 1];
  strcpy(name, n);
  surname = new char[strlen(n) + 1];
  strcpy(surname, s);
};
void Autor::print() {
  cout << "Name:" << name << endl;
  cout << "Surname:" << surname << endl;
}

void Poem::print() {
  cout << "Title:" << title << endl;
  cout << "Size:" << size << endl;
  cout << "Payment:" << payment << endl;
}

Autor::Autor() {
  name = new char[5];
  strcpy(name, "None");
  surname = new char[5];
  strcpy(surname, "None");
}

Autor::~Autor() { delete[] name, surname; }

Poem Poem::operator+(Poem p) {
  Poem temp;
  temp.payment = this->payment + p.payment;
  return temp;
}
