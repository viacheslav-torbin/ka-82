//RKP-I

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <conio.h>
using namespace std;

#define V ((*rhs)->obj.width * (*rhs)->obj.length * (*rhs)->obj.height)
#define M ((*lhs)->obj.width * (*lhs)->obj.length * (*lhs)->obj.height)

struct Exp;
Exp *CreateNode(char naming[], int wid, int leng, int hei);
Exp *AddNode(Exp *Head, Exp *NewNode);
void PrintList(Exp *Head);
void EditK(Exp *Head, int k);
void Swap(Exp *p, Exp *t);
void Sort(Exp **Head);
void Delete(Exp **Head, int k);
int Fileoutkey(Exp *Head, int k);

//ofstream fout("rkp1bin.bin");

//int Fileoutk(Exp *Head, int k);
//int Fileink(Exp *Head, int k);

int main()
{
	//char * buff;
	int k;
	Exp *Head = NULL;

	Exp *exp0 = CreateNode("Golova", 56, 77, 88);
	Head = AddNode(Head, exp0);

	Exp *exp1 = CreateNode("Ruka", 10, 40, 4);
	Head = AddNode(Head, exp1);

	Exp *exp2 = CreateNode("Noga", 89, 41, 20);
	Head = AddNode(Head, exp2);
	
	Exp *exp3 = CreateNode("Dolonya", 7, 15, 10);
	Head = AddNode(Head, exp3);

	PrintList(Head);
	
	printf("Enter the number of element that you want to change: ");
	scanf("%d", &k);
	
	EditK(Head, k);
	PrintList(Head);
	
	Sort(&Head);
	PrintList(Head);
	
	Delete(&Head, k);
	PrintList(Head);
	
	//ofstream fout("rkp1.txt");
	//fileoutk(Head, k);
	//system("pause");
	
	Fileoutkey(Head, k);
	
	//printf("\nReading from file... Done.\n\n");
	//fileink(Head, k);

	return 0;	
}


struct A
{
    int width;
    int length;
    int height;
    char name[20];
    //struct Exp * next;
};

struct Exp
{
	A obj;
	Exp * next;
};

Exp *CreateNode(char naming[], int wid, int leng, int hei)
{
	Exp *NewNode = (Exp*) malloc(sizeof(Exp));
	strcpy(NewNode->obj.name, naming);	
	NewNode->obj.width = wid;
	NewNode->obj.length = leng;
	NewNode->obj.height = hei;

	NewNode->next = NULL;
	return NewNode;
}

Exp *AddNode(Exp *Head, Exp *NewNode)
{
	if (!Head) return NewNode;
	else
	{
		NewNode->next = Head;
		Head = NewNode;	
	}
}

void PrintList(Exp *Head)
{
	printf("\nLIST:\n");
	if (!Head)
		printf("List is empty!");
	else
	{
		Exp *p = Head;
		while (p)
		{
			printf("Name: %s:\n", p->obj.name); 
			printf("\t Width: %d\n", p->obj.width);
			printf("\t Length: %d\n", p->obj.length);
			printf("\t Width: %d\n", p->obj.height); 
			p = p->next;
		}
	}
}

void EditK(Exp *Head, int k)
{
	int i = 0;
	Exp *p = Head;

	while(i < k)
	{
		p = p->next;
		i++;
	}
	
	printf("\nNew Name:");
	char Name[20];
	scanf("%s", &Name);
	strcpy(p->obj.name, Name);
	printf("\nNew Width: ");
	scanf("%d", &(p->obj.width));
	printf("\nNew Length: ");
	scanf("%d", &(p->obj.length));
	printf("\nNew Height: ");
	scanf("%d", &(p->obj.height));
}

void Swap(Exp *p, Exp *t)
{
	Exp *temp = p;
	
	strcpy(temp->obj.name, p->obj.name);
	strcpy(p->obj.name, t->obj.name);
	strcpy(t->obj.name, temp->obj.name);
	
	
	temp->obj.width = p->obj.width;
	p->obj.width = t->obj.width;
	t->obj.width = temp->obj.width;
	
	temp->obj.length = p->obj.length;
	p->obj.length = t->obj.length;
	t->obj.length = temp->obj.length;
	
	temp->obj.height = p->obj.height;
	p->obj.height = t->obj.height;
	t->obj.height = temp->obj.height;
}

void Sort(Exp **Head)
{
	Exp *p = *Head;
	*Head = NULL;
	
	while(p)
	{
		Exp **lhs = &p;
		Exp **rhs = &p->next;
		int swapped = 0;
		
		while(*rhs)
		{
			if(V < M)
			{
				swap(*lhs, *rhs);
				swap((*lhs)->next, (*rhs)->next);
				lhs = &(*lhs)->next;
				swapped = 1;
			}
			else
			{
				lhs = rhs;
				rhs = &(*rhs)->next;
			}
		}
		
		*rhs = *Head;
		
		if (swapped)
		{
			*Head = *lhs;
			*lhs = NULL;
		}
		else
		{
			*Head = p;
			break; 	
		}
	}
}

void Delete(Exp **Head, int k)
{
	if (!(*Head)->next)
	{
		free(*Head);
	}
	else
	{
		Exp *t = *Head;
		for(int i = 0; i < k; i++)
		{
			t = t->next;
		}
		
		Exp *p = t;
		
		while (p->next != NULL)
    	{
    		p = t->next;
       	 	t->next = p->next;
       	 	free (p);
    	}
	}	
}

int Fileoutkey(Exp *Head, int k) //KANON
{
	FILE *fp;
	if(fp = fopen("rkp1_text.bin", "wb"))
	{
		Exp *p = Head;
		for(int i = 0; i < k; i++)
			p = p->next;
	
		fwrite(&(p->obj), sizeof(A), 1, fp);
		//fprintf(fp, "Name: %s\n", p->name);
		//fprintf(fp, "Width: %d\n", p->width);
		//fprintf(fp, "Width: %d\n", p->length);
		//fprintf(fp, "Height: %d\n", p->height);
		fclose(fp);
	}
	else
	{
		printf("No such file in directory.\n");
		exit(1);
	}
}
