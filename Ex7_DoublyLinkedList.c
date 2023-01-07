#include<stdio.h>
#include<stdlib.h>
struct Dnode
{
    int data;
    struct Dnode *prev , *next;
};

void append(struct Dnode ** , int);
void display(struct Dnode *);
void delFirst(struct Dnode **);
void delLast(struct Dnode **);
void delLast2(struct Dnode **);
void delAny(struct Dnode **, int );
void delanyy(struct Dnode **, int );


int main()
{
    struct Dnode *start=NULL;
    int x, choice;
    for(;;)
    {
        printf("1. Add Element in the list \n");
        printf("2. Display all Element of the list \n");
        printf("3. Delete first node of the list \n");
        printf("4. Delete node  by its value \n"); //need to correection...
        printf("5. Delete last node of the list \n");
        printf("6. Delete last two node of the list \n");
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
                printf("Enter element to delete from the list\n");
                scanf("%d",&x);
                delanyy(&start,x);
                break;
            case 5:
                delLast(&start);
                break;
            case 6:
                delLast2(&start);
                break;
            case 7:
                return 0;
            default:
                printf("Enter valid input\n");
          }
    }
    return 0;
}

void append(struct Dnode **ps , int x)
{   struct Dnode *p , *temp ;
    p=(struct Dnode *)malloc(sizeof(struct Dnode));
    p->data=x;
    p->next=NULL;

    if(*ps==NULL)
    {
        *ps=p;
        p->prev=NULL;
        return;
    }

    temp = *ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->prev=temp;
}

void display(struct Dnode *p)
{
    if(p==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    while(p!=NULL)
    {
        printf("\n %d",p->data);
        p=p->next;
    }
}

void delFirst(struct Dnode **ps)
{
    struct Dnode *temp;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    if((*ps)->next==NULL)
    {   free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    *ps=temp->next;
    free(temp);
    (*ps)->prev=NULL;
}

void delLast(struct Dnode **ps)
{
    struct Dnode *temp;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    if((*ps)->next==NULL)
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}

void delLast2(struct Dnode **ps)
{
    struct Dnode *temp;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next==NULL)
    {
        printf("Deletion not possible as list has only 1 node \n");
        return;
    }
    if((*ps)->next->next==NULL)
    {
        free((*ps)->next);
        free(*ps);
        *ps=NULL;
        printf("There were only two node and they have been deleted\n");
        return;
    }
    temp=*ps;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->prev->next=NULL;
    free(temp);
}

void delAny(struct Dnode **ps , int x)
{
     struct Dnode *temp;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return ;
    }
    if((*ps)->next==NULL)
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    while(temp!=NULL && temp->data==x)
    {
        temp=temp->next;
    }
    if(temp->next==NULL && temp->data!=x)
    {
            printf("Element not found\n");
            return;
    }
    else if(temp->next==NULL && temp->data==x)
    {
        temp->prev->next=NULL;
        printf("Element deleted and found in the last \n");
        free(temp);
        return;
    }
    temp->prev->next=temp->next;
    printf("Element deleted and found in the mid \n");
    free(temp);   
}

void delanyy(struct Dnode **ps,int x)
{   
    struct Dnode *pre , *temp;
    if((*ps)==NULL)
    {
      printf("list is empty");
      return ;
    } 
        temp=*ps;
      if((*ps)->data==x)
    {
        *ps=(*ps)->next;
        free(temp);
        return;
    }
    while(temp!=NULL&&temp->data!=x)
    {
      pre=temp;
      temp=temp->next;
    }
    if(temp==NULL)
    {
      printf("node not found");
      return;
    }
    else if(temp->next==NULL)
    {
        pre->next=temp->next;
        free(temp);
        return;
    }
    else
    pre->next=temp->next;
    temp->next->prev=pre;
    free(temp);
    return;

}


// void delany(struct doubly **ps,int x)
// {
//     struct doubly *pre,*temp;
//     if((*ps)==NULL)
//     {
//       printf("list is empty");
//       return ;
//     } 
//         temp=*ps;
//       if((*ps)->data==x)
//     {
//         *ps=(*ps)->next;
//         free(temp);
//         return;
//     }
//     while(temp!=NULL&&temp->data!=x)
//     {
//       pre=temp;
//       temp=temp->next;
//     }
//     if(temp==NULL)
//     {
//       printf("node not found");
//       return;
//     }
//     else if(temp->next==NULL)
//     {
//         pre->next=temp->next;
//         free(temp);
//         return;
//     }
//     else
//     pre->next=temp->next;
//     temp->next->prev=pre;
//     free(temp);
//     return;
// }