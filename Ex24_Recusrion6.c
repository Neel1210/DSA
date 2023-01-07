#include<stdio.h>
#include<stdlib.h>
        //Tree traversal by recursion...
struct tree
{
    struct tree *left;
    int data;
    struct tree *right;
};

void append(struct tree ** , int);
void inOrder(struct tree *);

int main()
{   struct tree *start=NULL;
    append(&start,10);
    append(&start,6);
    append(&start,19);
    append(&start,27);
    append(&start,2);
    inOrder(start);
}

void append(struct tree **ps,int x)
{
    struct tree *p,*temp,*prv;
    p=(struct tree *)malloc(sizeof(struct tree));
    p->data=x;
    p->right=p->left=NULL;

    if(*ps==NULL)
    {
        *ps=p;
        return;
    }
    temp=*ps;
    while(temp!=NULL)
    {   prv=temp;
        if(temp->data > x)
            temp=temp->left;
        else
            temp=temp->right;   
    }
    if(prv->data > x)
        prv->left=p;
    else 
        prv->right=p;    
}

void inOrder(struct tree *ps)
{
    if(ps==NULL)
        return;
    inOrder(ps->left);
    printf("%d\n",ps->data);
    inOrder(ps->right);    
}
