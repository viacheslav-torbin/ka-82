#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_SIZE 10
#define ARRAY_SIZE 4

struct Solar_System
{
	char planet [MAX_NAME_SIZE];
    int distance;
};

void create_element(Solar_System x)
{
    printf("Planet: ");
    scanf("%s", x.planet);
		//printf("%s\n", x.planet);

    printf("Distance=");
    scanf(" %d", &x.distance);
}

void print_element(Solar_System x)
{
	printf("Planet: %s ; Distance: %d", x.planet, x.distance));
}

void print_array(Solar_System arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
		print_element(arr[i]);
        printf("\n");
    }
}


int size_of_array(Solar_System* arr[])
{
    int array_size = 0;

    for (int i = 0; arr[i] != NULL; i++)
    {
        array_size++;
    }

    return array_size;
}

void swap_elements(Solar_System arr[], int j, int k, int size)
{

    if ((j >= size) || (k >= size))
    {
        return;
    }

    Solar_System p = arr[j];
    arr[j] = arr[k];
    arr[k] = p;
}

void delete_element(Solar_System arr[], int k, int size)
{


    if (k >= size)
    {
        return;
    }


    for (int i = k; i < size-1; i++)
    {
	   arr[i] = arr[i+1];
    }

    //arr[array_size - 1] = NULL;
}

int main()
{	Solar_System* array= new Solar_System[ARRAY_SIZE + 1];
    int size_of_array=0;


    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        create_element(array[i]);
        printf("\n");
		size_of_array++;
    }

	int choice=1;
	while (choice!=0)
	{ printf(" Choose action: \n");
	scanf("%d",&choice);
	switch (choice)
	{ case 1 :{ print_array(array, size_of_array);break;};
	case 2: {printf("Size: %d \n",size_of_array);break;};
	case 3: {int j = 0;
    printf("j=");
    scanf("%d", &j);

    int k = 0;
    printf("k=");
    scanf("%d", &k);

    swap_elements(array, j, k, size_of_array);
	print_array(array,size_of_array);
	break;};

	case 4 : {
	int k;
	printf("delete k=");
    scanf("%d", &k);
    delete_element(array, k, size_of_array);
		size_of_array--;
	print_array(array,size_of_array);
	break;};

	case 5 :break;
	}
	}

    return 0;
}
