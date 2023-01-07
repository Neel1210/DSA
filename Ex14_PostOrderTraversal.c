#include<stdio.h>
#include<stdlib.h>

struct Bst
{
    struct Bst *left;
    int data , flag ;
    struct Bst *right;
};

struct stack 
{
    int tos;
    struct Bst *arr[10];
};

void push(struct stack *,struct Bst *);
struct Bst* pop(struct stack *);
void append(struct Bst **,int );
int search(struct Bst * ,int );
void postOrder(struct Bst *);
void postOrder1(struct Bst *);

int main()
{
    struct Bst *root=NULL;
    int i;
    append(&root,10);
    append(&root,9);
    append(&root,12);
    append(&root,7);
    // i=search(root,12);
    // if(i==1)
    //     printf("Data is here\n");
    // else    
    //     printf("Data not found\n");
    postOrder(root);
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

void postOrder(struct Bst *p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("Empty Tree");
        return;
    }
    s.tos=-1;
    push_node:
        while(p!=NULL)
        {
            push(&s,p);
            if(p->right!=NULL)
                push(&s,p->right);
            p=p->left;
        }
        p=pop(&s);
        while(p!=NULL)
        {
            if(p->flag==1)
                printf("%d\n",p->data);
            else    
            {
                p->flag=1;
                goto push_node;
            }
            p=pop(&s);
        }
}

void postOrder1(struct Bst *p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("Empty Tree \n");
        return;
    }
    s.tos=-1;
    push_node:
        while(p!=NULL)
        {
            p->flag=1;
            push(&s,p);
            if(p->right!=NULL)
            {
                p->right->flag=-1;
                push(&s,p->right);
            }
            p=p->left;
        }
        while(p!=NULL)
        {
            if(p->flag==1)
                printf("\n%d",p->data);
            else
            {
                goto push_node;
            }
            p=pop(&s);
        }
}