#include<stdio.h>
#include<stdlib.h>
        //linked list traversal by recursion...
struct node
{
    int data;
    struct node *next;
};

void display(struct node *);
void append(struct node ** , int);

int main()
{   struct node *start=NULL;
    append(&start,10);
    append(&start,20);
    append(&start,30);
    append(&start,40);

    display(start);
    return 0;
}

void append(struct node **ps,int x)
{
    struct node *p,*temp;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=NULL;

    if(*ps==NULL)
    {
        *ps=p;
        return;
    }
    temp=*ps;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
}

void display(struct node *p)
{
    if(p==NULL)
    {
        printf("List is empty ");
        return;
    }
    printf("%d\n",p->data);
    display(p->next);
}