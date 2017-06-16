/*Write a C program to implement a binary search tree and perform the following operations on it.
(i) Insert an item (ii) Search an item (iii) Inorder Traversal*/


#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *llink;
  struct node *rlink;
};
 typedef struct node *treeptr;
 treeptr root=NULL;

void insert(treeptr *root,int d)
{
   if(*root==NULL)
     {
       *root=(treeptr)malloc(sizeof(treeptr));
       (*root)->data=d;
        (*root)->llink=NULL;
        (*root)->rlink=NULL;
        return;
     }
   else if(d<(*root)->data)
        insert(&(*root)->llink,d);
   else insert(&(*root)->rlink,d);
}

void inorder(treeptr root)
{
    if(root)
    {
        inorder(root->llink);
        printf("%d ",root->data);
        inorder(root->rlink);
    }
}

treeptr search(treeptr root,int value)
{
    if(!root)
        return NULL;
    if(value==root->data)
        return root;
    if(value<root->data)
        return(search(root->llink,value));
    else
        return(search(root->rlink,value));
}

void main()
{
   int d,ch,val;
   treeptr s=NULL;
   do
   {
      printf("\nEnter your choice from below\n");
      printf("1-insert\t2-inorder traversal\t3-search\t4-exit\n");
      scanf("%d",&ch);
      switch(ch)
      {
       case 1:printf("enter the data \n");
              scanf("%d",&d);
              insert(&root,d);
              break;
       case 2:inorder(root);
              printf("\n");
              break;
       case 3:printf("Enter the number to search\t");
              scanf("%d",&val);
              s=search(root,val);
              if(s!=NULL)
                 printf("%d found",val);
              else
                 printf("%d not found",val);
              break;
      }

   }while(ch!=4);
}
