#include<stdio.h>
#include<stdlib.h>
struct node
{   
    int data;
    struct node *next;
};

int main()
{
    struct node *start=NULL;
    //First Node Creation
    start=(struct node*)malloc(sizeof(struct node));
    start->data=12;
    start->next=NULL;

    //Second Node Creation 
    start->next=(struct node *)malloc(sizeof(struct node));
    start->next->data=10;
    start->next->next=NULL;

    //printing data 
    printf("Element is %d\n",start->data);
    printf("Element is %d",start->next->data);
    return 0;
}