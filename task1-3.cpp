#include <stdio.h>
#include <stdlib.h>
#define N 32



struct Chess {
	int x, y;
	char color[6];
};

Chess* p_arr[N];


int func1() { 
	printf("how many figures do you want to put?\n");
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		p_arr[i] = new Chess;
		printf("enter coordinates of a figure from 1 to 8 using a space bar\nlike this:\t2 4\n");
		scanf("%d%d", &p_arr[i]->x, &p_arr[i]->y);
		printf("what is the color of your figure?\n");
		scanf("%s", &p_arr[i]->color);
	}

	return n;
}


void func2(int n) {
	printf("the contents of the created array will be displayed.\n");
	for(int i=0; i<n; i++) {
		printf("Coordinates: (%d:%d)\nColor: %s\n", p_arr[i]->x, p_arr[i]->y, p_arr[i]->color);
	}

}


void func3(int n) {
	int quantity=0;
	for(int i=0; i<n; i++) {
		if((p_arr[i]->color!=0)&&(p_arr[i]->y<5)) quantity++;
	}
	printf("%d\n", quantity);
}


void func4(int k, int n) {
	for(int i=n; i>=k; i--) {
		p_arr[i+1]=p_arr[i];
	}
	p_arr[k]= new Chess;
	printf("enter coordinates of a new figure from 1 to 8 using a space bar\n");
	scanf("%d%d", &p_arr[k]->x, &p_arr[k]->y);
	printf("enter the color of your new figure\n(b or w?)\n");
	scanf("%s", &p_arr[k]->color);

}


void func5(int k, int j) {
	Chess* temp;
	if(k>j) {
		temp=p_arr[k];
		for(int i=k-1; i>=j; i--) {	
			p_arr[i+1]=p_arr[i];
		}
		p_arr[j]=temp;

	}
	else {
		temp=p_arr[k];
		for(int i=k; i<j-1; i--) {
			p_arr[i]=p_arr[i+1];
		}
		p_arr[j-1]=temp;
	}
	
}




int main() {
	int flag=0, n=0, k=0, j=0;

	printf("you can use func1 right now. continue?\n");
	scanf("%d", &flag);
	if(flag==0) {
		printf("ok, bye!\n");
		delete[]p_arr;
		exit(1);
		for(int i=0; i<N; i++) {
			delete [] p_arr[i];
		}
	}
	n=func1();

	printf("you can print it now. press 0 if you don't want to\n");
	scanf("%d", &flag);
	if(flag==0) {
		printf("ok, bye!\n");
		delete[]p_arr;
		exit(1);
		for(int i=0; i<N; i++) {
			delete [] p_arr[i];
		}
	}
	func2(n);

	printf("now you will see how many figures you have on the half of the board. press 0 if you don't wanto to\n");
	scanf("%d", &flag);
	if(flag==0) {
		printf("ok, bye!\n");
		delete[]p_arr;
		exit(1);
	}
	func3(n);

	do {
		printf("now you'll add a new element before the element nuber k\n");
		printf("enter k\n");
		scanf("%d", &k);
		func4(k, n);
		n++;
		func2(n);

		printf("now you'll place the element number k before the element number j\n");
		printf("enter k and j\n");
		scanf("%d%d", &k, &j);
		func5(k, j);
		func2(n);



		printf("one more time?\n");
		scanf("%d", &flag);
	}
	while(flag!=0);



	for(int i=0; i<N; i++) {
		delete [] p_arr[i];
	}
	return 0;
}
