#include<stdio.h>
#include<ctype.h>
void push(char stack[100],char x,int *top)
{
    stack[++(*top)] = x;
}
 
char pop(char stack[100],int *top)
{
    if(*top == -1)
        return -1;
    else
        return stack[(*top)--];
}
 
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}
 

void main()
{
    char exp[100];
    char *e, x;
    char stack[100];
    int top = -1;
    printf("Enter the expression :: ");
    scanf("%s",exp);
    e = exp;
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c",*e);
        else if(*e == '(')
            push(stack,*e,&top);
        else if(*e == ')')
        {
            while((x = pop(stack,&top)) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c",pop(stack,&top));
            push(stack,*e,&top);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c",pop(stack,&top));
    }

}




