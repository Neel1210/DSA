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

void push(struct stack *,struct Bst *);
struct Bst* pop(struct stack *);
void append(struct Bst **,int );
int search(struct Bst * ,int );
void preOrder(struct Bst*);
// void inOrder(struct Bst *p);

int main()
{
    struct Bst *root=NULL;
    int i;
    append(&root,10);
    append(&root,9);
    append(&root,12);
    append(&root,7);
    i=search(root,12);
    if(i==1)
        printf("Data is here\n");
    else    
        printf("Data not found\n");
    preOrder(root);
    inOrder(root);
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

void push(struct stack *p,struct Bst *right)
{
    if(p->tos==9)
    {
        printf("Stack OverFlow\n");
        return ;
    }
    p->tos++;
    p->arr[p->tos]=right;
}

struct Bst * pop(struct stack *p)
{
    struct Bst *temp;
    if(p->tos==-1)
    {
        printf("Stack UnderFlow\n");
        return NULL;
    }
    temp=p->arr[p->tos];
    p->tos--;
    return temp;
}
void preOrder(struct Bst *p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    s.tos=-1;
    push(&s,p);
    while(s.tos!=-1)
    {
        p=pop(&s);
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            if(p->right!=NULL)
                push(&s,p->right);
            p=p->left;
        }
    }
}

// void inOrder(struct Bst *p)
// {
//     if(p==NULL)
//         return;
//     inOrder(p->left);
//     printf("%d\n",p->data);
//     inOrder(p->right);
// }