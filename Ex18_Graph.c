#include<stdio.h>
#include<stdlib.h>
struct edge
{
    char data;
    struct edge *next;
};
struct node
{
    char data;
    struct node *next;
    struct node *enext;
};
void addVertex(struct node **,char);
void insertEdge(struct node *,char,char);
struct node* findVertex(struct node*,char);
void display(struct node *);
void removeVertex(struct node **,char);
void removeEdge(struct node *,char,char);

int main()
{
    struct node *start=NULL;
    char ch1,ch2;
    int choice;
    do
    {
        printf("1. Add vertex \n");
        printf("2. Insert edge \n");
        printf("3. Remove vertex \n");
        printf("4. Remove Edge \n");
        printf("5. Display \n");
        printf("6. Quit \n");
        scanf("%d",&choice);
        switch(choice)
        {   
            fflush(stdin);
            case 1:
                printf("Enter the vertex : ");
                scanf("%c\n",&ch1);
                addVertex(&start,ch1);
                break;
            case 2:
                printf("\nEnter src and dest vertices : ");
                scanf("%c %c",&ch1,&ch2);
                insertEdge(start,ch1,ch2);
                break;
            case 3:
                printf("\nEnter Vertex to remove : ");
                scanf("%c",&ch1);
                // removeVertex(&start,ch1);
                break;
            case 4:
                printf("\nEnter src and dest vertices : ");
                scanf("%c %c",&ch1,&ch2);
                // removeEdge(start,ch1,ch2);
                break;
            case 5:
                display(start);
                break;
            case 6:
                return 0;
            default:
                printf("\nWrong Choice . Try Again... ");
        }
    } while (1);
    return 0;
}

void addVertex(struct node **ps,char ch)
{
    struct node *p,*temp;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=ch;
    p->next=p->enext=NULL;

    if(*ps==NULL)
    {
        *ps=p;
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
}

struct node* findVertex(struct node *p , char ch)
{
    while(p!=NULL)
    {
        if(p->data==ch)
            break;
        p=p->next;
    }
    return p;
}

void insertEdge (struct node *p ,char s, char d)
{
    struct node *temp;
    struct edge *q,*r;
    if(p==NULL)
    {
        printf("\nGraph is empty");
        return;
    }

    temp=findVertex(p,s);
    if(temp==NULL)
    {
        printf("\nSource vertex not found ");
        return;
    }
    if(findVertex(p,d)==NULL)
    {
        printf("\nDest vertex not found ");
        return;
    }
    q=(struct edge *)malloc(sizeof(struct edge));
    q->next=NULL;
    q->data=d;

    if(temp->enext==NULL)
    {
        temp->enext=q;
        return;
    }
    r=temp->enext;
    while(r->next!=NULL)
    {
        r=r->next;
    }
    r->next=q;
    printf("\nEdge SuccessFully added !");
}

void display(struct node *p)
{
    struct edge *q;
    if(p==NULL)
    {
        printf("\nGraph is empty");
        return;
    }
    while(p!=NULL)
    {
        printf("\nVertex : %c ",p->data);
        printf("\nAdj Vertices : ");
        q=p->enext;
        while(q!=NULL)
        {
            printf("\n %c ",q->data);
            q=q->next;
        }
        p=p->next;
    }
}