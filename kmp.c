//Write a C program to perform pattern matching using KMP Algorithm. (Print the failure function of a pattern and display whether match is found or not).

#include<stdio.h>
#include<string.h>
#include<conio.h>
#define max_sp_size 100
int failure[max_sp_size];
char string[max_sp_size];
char pat[max_sp_size];
void fail(char *pat)
{
    int n=strlen(pat),j,i;
    failure[0]=-1;
    for(j=1;j<n;j++)
    {
        i=failure[j-1];
        while((pat[j]!=pat[i+1]&&(i>=0)))
        {
            i=failure[i];
        }
        if(pat[j]==pat[i+1])
            failure[j]=i+1;
        else
            failure[j]=-1;
    }
}
int pmatch(char *string,char *pat)
{
    int i=0,j=0;
    int lens=strlen(string),lenp=strlen(pat);
    while( (i<lens) && (j<lenp) )
    {
        if(string[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j==0)
        {
            i++;
        }
        else
        {
            j=failure[j-1]+1;
        }
    }
    return((j==lenp)?(i-lenp):-1);
}
void main()
{
    int i,p=0;
    printf("enter the string \n");
    scanf("%s",&string);
    printf("enter pattern to be found \n");
    scanf("%s",&pat);
    fail(pat);
    printf("The failure values of the string are");
    for(i=0;i<strlen(pat);i++)
        printf(" %d ",failure[i]);
    p=pmatch(string,pat);
    printf("the pattern is found at position %d of string array and starts at the %dth character",p,(p+1));
    getch();
}
