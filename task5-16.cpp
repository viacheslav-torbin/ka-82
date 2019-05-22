#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Poem {
protected:
  string title;
  int size, payment;

public:
  Poem();
  Poem(string, int, int);
  Poem(const Poem &p) : Poem(p.title, p.size, p.payment){};
  string getTitle() { return title; };
  int getSize() { return size; };
  int getPayment() { return payment; };
  void setTitle(string);
  void setSize(int s) { size = s; };
  void setPayment(int pay) { payment = pay; };
  virtual void print();
  Poem operator+(Poem);
  friend ostream &operator<<(ostream &out, Poem &p) {
    out << "Title: " << p.title << "\n"
        << "Size: " << p.size << "\n"
        << "Payment: " << p.payment << endl;
  }
  friend istream &operator>>(istream &in, Poem &p) {
    in >> p.title >> p.size >> p.payment;
  }
  virtual ~Poem(){};
};

class Autor {
private:
  string name, surname;

public:
  Autor();
  Autor(string, string);
  Autor(const Autor &a) : Autor(a.name, a.surname){};
  void setName(string);
  void setSurname(string s);
  string getName() { return name; };
  string getSurname() { return surname; };
  void print();
  bool operator==(Autor &a) {
    return ((this->name == a.name) && (this->surname == a.surname));
  }
  ~Autor(){};
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
  Music(string t, int s, int p, float d, Autor a)
      : Poem(t, s, p), duration(d), autor(a){};
  void setDuration(float d) { duration = d; };
  float getDuration() { return duration; };
  void setAutor(Autor a) { autor = a; };
  virtual void print() {
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
  friend Poem;
  Book() : Poem(), pages(-1), autor(){};
  Book(string t, int s, int pay, int pages, Autor a)
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
  virtual void print() {
    Poem::print();
    cout << "Pages:" << pages << endl;
    autor.print();
  };
  Book(Music m);
  operator Music() {
    Music m;
    m.setTitle(this->title);
    m.setSize(this->size);
    m.setPayment(this->payment);
    m.setAutor(this->autor);
    m.setDuration(0);
  };
};

class Concert {
private:
  Autor autor;
  Music *arr;
  static int number;
  int size;

public:
  Concert();
  Concert(int s);
  Music &operator[](int n) {
    if ((n >= 0) && (n < size)) {
      return arr[n];
    }
  };
  ~Concert() { delete[] arr; }
  void print() {
    for (int i = 0; i < size; i++) {
      cout << "Number : " << i << endl;
      cout << arr[i] << endl;
    }
  }
};

int main() {
  int size;
  cout << "Enter size of Concert you want to create : " << endl;
  cin >> size;
  Concert c1 (size);
  c1.print();
  Book b1, b2;
  Music m1, m2;
  m1.print();
  b1 = m1;
  b1.print();
  return 0;
}

Poem::Poem() {
  title = "None";
  size = -1;
  payment = -1;
}

Poem::Poem(string title_, int size_, int payment_) {
  title = title_;
  size = size_;
  payment = payment_;
}

void Poem::setTitle(string title_) { title = title_; };

void Autor::setName(string n) { name = n; };

void Autor::setSurname(string s) { surname = s; }

Autor::Autor(string n, string s) {
  name = n;
  surname = s;
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
  name = "None";
  surname = "None";
}

Poem Poem::operator+(Poem p) {
  Poem temp;
  temp.payment = this->payment + p.payment;
  return temp;
}

int Concert::number = 0;

Concert::Concert() {
  size = 1;
  number++;
  arr = new Music[1];
  arr[0] = Music();
}

Concert::Concert(int s) {
  size = s;
  number += s;
  char answ;
  arr = new Music[size];
  for (int i = 0; i < size; i++) {
    cout << "Do you want to create default Music? (Y/N)" << endl;
    cin >> answ;
    if (answ == tolower('Y')) {
      arr[i] = Music();
    } else if (answ == tolower('N')) {
      cin >> arr[i];
    }
  }
}

Book::Book(Music m) {
  this->title = m.getTitle();
  this->size = m.getSize();
  this->payment = m.getPayment();
  this->autor = Autor();
  this->pages = 0;
}
