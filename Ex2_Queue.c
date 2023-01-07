#include<stdio.h>

struct Queue
{
    int arr[5] ;
    int rear ;
    int front;
};

void insert(struct Queue * , int );
int remove1(struct Queue *);

int main()
{
    struct Queue q;
    q.front=0;
    q.rear=-1;
    int i ,x;
    for(i=0;i<6;i++)
    {
        printf("Enter the only +ve Element to push in queue\n");
        scanf("%d",&x);
        insert(&q,x);
    }
    
    for(i=0;i<6;i++)
    {
        x=remove1(&q);
        if(x!=-1)
            printf("Removed element from the Queue = %d\n",x);

    }
    return 0;
}

void insert(struct Queue *p,int x)
{
    if(p->rear==4)
    {
        printf("\tQueue overFlow\n");
        return ;
    }
    p->rear = p->rear +1;
    p->arr[p->rear]=x;
}

int remove1(struct Queue *p)
{   int x;
    if(p->front>p->rear)
    {
        printf("\tQueue underFlow\n");
        return -1;
    }
    x = p->arr[p->front];
     p->front = p->front+1;
    return x;
}
