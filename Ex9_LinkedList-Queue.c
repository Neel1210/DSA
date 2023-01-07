#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

void insert(struct Queue **,struct Queue **,int);
int rem1(struct Queue **,struct Queue **);

int main()
{
    struct Queue *front , *rear ;
    int i=0,x,j;
    char ch;
    for(;;)
    {
        printf("1. For insert element to add to Queue only (+ve values) :-\n");
        printf("2. For Remove the element from the Queue\n");
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
                    insert(&front,&rear,j);
                }
                break;
                
            case 2:
                for(;;)
                {    if(ch=='n')
                        break;
                    fflush(stdin);   
                    x=rem1(&front,&rear);
                    if(x==-1)
                    {
                       break;
                    }
                    printf("Removed element is %d\n",x);
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
}

void insert(struct Queue **pf,struct Queue **pr,int x)
{
    struct Queue *p;
    p=(struct Queue *)malloc(sizeof(struct Queue));
    if(p==NULL)
    {
        printf("Queue OverFlow\n");
        return;
    }
    p->data=x;
    p->next=NULL;
    
    if(*pf==NULL)
        *pf=p;
    else
        (*pr)->next=p;
    *pr=p;
}

int rem1(struct Queue **pf,struct Queue **pr)
{
    struct Queue *temp;
    int x;
    if(*pf==NULL)
    {
        printf("Queue UnderFlow\n");
        return -1;
    }
    temp=*pf;
    x=temp->data;
    if(*pf==*pr)
        *pr=NULL;
    *pf=temp->next;
    free(temp);
    return x;    
}