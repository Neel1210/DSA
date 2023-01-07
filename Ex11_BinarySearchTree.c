#include<stdio.h>
#include<stdlib.h>

struct Bst
{
    struct Bst *left;
    int data;
    struct Bst *right; 
};

void append(struct Bst **,int );
int search(struct Bst * ,int );

int main()
{
    struct Bst *root=NULL;
    int i;
    append(&root,10);
    append(&root,9);
    append(&root,12);
    append(&root,10);
    i=search(root,12);
    if(i==1)
        printf("Data is here\n");
    else    
        printf("Data not found\n");
    return 0;
}

void append(struct Bst **pr , int x)
{
    struct Bst *p,*temp,*prev;
    p=(struct Bst *)malloc(sizeof(struct Bst));
    p->data=x;
    p->right=p->left=NULL;

    if(*pr==NULL)
    {
        *pr=p;
        return;
    }
    temp=*pr;
    while(temp!=NULL)
    {
        prev=temp;
        if(temp->data > x)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if(prev->data > x)
        prev->left=p;
    else
        prev->right=p;
}

int search(struct Bst *p ,int x)
{
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    while(p!=NULL)
    {
        if(p->data==x)
            return 1;
        if(p->data > x)
            p=p->left;
        else
            p=p->right;
    }
    return 0;
}