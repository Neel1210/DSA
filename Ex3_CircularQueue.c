#include<stdio.h>

struct Cqueue
{
    int arr[5];
    int front , rear;
};

void insert(struct Cqueue * , int);
int remove1(struct Cqueue *);

int main()
{
    struct Cqueue q;
    q.front=q.rear=-1;
    int i,x;

    for(i=0;i<6;i++)
    {
        printf("Enter only +ve element in Cqueue \n");
        scanf("%d",&x);
        insert(&q,x);
    }

    for(i=0;i<6;i++)
    {
        x=remove1(&q);
        if(x!=0)
            printf("\nRemoved element is %d ",x);
    }
    return 0;
}

void insert(struct Cqueue *p , int x)
{
    if((p->rear==4 && p->front==0) || (p->rear+1==p->front)) //Or in single line if((p->rear+1)%5==p->front)
    {
        printf("Queue OverFlow");
        return;
    }

    if(p->rear==4)
        p->rear=0;
    else    
        p->rear=p->rear+1;

    p->arr[p->rear]=x;
    if(p->front==-1)
        p->front=0;

}

int remove1(struct Cqueue *p)
{   int x;
    if(p->front==-1)
    {
        printf("Queue UnderFlow");
        return 0;
    }
    x=p->arr[p->front];
   
    if(p->front==p->rear)
        p->front=p->rear=-1;
   
    else if(p->front==4)
            p->front=0;
    else
        p->front=p->front+1;
    return x;
}

