//Write a C program to add two polynomials represented as circular linked lists with header nodes. Display both polynomials and the resultant polynomial after addition

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MALLOC(head,n,NODE) head=((NODE)malloc(n* sizeof(NODE)))
#define COMPARE(x,y) (((x)==(y))?0:((x)>(y))?1:-1)
int n=1;
struct node
 {
  int coeff,expon;
  struct node *link;
 };
typedef struct node *NODE;
void display(NODE head)
 {
  NODE temp;
  if(head->link==head)
   {
    printf("\nPolynomial does not exist\n");
    return;
   }
  temp=head->link;
  while(temp!=head)
   {
    if(temp->coeff<0) // to display negative coefficient
    printf("%2dx^%2d",temp->coeff,temp->expon);
    else // to display positive coefficient
    printf("+%2dx^%2d",temp->coeff,temp->expon);
    temp=temp->link;
   }
}
NODE attach(int coeff,int expon,NODE head)
 {
  NODE temp,cur;
  MALLOC(temp,1,NODE);
  temp->coeff=coeff;
  temp->expon=expon;
  cur=head->link;
  while(cur->link!=head)
   {
    cur=cur->link;
   }
  cur->link=temp;
  temp->link=head;
  return head;
 }
NODE read(NODE head)
 {
  int i=1,coeff,expon;
  printf("\nEnter the coefficient -999 to end the polynomial\n");
  while(1)  {
    printf("\nEnter the %d term\n",i++);
    printf("\nCoeff= ");
    scanf("%d",&coeff);
    if(coeff==-999)
    break;
    printf("\npower of x= ");
    scanf("%d",&expon);
    head=attach(coeff,expon,head);
   }
  return head;
 }
NODE polyadd(NODE head1,NODE head2,NODE head3)
 {
  NODE a,b;
  int coeff;
  a=head1->link;
  b=head2->link;
  while((a!=head1)&&(b!=head2))
    {
        switch(COMPARE(a->expon,b->expon))
       {
        case 0:  coeff =a->coeff+b->coeff;
                if(coeff!=0)
                head3=attach(coeff,a->expon,head3);
                a=a->link;
                b=b->link;
                break;
       case 1:  head3=attach(a->coeff,a->expon,head3);
                a=a->link;
                break;
       default: head3=attach(b->coeff,b->expon,head3);
                b=b->link;
                break;
       }
    }

     while(a!=head1) // Adding remaining terms of A
   {
       head3=attach(a->coeff,a->expon,head3);
       a=a->link;
   }
    while(b!=head2) // Adding remaining terms of B
   {
       head3=attach(b->coeff,b->expon,head3);
       b=b->link;
   }
   return head3;
 }
 int main()
 {
     NODE head1,head2,head3;
     MALLOC(head1,1,NODE);
     MALLOC(head2,1,NODE);
     MALLOC(head3,1,NODE);
     head1->link=head1;
     head2->link=head2;
     head3->link=head3;
     printf("\nEnter the first polynomial\n");
     head1=read(head1);
     printf("\nEnter the second polynomial\n");
     head2=read(head2);
     head3=polyadd(head1,head2,head3);
     printf("\nPolynomial 1:\t");
     display(head1);
     printf("\nPolynomial 2:\t");
     display(head2);
     printf("\nPolynomial 3:\t");
     display(head3);
     getch();
     return 0;
 }
