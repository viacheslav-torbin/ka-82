#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Product {
  char name[40];
  float price;
  char firm[40];
};

struct l_l {
  struct Product prod;
  l_l * next;
};

struct l_l *create_node();
void add_tail(l_l *head);
void change_k(l_l *head, int k);
void print_list(l_l *head);
void count_firm(l_l *head);
void swap(l_l *head, int k, int j);

int main(){
  char answ;
  struct l_l *head = NULL, *node = NULL;
  head = create_node();
  printf("Do you want to add more products? (y/n)\n");
  scanf(" %c", &answ);
  while (tolower(answ)=='y') {
    add_tail(head);
    printf("Do you want to add more products? (y/n)\n");
    scanf(" %c", &answ);
  }
  print_list(head);
  int d=0;
  printf("What you want to do?\n1-Add product to tail\n2-Change product\n3-Print all list\n4-Count products of firm\n5-Swap products\n");
  scanf("%d", &d);
  switch (d) {
    case 1:{
      add_tail(head);
      print_list(head);
      break;
    }
    case 2:{
      int k;
      printf("Enter number of product to change\n");
      scanf("%d", &k);
      change_k(head, k);
      print_list(head);
      break;
    }
    case 3:{
      print_list(head);
      break;
    }
    case 4:{
      count_firm(head);
      break;
    }
    case 5:{
      int a,b;
      printf("Enter numbers to switch\n");
      scanf("%d %d", &a, &b);
      swap(head,a,b);
      break;
    }
  }
}

struct l_l *create_node(){
  struct l_l *result = new l_l;
  if(result){
    printf("Enter name of product\n");
    scanf("%s", result->prod.name);
    printf("Enter price\n");
    scanf("%f", &result->prod.price);
    printf("Enter name of firm\n");
    scanf("%s", result->prod.firm);
  }
  else{
    printf("Memory error!\n");
    return 0;
  }
  result->next=NULL;
  return result;
}

void add_tail(l_l *head){
  struct l_l *x = head;
  while (x->next) {
    x=x->next;
  }
  x->next=create_node();
}

void change_k(l_l *head, int k) {
  struct l_l *x=head;
  for (int i = 1; i < k-1 , x!=NULL, x->next!=NULL; i++) {
    x=x->next;
  }
  printf("Enter changed name of product\n");
  scanf("%s", x->prod.name);
  printf("Enter changed price\n");
  scanf("%f", &x->prod.price);
  printf("Enter changed name of firm\n");
  scanf("%s", x->prod.firm);
  delete x;
}

void print_list(l_l *head) {
  struct l_l *x=head;
  if(x){
    while (x) {
      printf("Name:%s\nPrice:%.2f\nFirm:%s\n", x->prod.name, x->prod.price, x->prod.firm);
      x=x->next;
    }
  }
  else {
    printf("List is empty!\n");
  }
  printf("\n");
}

void count_firm(struct l_l *head) {
  struct l_l *x=head;
  char s[40];
  printf("Enter firm to count\n");
  scanf("%s", s);
  int i=0;
  if (x) {
    while (x) {
      if(!strcmp(x->prod.firm, s)){
        i++;
      }
      x=x->next;
    }
  }
  else {
    printf("List is empty!\n");
  }
  printf("Number of products of firm %s is %d\n",s,i);
}

void swap(l_l *head, int k, int j){
  struct l_l *x=head, *a, *b, *t;
  for (int i = 0; i < k, x; i++) {
    x=x->next;
  }
  a=x;
  for (int i = k-1; i < j, x; i++) {
    x=x->next;
  }
  b=x;
  strcpy(t->prod.name, a->prod.name);
  strcpy(t->prod.firm, a->prod.firm);
  t->prod.price = a->prod.price;
  strcpy(a->prod.name, b->prod.name);
  strcpy(a->prod.firm, b->prod.firm);
  a->prod.price = b->prod.price;
  strcpy(b->prod.name, t->prod.name);
  strcpy(b->prod.firm, t->prod.firm);
  b->prod.price = t->prod.price;
  delete t, a, b, x;
}
