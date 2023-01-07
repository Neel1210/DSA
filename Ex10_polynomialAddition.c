#include<stdio.h>
#include<stdlib.h>

struct poly
{
    int c;
    int e;
    struct poly *next;
};

void append(struct poly **,int,int);
void display(struct poly *);
void add(struct poly * , struct poly * ,struct poly **);

int main()
{
    struct poly *first , *second , *third ;
    first=second=third=NULL;

    append(&first,4,1);
    append(&first,2,3);
    append(&first,5,4);
    append(&first,3,6);

    append(&second,6,2);
    append(&second,3,3);
    append(&second,8,4);
    append(&second,-2,6);
    add(first,second,&third);
    display(first);
    printf("\n");
    display(second);
    printf("\nAddition is here :-");
    display(third);

    return 0;
}

void append(struct poly **ps,int x,int y)
{
    struct poly *p,*temp;
    p=(struct poly *)malloc(sizeof(struct poly));
    p->c=x;
    p->e=y;
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
    return;
}

void display(struct poly *ps)
{   struct poly *p;
    if(ps==NULL)
    {
        printf("Polynomial expression is empty\n");
        return ;
    }
    p=ps;
    while (p->next!=NULL)
    {
        printf("%d^%d\n",p->c,p->e);
        p=p->next;
    }
    printf("%d^%d\n",p->c,p->e);
    return;
}

void add(struct poly *f,struct poly *s,struct poly **pt)
{
    struct poly *q;
    if(f==NULL && s==NULL)
    {
        printf("Addition not possible\n");
        return;
    }
    while(f!=NULL && s!=NULL)
    {   if(f->e < s->e)
        {   append(pt,f->c,f->e);
            f=f->next;
        }
        else if(s->e < f->e)
        {
            append(pt,s->c,s->e);
            s=s->next;
        }
        else{
            append(pt,f->c+s->c,f->e);
            f=f->next;
            s=s->next;
        }
    }
}