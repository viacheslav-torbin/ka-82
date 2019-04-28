#define _KP4_
#include "task3-9.cpp"

IndustrialGoods& operator+(IndustrialGoods& o, int a)
{
	o.setPrice(o.getPrice()+a);
	return o;
}

IndustrialGoods& operator++(IndustrialGoods& o)
{
	o.setPrice(o.getPrice()+10);
	return o;
}

bool operator < (Artwork& a, Artwork& b)
{
	return a.getYear() < b.getYear();
}

bool operator == (Exhibit& e1, Exhibit& e2)
{
	return (e1.getHeight()+e1.getLength()+e1.getWidth() == e2.getHeight()+e2.getLength()+e2.getWidth());
}

ostream& operator << (ostream& o, Address& a)
{
	return o << a.getCity() << ", " << a.getStreet() << " " << a.getNumber();
}

istream& operator >> (istream& i, Address& a)
{
	char c[40], s[40];
	int n;
	i >> c >> s >> n;
	a.setCity(c).setStreet(s).setNumber(n);
	return i;
}

int main()
{
	cout << "IndustrialGoods operators:\n";
	IndustrialGoods obj1;
	cout << obj1.getPrice() << "\n";
	obj1 = obj1+12;
	cout << obj1.getPrice() << "\n";;
	++obj1;
	cout << obj1.getPrice() << "\n";;
	
	cout << "\nArtwork operator:\n";
	Artwork a;
	Artwork b;
	a.setYear(2017);
	b.setYear(2019);
	int q = a<b;
	cout << q << "\n";
	
	cout << "\nAddress operators:\n";
	Address adr;
	cin >> adr;
	cout << adr;
	
	
}
