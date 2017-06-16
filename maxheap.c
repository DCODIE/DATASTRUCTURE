/*Write a C program to implement a max heap using an array and perform the following
operations on it-
(i)	Insert an item (ii) Delete an item (iii) Display a heap*/

#include<stdio.h>
#define MAX 200
typedef struct
{
int key;
}element;
element heap[MAX];
void insert(element item,int *n)
{
int i=++(*n);
while(i!=1&&item.key>heap[i/2].key)
{
heap[i]=heap[i/2];
i=i/2;
}
heap[i]=item;
}
element delete(int *n)
{
int child=2,parent=1;
element item,temp;
if(n==0)
{
item.key=-9999;
printf("Empty heap\n");
return item;
}
item=heap[1];
temp=heap[(*n)--];
while(child<=*n)
{
if(child<*n&&heap[child].key<heap[child+1].key)
child++;
if(temp.key>=heap[child].key)
break;
heap[parent]=heap[child];
parent=child;
child*=2;
}
heap[parent]=temp;
return item;
}
void display(int n)
{
int i;
if(n==0)
printf("Empty heap\n");
else
for(i=1;i<=n;i++)
printf("%d ",heap[i].key);
printf("\n");
}
void main()
{
element item;
int ch,n=0;
do
{
printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter element to be inserted\n");
scanf("%d",&item.key);
insert(item,&n);
break;
case 2:item=delete(&n);
if(item.key!=-9999)
printf("%d deleted\n",item.key);
break;
case 3:display(n);
}
}while(ch!=4);
}
