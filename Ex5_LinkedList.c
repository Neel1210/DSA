#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data ;
    struct node* next ;
};

void append(struct node ** , int);
void insert(struct node **,int);
void display(struct node *);
int countNode(struct node *);
int search(struct node *, int);
void delFirst(struct node **);
void delAny(struct node **,int);
void delLast(struct node **);
void Reverse (struct node *);
int getNth(struct node *, int);

int main()
{
    struct node * start = NULL;
    int choice,x,ans;
    for(;;)
    {
        printf("1. Add new Node\n");
        printf("2. Display all Nodes\n");
        printf("3. Total no of Node\n");
        printf("4. Search Node\n");
        printf("5. Delete First Node\n");
        printf("6. Delete Node by value\n");
        printf("7. Delete Last Node\n");
        printf("8. Display reverse \n");
        printf("9. Insert\n");
        printf("10. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
                for(;;)
                {
                    printf("Enter element for new node & 0 for Back\n");
                    scanf("%d",&x);
                    if(x==0)
                        break;
                    append(&start,x);
                }
        case 2:
                display(start);
                break;
        case 3:
                countNode(start);
                break;
        case 4:
                printf("Enter element to Search in List\n");
                scanf("%d",&x);
                ans=search(start,x);
                if(ans==-1)
                {   printf("Element not found\n");
                    break;
                }
                printf("The searched element present at position no %d\n",ans);
                break;
        case 5:
                delFirst(&start);
                printf("Element deleted\n");
                break;
        case 6:
                printf("Enter element to Delete from the List\n");
                scanf("%d",&x);
                delAny(&start,x);
                printf("Element deleted\n");
                break;
        case 7:
                delLast(&start);
                printf("Element deleted\n");
                break;
        case 8:
                Reverse(start);
                break;
        case 9:
                printf("Enter element for new node & 0 for Back\n");
                scanf("%d",&x);
                if(x==0)
                    break;
                insert(&start,x);
                break;
        case 10:
                return 0;
         default:
                printf("Enter valid input ");
            break;
        }

    }
    return 0;
}

void append(struct node **ps,int x)
{   
    struct node *p , *temp ;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->next=NULL;

    if(*ps==NULL)
    {
        *ps=p;
        return;
    }
    temp = *ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
}

void insert(struct node **ps,int x)
{   
    struct node *p , *temp ;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->next=NULL;

    if(*ps==NULL) // first node insertion 
    {
        *ps=p;
        return;
    }
    if((*ps)->data > x) // if data is smaller then first node .
    {
        p->next=*ps;
        *ps=p;
        return;
    }
    temp = *ps;
    while(temp->next!=NULL)
    {   
        if(x > temp->next->data)
            temp=temp->next;
        else    
            break;
    }
    if(temp->next==NULL) // if data is greater than the last node 
        temp->next=p;
    else
        p->next=temp->next;
        temp->next=p;
}

void display(struct node *p)
{
    if(p==NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(p->next!=NULL)
    {  
        printf("\nelements %d \n",p->data);
        p=p->next;
    }
     printf("\nelements %d \n",p->data);
}

int countNode(struct node *p)
{
    int count = 0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    if(count==0)
        printf("List is empty \n");
    else if(count==1)
        printf("Total Node is %d\n",count);
    else
        printf("Total Node are %d\n",count);
    return count;
}

int search(struct node *p , int x)
{
    int pos = 1;
    
    if(p==NULL)
        return -2;
    while(p!=NULL)
    {
        if(p->data==x)
            return pos;
        pos++;
        p=p->next;
    }
    return -1;
}

void delFirst(struct node **ps)
{
    struct node *temp ;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return ;
    }

    if((*ps)->next == NULL)
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    *ps=(*ps)->next;
    free(temp);
}

void delLast(struct node **ps)
{
    struct node *temp,*prev;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return;
    }
    if((*ps)->next==NULL)
    {   free(*ps);
        *ps=NULL;
        return ;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=NULL;
}

void delAny(struct node **ps,int x)
{   int pos = -1;
    struct node *temp , *prev;

    if(*ps==NULL)
    {
        printf("list is empty\n");
        return;
    }
    temp=*ps;
    if((*ps)->data==x)
    {
        *ps=(*ps)->next;
        free(temp);
        printf("Node found at the beginning of list and deleted\n");
        return;
    }
    while(temp!=NULL && temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Node not found\n");
    }
    else
    {
        prev->next=temp->next;
        free(temp);
        printf("Node found in the mid or last and deleted \n");
    }
}

void reverse (struct node **ps)
{
    int i;
    if(*ps==NULL)
    {
        printf("List is empty");
        return;
    }
    if((*ps)->next==NULL)
    {
        printf("There is only one elements in the list -%d",(*ps)->data);
        return;
    }

    for(i=countNode(*ps);i<=0;i--)
    {
        printf("%d\n",getNth(*ps,i));
    }

}

int getNth(struct node *ps , int n)
{
    struct node *temp= ps;
    for (int i=0; i<n-1 && temp != NULL; i++)
       temp = temp->next;
    return temp->data;
}

void Reverse(struct node *head)
{
    // Base case
    if(head == NULL)
    return;
 
    // print the list after head node
    Reverse(head->next);
 
    // After everything else is printed, print head
    printf("%d\n",head->data);
}