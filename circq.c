/*Write a C program to implement a circular queue using dynamically allocated array and perform the following operations on it-
(i) Insert an item (ii) Delete an item (iii) Display a circular queue*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct
{
        int key;
}element;
int c=2,f=0,r=0;
element *queue;
void copy(element *s,element *e,element *n)
{
        while(s!=e)
        {
                *n=*s;
                s++;
                n++;
        }
}
void isfull()
{
        element *newqueue;
        newqueue=(element*)malloc(c*2*sizeof(element));
        int start=(f+1)%c;
        if(start<2)
                copy(queue+start,queue+c+start-1,newqueue);
        else
        {
                copy(queue+start,queue+c,newqueue);
                copy(queue,queue+r+1,newqueue+c-start);
        }
        f=2*c-1;
        r=c-2;
        c=c*2;
        free(queue);
        queue=newqueue;
}
element isempty()
{
        element rem;
        rem.key=-9999;
        printf("Queue is Empty\n");
        return rem;
}
void push(element item)
{
        r=(r+1)%c;
        if(f==r)
        {
                isfull();
                r=r+1;
        }
        queue[r]=item;
}
element pop()
{
        if(f==r)
                return isempty();
        f=(f+1)%c;
        return queue[f];
}
void display()
{
        int front,rear;
        front=f;
        rear=r;
        if(front==rear)
                isempty();
        else
                while(front!=rear)
                {
                        front=(front+1)%c;
                        printf("%d \t",queue[front].key);
                }
        printf("\n");
}
int main()
{
        element item,rem;
        queue=(element*)malloc(c*sizeof(element));
        int ch;
        do
        {
                printf("1.Add\n2.Delete\n3.Display\n4.Exit\n\n");
                scanf("%d",&ch);
                printf("\n");
                switch(ch)
                {
                        case 1:printf("Enter the element\n");
                                   scanf("%d",&item.key);
                                push(item);
                                break;

                            case 2:rem=pop();
                                if(rem.key!=-9999)
                                printf("\n%d was removed\n",rem.key);
                                break;
                        case 3:display();
                }
        }while(ch!=4);
        getch();
  return 0;
}
