#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define N 100

struct Adress{
	char surname[20], town[25], street[40];
  	int house, flat;
};

int is_equal(char s1[], char s2[]){
  	if (strlen(s1)!=strlen(s2)) return 0;
  	int n=strlen(s1);
  	for (int i=0; i<n; i++){
  		if (tolower(s1[i])!=tolower(s2[i])) return 0;
 	}
 	return 1;
}

void upcase(char s[]){
  	s[0]=toupper(s[0]);
  	for (int i=1; i<strlen(s); i++)
    	s[i]=tolower(s[i]);
}

// 1.1. create array of structures
void create(Adress* a[], int n){
  	for (int i=0; i<n; i++)
    	a[i]=new Adress;
}

// 1.2. fill structure
void fill(Adress* a[], int n){
  	for (int i=0; i<n; i++){
    	printf("Enter surname: ");
    	scanf("%s", a[i]->surname);
    	printf("Enter town: ");
    	scanf("%s", a[i]->town);
    	printf("Enter street: ");
    	scanf("%s", &(a[i]->street));
    	printf("Enter house and flat N: ");
    	scanf("%d %d", &(a[i]->house), &(a[i]->flat));
  	}
}

// 2. print array
void out(Adress* a[], int n){
  	for (int i=0; i<n; i++)
    	printf("%i. %s: %s, %s %i, fl. %i\n", i+1, a[i]->surname, a[i]->town, a[i]->street, a[i]->house, a[i]->flat);
}

// extra: print array to file
void outf(Adress* a[], int n, char town[]){
  	FILE *fp;
  	char fname[]="lab.txt";
  	if ((fp=fopen(fname, "w"))==NULL){
    	printf("Cannot open file %s\n", fname);
    	exit(1);
  	}
  	for (int i=0; i<n; i++){
    	if (is_equal(town, a[i]->town))
      	fprintf(fp, "%s, %s\n", a[i]->surname, a[i]->street);
  	}
  	fclose(fp);
  	
  	FILE *fb;
  	char bname[]="lab.dat";
  	if ((fb=fopen(bname, "wb"))==NULL){
    	printf("Cannot open file %s\n", bname);
    	exit(1);
  	}
  	for (int i=0; i<n; i++){
    	if (is_equal(town, a[i]->town))
      	fwrite(a, sizeof(Adress), 1, fb);
  	}
  	fclose(fb);
}

// count people from one town
int count(Adress* a[], int n, char town[]){
  	int count=0;
  	for (int i=0; i<n; i++){
    if (is_equal(town, a[i]->town))
      count++;
  	}
  	return count;
}

// add element after k
void add(Adress* a[], int n, int k){
  	a[n]=new Adress;
  	for (int i=k; i<n; i++){
    	strcpy(a[i+1]->surname,a[i]->surname); 
    	strcpy(a[i+1]->town,a[i]->town); 
    	strcpy(a[i+1]->street,a[i]->street); 
    	a[i+1]->house=a[i]->house; 
    	a[i+1]->flat=a[i]->flat; 
  	}
    printf("Enter surname: ");
    scanf("%s", a[k]->surname);
    printf("Enter town: ");
    scanf("%s", a[k]->town);
    printf("Enter street: ");
    scanf("%s", &(a[k]->street));
    printf("Enter house and flat N: ");
    scanf("%d %d", &(a[k]->house), &(a[k]->flat));
}

//swap town for k and j
void swap(Adress* a[], int n, int k, int j){
	char temp[25];
	strcpy(temp, a[k-1]->town);
	strcpy(a[k-1]->town, a[j-1]->town);
	strcpy(a[j-1]->town, temp);
}

// delete array
void del(Adress* a[], int n){
  	for (int i=0; i<n; i++) delete a[i];
}

int main(){
  	int n,k,j; char s[80];  
  	Adress *list[N];
  	printf("How many adresses?\n");
  	scanf("%i", &n);
  	create(list, n);
  	fill(list, n);
  	out(list, n);
	printf("\nEnter town to count people from one town: ");
  	scanf("%s", s); upcase(s);
  	printf("There are %i people from %s\n", count(list, n, s), s);
 	outf(list, n, s);
 	do {
 		printf("Enter k to add element after k:\n");
 		scanf("%i", &k);
	} while ((k>n) || (k<0));
  	add(list, n, k); n++;
  	out(list, n);
  	//do {
 		printf("Enter k and j to swap k and j towns:\n");
 		scanf("%i %i", &k, &j);
	//} while (!((k<n) && (j<n) && (k>0) && (j>0)));
	swap(list, n, k, j);
	out(list, n);
  	del(list, n);
}
