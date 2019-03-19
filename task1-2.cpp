#include<math.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
//#include<conio.h>

struct chess
{
	char name ;
	int number;
	char place;
};
int main ()
{//заполнить структуру с клавиатуры

	int i;
	struct chess figure[5];
	for(i=0;i<5;i++)
	{
	printf ("enter a name\n");
	scanf ("%c\n", &figure[i].name);
	printf ("enter a number\n");
	scanf ("%d\n", &figure[i].number);
	printf ("enter a place\n");
	scanf ("%c\n", &figure[i].place);
	}
//вывести содержимое структуры на экран
for (i = 0; i<5; i++)
  {
    printf("%c%d%c", figure[i].name, figure[i].number, figure[i].place);
  }
  getchar();
  return 0;

  //поменять местами элементы k,j
  	char temp1, temp3;
  	int k,j,temp2;
  	printf ("enter element1\n");
	scanf ("%d\n", &k);
	printf ("enter element2\n");
	scanf ("%d\n", &j);
	temp1=figure[k].name;
	temp2=figure[k].number;
	temp3=figure[k].place;
	figure[j].name=figure[k].name;
	figure[j].number=figure[k].number;
	figure[j].place=figure[k].place;
	temp1=figure[j].name;
	temp2=figure[j].number;
	temp3=figure[j].place;

//удаление элемента k
	for (;k<5;k++)
	{
		figure[k+1].name=figure[k].name;
		figure[k+1].number=figure[k].number;
		figure[k+1].place=figure[k].place;
	}




}
