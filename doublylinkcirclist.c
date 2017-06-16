/*Write a C program to implement a doubly linked circular list with a header node and perform the following operations on it-
(i) Insert a node (iii) Display a doubly linked circular list in forward direction
(ii) Delete a node (iv) Display a doubly linked circular list in reverse direction*/

#include<stdio.h>
#include<stdlib.h>
struct node
   {
    int info; struct node *llink,*rlink;
   };
typedef struct node *NODE;
int n=1;
#define MALLOC(temp,n,NODE) temp=((NODE)malloc(n* sizeof(NODE)))
NODE insertfront(int item,NODE head)
{
    NODE temp,cur;
    MALLOC(temp,1,NODE); //node to be inserted
    temp->info=item;
    cur=head->rlink;//obtain address of 1st node
    head->rlink=temp;//insert between header and 1st node
    temp->llink=head;
    temp->rlink=cur;
    cur->llink=temp;
    return head;
}
NODE deleteitem(int item,NODE head)
{
    NODE prev,cur,next;
    if(head->rlink==head)
    {
        printf("\nList is Empty\n"); return head;
    }
    cur=head->rlink;//find address of node to be deleted
    while(cur!=head)
    {
        if(item==cur->info)
            break;
        cur=cur->rlink;
    }
    if(cur==head)
    {
        printf("\nItem not found\n");return head;
    }
    prev=cur->llink;//obtain address of predecessor
    next=cur->rlink;//Obtain address of succesor
    prev->rlink=next;
    next->llink=prev;
    free(cur);
    return head;
}
void displayforward(NODE head)
{
    NODE temp;
    if(head->rlink==head)
    {
        printf("\nEMPTY\n");
        return;
    }
    printf("\nCONTENTS\n");
    temp=head->rlink;
    while(temp!=head)
    {
        printf("\t%d",temp->info);
        temp=temp->rlink;
    }
}
void displaybackward(NODE head)
{
    NODE temp;
    if(head->rlink==head)
    {
        printf("\nEMPTY\n");
        return;
    }
    printf("\nCONTENTS\n");
    temp=head->llink;
    while(temp!=head)
    {
        printf("\t%d",temp->info);
        temp=temp->llink;
    }
}
int main()
{
    NODE head;
    int choice,item;
    MALLOC(head,1,NODE);
    head->rlink=head;
    head->llink=head;
    for(;;)
    {
        printf("\n1.Insert node\n2.Delete node\n3.Display forward\n4.Display backward\nEnter your choice");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:printf("Enter item to be inserted");
                scanf("%d",&item);
                head=insertfront(item,head);
                break;
         case 2:printf("Enter item to be deleted");
                scanf("%d",&item);
                head=deleteitem(item,head);
                break;
         case 3:displayforward(head);
                break;
         case 4:displaybackward(head);
                break;
            default: exit(0);
        }
    }
}
