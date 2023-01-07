#include<stdio.h>
#include<stdlib.h>

struct cnode
{
    int data;
    struct cnode *next;
};

void append(struct cnode **,int);
void display(struct cnode *);
void delFirst(struct cnode **);
void delLast(struct cnode **);
void insert(struct cnode **,int);
void insert1(struct cnode **,int);

int main()
{
    struct cnode *start=NULL;
    int x, choice;
    for(;;)
    {
        printf("1. Add Element in the list \n");
        printf("2. Display all Element of the list \n");
        printf("3. Delete first node of the list \n");
        printf("4. Delete node  by its position \n");
        printf("5. Delete last node of the list \n");
        printf("6. insert data \n");
        printf("7. Exit \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                for(;;)
                {
                    printf("Enter element to add in the list Or 0 for back \n");
                    scanf("%d",&x);
                    if(x==0)
                        break;
                    append(&start,x);
                }
                break;
            case 2:
                display(start);
                break;
            case 3:
                delFirst(&start);
                break;
            case 4:
                break;
            case 5:
                delLast(&start);
                break;
            case 6:
                printf("Enter element to add in the list Or 0 for back \n");
                    scanf("%d",&x);
                    if(x==0)
                        break;
                    insert1(&start,x);
                    break;
            case 7:
                return 0;
            default:
                printf("Enter valid input\n");
          }
    }
    return 0;
}

void append(struct cnode **ps , int x)
{
    struct cnode *p , *temp ;
    p=(struct cnode *)malloc(sizeof(struct cnode));
    p->data=x;
    if(*ps==NULL)
    {
       *ps=p;
        p->next=p;
        return;
    }
    temp=*ps;
    while(temp->next!=*ps)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->next=*ps;
}

void display(struct cnode *p)
{
    struct cnode *temp;
    if(p==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=p;
    do
    {
       printf("Data is %d\n",temp->data);
       temp=temp->next;
    } while(temp != p);
}

void delFirst(struct cnode **ps)
{
    struct cnode *p , *temp ;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }

    if((*ps)->next==*ps)
    {
        free(*ps);
        *ps=NULL;
        printf("First Node deleted\n");
        return;
    }
    temp=*ps;
    while(temp->next!=*ps)
    {
        temp=temp->next;
    }
    p=*ps;
    *ps=(*ps)->next;
    free(p);
    temp->next=*ps;
}

void delLast(struct cnode **ps)
{
    struct cnode *prev , *temp ;
    if(*ps==NULL)
    {
        printf("List is empty");
        return;
    }
    if((*ps)->next==*ps)
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    while(temp->next!=*ps)
    {
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=*ps;    
}

void insert(struct cnode **ps,int x)
    {
      struct cnode *temp,*prev,*p;
      p=(struct cnode*)malloc(sizeof(struct cnode));
      if(p==NULL)
      {
        printf("Insufficient space");
        return;
      }
      p->data=x;
      if(*ps==NULL)
      {
        *ps=p;
        (*ps)->next=*ps;
        return;
      }
    temp=*ps;
      if((*ps)->data > x)
      {
          p->next=*ps;
          while(temp->next!=*ps)
          {
              temp=temp->next;
          }
          temp->next=p;
          *ps=p;
          return;
      }
    //temp=*ps;
      while(temp->next!=(*ps) && temp->data < x )
      {
        prev=temp;
        temp=temp->next;
      }
    if(temp->next==(*ps))
    {
        temp->next=p;
        p->next=*ps;
    }
    else
    {
        prev->next=p;
        p->next=temp;
    }
}

void insert1(struct cnode**ps,int x)
    {
      struct cnode *temp,*prev,*p;
      p=(struct cnode*)malloc(sizeof(struct cnode));
      if(p==NULL)
      {
        printf("Insufficient space");
        return;
      }
      p->data=x;
      if(*ps==NULL)
      {
        *ps=p;
        (*ps)->next=*ps;
        return;
      }
      temp=*ps;
      if(x<(*ps)->data)
      {
           while(temp!=(*ps))
           {
             temp=temp->next;
         }
         p->next=*ps;
         *ps=p;
         temp->next=*ps;
      }
        temp=*ps;
      while(temp->next!=(*ps)&&temp->data<x)
      {
        prev=temp;
        temp=temp->next;
      }
      if(temp==*ps)
      {
        temp->next=p;
        p->next=*ps;
        }
        else
        {
          prev->next=p;
          p->next=temp;
        }
    }