#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct Adress
{
	char city[40];
	char street[40];
	int number;
};

Adress** createAdressArray(int n)
{
	Adress**adresses = new Adress*[n];
	for(int i=0;i<n;i++)
	{
		adresses[i]= new Adress;
		puts("\ncity:");
		gets(adresses[i]->city);
		puts("street:");
		gets(adresses[i]->street);
		puts("number:");
		cin >> adresses[i]->number;
		getchar();
	}
	return adresses;
}

void print(Adress** adr, int n)
{
	puts("\nArray:");
	for(int i=0;i<n;i++)
	{
		printf("%s %s %d\n",adr[i]->city, adr[i]->street, adr[i]->number);
	}
}

int onStreet(char* street, Adress**arr, int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if (!strcmp((arr[i]->street),street)) count++;
	}
	return count;
}

void add(Adress**&arr, int &n, int k)
{
	Adress** tmp=(Adress**)realloc(arr,sizeof(Adress*)*(n+1));
	if (!tmp) 
	{
		cout << "Memory error";
		return;
	}
	
	Adress *adress = new Adress;
	
	puts("\ncity:");
	gets(adress->city);
	puts("street:");
	gets(adress->street);
	puts("number:");
	cin >> adress->number;
	getchar();
	
	n++;
	
	arr=tmp;
	
	for (int i=n;i>k;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[k]=adress;
	
}

void swap(Adress**&arr, int j, int k)
{
	Adress* tmp = arr[j];
	arr[j]=arr[k];
	arr[k]=tmp;
}

void filePrint(Adress** adr, int n, int m)
{
	FILE * f;
	if (f = fopen("textfile.txt","wt"))
	{
		if (m > n) m = n;
		for (int i = 0; i < m; i++)
	    {
	    	fprintf(f, "%s, %s street, %d\n", adr[i]->city, adr[i]->street, adr[i]->number);
	    }
		fclose(f);
	}
}

int main()
{
	int n;
	puts("enter n:");
	cin >> n;
	getchar();
	Adress**adresses = createAdressArray(n);
	
	print(adresses, n);
	
	puts("\ncount on the street");
	char str[40];
	gets(str);
	cout << onStreet(str,adresses, n);
	
	puts("\n\nadd after: ");
	int k;
	cin >> k;
	getchar();
	add(adresses,n,k);
	print(adresses, n);
	
	int j;
	puts("\nswap j and k");
	cin >> j >> k;
	swap(adresses,j,k);
	print(adresses, n);
	
	puts("\nhow many addresses to write to a file?");
	int m;
	cin >> m;
	filePrint(adresses, n, m);
	
	return 0;
}

