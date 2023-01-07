#include<stdio.h>
#include<stdlib.h>

struct Bst
{
    struct Bst *left;
    int data;
    struct Bst *right;
};

struct stack
{
    struct Bst *arr[10];
    int tos;
};

void append(struct Bst **,int);
void del_node1(struct Bst **,int);
int search(struct Bst *,int ,struct Bst **,struct Bst **);

int main()
{
    struct Bst *root=NULL;
    append(&root,10);
    append(&root,12);
    append(&root,19);
    append(&root,17);
    del_node1(&root,19);
    printf("%d",root->right->data);
    return 0;
}

void append(struct Bst **pr,int x)
{
    struct Bst *p,*temp,*prev;
    p=(struct Bst *)malloc(sizeof(struct Bst));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    if(*pr==NULL)
    {
        *pr=p;
        return;
    }
    temp=*pr;
    while(temp!=NULL)
    {   prev=temp;
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

int search(struct Bst *p ,int x ,struct Bst **pchild ,struct Bst **ppar)
{
    struct Bst *prev = NULL;
    while(p!=NULL)
    {
        if(p->data==x)
        {
            *pchild=p;
            *ppar=prev;
            return 1;
        }
        prev=p;
        if(p->data > x)
            p=p->left;
        else    
            p=p->right;
    }
    return 0;
}

void del_node1(struct Bst **pr , int x)
{
    struct Bst *child , *par , *q;
    int result;
    if(*pr==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    result=search(*pr,x,&child,&par);
    if(result==0)
    {
        printf("Node not found \n");
        return;
    }
    if(child->left!=NULL && child->right!=NULL)
    {
        q=child->right;
        par=child;
        while(q->left!=NULL)
        {
            par = q;
            q=q->left;
        }
        child->data=q->data;
        child=q;
    }
    if(child->left==NULL && child->right==NULL)
    {
        if(par==NULL)
            *pr=NULL;
        else if(child==par->left)
            par->left=NULL;
        else
            par->right=NULL;
        free(child);
    }
    else if(child->right==NULL &&child->left!=NULL)
    {
        if(par==NULL)
            *pr=child->left;
        else if(child==par->left)
            par->left=child->left;
        else    
            par->right=child->left;
        free(child);
    }
    else if(child->right != NULL && child->left==NULL)
    {
        if(par==NULL)
            *pr=child->right;
        if(child==par->left)
            par->left=child->right;
        else   
            par->right=child->right;
    }   free(child);
}