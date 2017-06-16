//Write a C program to convert a given infix expression to a postfix expression using a stack.

#include<stdio.h>
#include<conio.h>
typedef enum{lp,rp,plus,minus,times,divide,mod,eos,operand} precedence;
int top=0;
char stack[10];
int isp[]={0,3,1,1,2,2,2,0,0};
int icp[]={100,3,1,1,2,2,2,0,0};
char expr[100];
void printt(precedence token);
precedence get(char *sym,int *n)
{
  *sym=expr[(*n)++];
   switch(*sym)
   {
       case '(': return lp;break;
       case ')':return rp;break;
       case '+': return plus;break;
       case '-': return minus;break;
       case '*': return times;break;
       case '/': return divide;break;
       case '%': return mod;break;
       case '\0': return eos;break;
       default : return operand;
   }
}
precedence pop()
{
  return stack[top--];
}
void push(precedence item)
{
  stack[++top]=item;
}
void post()
{
  char sym;
  stack[0]=eos;
  precedence token;
  int n=0;
  for(token=get(&sym,&n);token!=eos;token=get(&sym,&n))
  {
      if (token==operand)
        printf("%c",sym);
      else if(token==rp)
        {
             while(stack[top]!=lp)
                printt(pop());
             pop();
         }
      else
        {
             while((icp[token])<=(isp[stack[top]]))
             printt(pop());
             push(token);
      }
  }
   while((token=pop())!=eos)
      printt(token);
}
void printt(precedence token)
{
   switch(token)
   {
      case plus: printf("+");break;
      case minus: printf("-");break;
      case divide: printf("/");break;
      case times: printf("*");break;
      case mod: printf("%");break;
   }
}
int main()
{
  printf("enter the infix expression");
  scanf("%s",expr);
  post();
  getch();
  return 0;
}
