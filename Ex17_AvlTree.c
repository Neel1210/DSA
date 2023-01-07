#include<stdio.h>
#include<stdlib.h>
        //Error Occoured...

struct avl
{
    struct avl *left;
    int data;
    struct avl *right;
    int height;
}*root=NULL;

struct avl* append(struct avl* , int);
int nodeHeight(struct avl*);
int balanceFactor(struct avl*);
struct avl* LLRotation(struct avl *);
struct avl* LRRotation(struct avl *);
struct avl* RLRotation(struct avl *);
struct avl* RRRotation(struct avl *);

void main()
{
    root=append(root,10);
    append(root,5);
    append(root,12);
    append(root,10);
    append(root,27);
    append(root,24);
    return;
}

struct avl* append(struct avl *pr,int x)
{
    struct avl *p=NULL;
    if(pr==NULL)
    {
        p=(struct avl*)malloc(sizeof(struct avl));
        p->data=x;
        p->left=p->right=NULL;
        return p;
    }
    if(x > pr->data)
        pr->right=append(pr->right,x);
    else
        pr->left=append(pr->left,x);
    pr->height=nodeHeight(pr);
    if(balanceFactor(pr)==2 && balanceFactor(pr->left)==1)
            return LLRotation(pr);
    else if(balanceFactor(pr)==2 && balanceFactor(pr->left)==-1)
            return LRRotation(pr);
    return pr;
}

int nodeHeight(struct avl *p)
{
    int hl , hr;
    hl= p && p->left?p->left->height:0;
    hr= p && p->right?p->right->height:0;
    return hl > hr ?hl+1:hr+1;
}

int balanceFactor(struct avl *p)
{
    int hl , hr;
    hl=p && p->left?p->left->height:0;
    hr=p && p->right?p->right->height:0;
    return hl-hr;
}

struct avl* LLRotation(struct avl *p)
{
    struct avl *pl=p->left;
    struct avl *plr=p->right;
    pl->right=p;
    p->left=plr;
    p->height=nodeHeight(p);
    pl->height=nodeHeight(pl);
    if(root == p)
        root=pl;
    return pl;
}
