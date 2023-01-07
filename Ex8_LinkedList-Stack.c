#include<stdio.h>
#include<stdlib.h>

struct stack 
{
    int data;
    struct stack *next;
};

void push(struct stack **,int);
int pop(struct stack **);

int main()
{
    struct stack s;
    int i=0,x,j;
    char ch;
    for(;;)
    {
        printf("1. For push element to add to stack only (+ve values) :-\n");
        printf("2. For pop the element from the stack\n");
        printf("3. Exit\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                for(;;)
                {
                    printf("Enter element to add Or '-1' for back :-\n");
                    scanf("%d",&j);
                    if(j==-1)
                    {
                        break;
                    }
                    push(&s,j);
                }
                break;
                
            case 2:
                for(;;)
                {    if(ch=='n')
                        break;
                    fflush(stdin);   
                    x=pop(&s);
                    if(x==-1)
                    {
                        printf("Stack UnderFLow\n");
                        break;
                    }
                    printf("poped element %d\n",x);
                    printf("Enter 'y' for pop again OR 'n' for Back  :- ");
                    scanf("%ch",&ch);
                }
                break;
            case 3:
                return 0;

            default:
                printf("Enter valid option:-\n");   
                break;    
        }
    }
    return 0;
}

void push(struct stack **ptos,int x)
{
    struct stack *p;
    p=(struct stack *)malloc(sizeof(struct stack));
    if(p==NULL)
    {
        printf("Stack OverFlow\n");
        return;
    }
    p->data=x;
    p->next=*ptos;
    *ptos=p;
}

int pop(struct stack **ptos)
{
    struct stack *temp;
    int x;
    if(*ptos==NULL)
    {
        printf("Stack underFlow\n");
        return -1;
    }
    x=(*ptos)->data;
    temp=*ptos;
    *ptos=(*ptos)->next;
    free(temp);
    return x;
}