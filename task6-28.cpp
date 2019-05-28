#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;

class Complex{
	double Re, Im;
public:
	Complex(){Re=0.0; Im=0.0;};
	Complex(double r, double i){Re=r; Im=i;};
	bool operator<(Complex&);
	bool operator>(Complex&);
	Complex& operator=(Complex&);
	friend ostream& operator<<(ostream&, Complex&);
	friend istream& operator>>(istream&, Complex&);
};

bool Complex::operator>(Complex &c){
	if (fabs(this->Re - c.Re)<0.000001){
		return (this->Im > c.Im);
	}
	else return(this->Re > c.Re);
}

bool Complex::operator<(Complex &c){
	if (fabs(this->Re - c.Re)<0.000001){
		return (this->Im < c.Im);
	}
	else return(this->Re < c.Re);
}

Complex& Complex::operator=(Complex &c){
	Re = c.Re;
	Im = c.Im;
}

ostream& operator<<(ostream &out, Complex &c){
	if (c.Im>=0){
		out<<c.Re<<"+"<<c.Im<<"i";
	} 
	else out<<c.Re<<c.Im<<"i";
	return out;
}

istream& operator>>(istream &in, Complex &c){
	in>>c.Re>>c.Im;
	return in;
}

template <class T> void sort(T arr[], int size){
	T temp;
	for (int k=size-2; k>=0; k--){
		for (int i=0; i<=k; i++){
			if (arr[i+1]<arr[i]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}

template <class T> bool is_less(T el1, T el2){
	return el1<el2;
}

template <class T> void insert(T arr[], int size, T element){
	int k; T temp;
	if (is_less(element, arr[0])){
		for (int i=size; i>0; i--)
			arr[i] = arr[i-1];
		arr[0] = element;
	} else{
		if (is_less(arr[size-1], element)) arr[size] = element;
		else {
			for (int i=0; i<size; i++)
				if (is_less(arr[i], element) && is_less(element, arr[i+1])) k=i+1;
			for (int i=size; i>k; i--)
				arr[i] = arr[i-1];
			arr[k] = element;
		}		
	}
	
}

int main(){
	int size;
	int *arr_i; Complex *arr_c;
	srand(time(NULL));
	cout<<"enter arrays size: "; cin>>size;
	arr_i = new int[size+1]; arr_c = new Complex[size+2];
	for (int i=0; i<size; i++){
		arr_i[i] = rand()%20-10;
		Complex temp(double(rand()%20-10),double(rand()%20-10));
		arr_c[i] = temp;
	} cout<<endl;
	cout<<"int array: "<<endl;
	for (int i=0; i<size; i++)
		cout<<arr_i[i]<<" "; cout<<endl;
	cout<<"complex array: "<<endl;
	for (int i=0; i<size; i++)
		cout<<arr_c[i]<<" "; cout<<endl;

	sort(arr_i, size); sort(arr_c, size);
	cout<<endl;
	cout<<"sorted int array: "<<endl;
	for (int i=0; i<size; i++)
		cout<<arr_i[i]<<" "; cout<<endl;
	cout<<"sorted complex array: "<<endl;
	for (int i=0; i<size; i++)
		cout<<arr_c[i]<<" "; cout<<endl;

	int x; Complex z; cout<<endl;
	cout<<"enter int x to insert: ";
	cin>>x;
	insert(arr_i, size, x);
	for (int i=0; i<size+1; i++)
		cout<<arr_i[i]<<" "; cout<<endl;
	cout<<"enter complex z to insert: ";
	cin>>z;
	insert(arr_c, size, z);
	for (int i=0; i<size+1; i++)
		cout<<arr_c[i]<<" "; cout<<endl;

	cout<<endl;
	cout<<"enter complex z to insert (explicit instantiation used): ";
	cin>>z;
	insert <Complex> (arr_c, size, z);
	for (int i=0; i<size+1; i++)
		cout<<arr_c[i]<<" "; cout<<endl;



	system("pause");
}