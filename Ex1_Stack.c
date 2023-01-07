#include<stdio.h>

struct stack
{
    int arr[5] ;
    int tos;
};

void push(struct stack * , int);
int pop(struct stack *);

int main()
{
    struct stack s;
    s.tos=-1;
    int i,x;
    for(i = 0 ; i < 5 ; i++)
    {
            printf("Enter an element to put in a staack \n"); //don't give a -ve value in input 
            scanf("%d",&x);
            push(&s,x);
    }

    for(i=0;i<5;i++)
    {   
        x=pop(&s);
        printf("The element is %d\n",x);
    }
    return 0;
}

void push(struct stack *p , int x)
{
    if(p->tos == 4)
    {
        printf("Stack is overFlow");
        return ;
    }
    p->tos = p->tos + 1;
    p->arr[p->tos]=x;
}

int pop(struct stack *p)
{   int x;
    if(p->tos == -1)
    {
        printf("stack underFlow");
        return -1;
    }
    x=p->arr[p->tos];
    p->tos = p->tos -1 ;
    return x;
}