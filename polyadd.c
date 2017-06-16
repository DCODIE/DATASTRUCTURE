//Write a C program to perform addition of two polynomials using an array. (Represent both polynomials as well as the resultant polynomial in a single array. Display both polynomials and the resultant polynomial after addition).

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<conio.h>
#define MAX 100
#define COMPARE(a,b) (((a)>(b))? 1 :(((a)<(b)) ? -1 : 0))
struct eqn
{
    int coef;
    int exp;
};
struct eqn terms[MAX];
int avail=0;
void display(int startD, int endD);
void attach(int coef,int exp)
{
   if(avail>=MAX)
   {
      printf("\nInsufficient memory space");
      exit(0);
   }
   else
   {
      terms[avail].coef= coef;
      terms[avail].exp= exp;
      avail++;
   }
}
void padd(int startA, int endA, int startB, int endB)
{
    int coef,cnt=0;
    int  startD= endB+1;
    while(startA<= endA && startB<= endB)
    {
       switch(COMPARE(terms[startA].exp, terms[startB].exp))
       {
          case 1:
                 attach(terms[startA].coef, terms[startA].exp);
                 startA++;
                 cnt++;
                 break;
          case -1:
                 attach(terms[startB].coef, terms[startB].exp);
                 startB++;
                  cnt++;
                 break;
          case 0:
                 attach((terms[startA].coef + terms[startB].coef), terms[startA].exp);
                 startA++;
                 startB++;
                 cnt++;
                 break;
      }
}
      while(startA<= endA)
      {
          attach(terms[startA].coef, terms[startA].exp);
          startA++;
          cnt++;
      }
      while(startB<= endB)
      {
          attach(terms[startB].coef, terms[startB].exp);
          startB++;
          cnt++;
      }
      int endD= startD+ cnt-1;
     printf("\nAddition of two polynomials is:\n ");
      display(startD, endD);
}
void display(int start, int end)
{
     int i;
     //printf("\nThe addition of the given polynomial results in ");
     for(i=start;i<=end;i++)
     {
        if(i==start)
        printf("%dx^%d",terms[i].coef, terms[i].exp);
        else
        printf(" + %dx^%d ",terms[i].coef, terms[i].exp);
     }
}
void evaluate(int startA, int endA, int x)
{
     int res=0,i;
     for(i=startA;i<=endA;i++)
     {
         res+= terms[i].coef* pow(x,terms[i].exp);
     }
     printf("\nValue= %d", res);
}
int main()
{
     int i, nA, nB, startA, startB, endA, endB, coef, exp,ch,x;
     printf("\nMenu\n1.Addition of two polynomials\n2.Evaluation of a polynomial\nEnter your choice:");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1: printf("\nEnter the number of terms for first polynomial: ");
                scanf("%d", &nA);
                startA=0;
                endA= startA+ nA -1;
                for(i=startA; i<=endA; i++)
                 {
                  printf("\nEnter the coefficient and exponent: ");
                  scanf("%d %d", &coef, &exp);
                  attach(coef,exp);
                 }
                printf("\nEnter the number of terms for second polynomial: ");
                scanf("%d", &nB);
                startB= endA+1;
                endB= startB + nB -1;
                for(i=startB; i<=endB; i++)
                 {
                    printf("\nEnter the coefficient and exponent: ");
                    scanf("%d %d", &coef, &exp);
                    attach(coef,exp);
                 }
                printf("\nFirst polynomial is: ");
                display(startA,endA);
                printf("\nSecond polynomial is: ");
                display(startB,endB);
                padd(startA, endA, startB, endB);
                break;
     case 2:    printf("\nEnter the number of terms for polynomial: ");
                scanf("%d", &nA);
                startA=0;
                endA= startA+ nA -1;
                for(i=startA; i<=endA; i++)
                 {
                    printf("\nEnter the coefficient and exponent: ");
                    scanf("%d %d", &coef, &exp);
                    attach(coef,exp);
                 }
                printf("\nPoynomial is: ");
                display(startA,endA);
                printf("\nEnter the value of x: ");
                scanf("%d",&x);
                evaluate(startA,endA,x);
                break;
      }
      getch();
    return 0;
}
