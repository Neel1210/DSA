#include<stdio.h>
#include<stdlib.h>

void insert(int [],int ,int);

void main()
{
    int arr[11],i,x;
    for(i=0;i<=10;i++)
    {
        printf("Enter number :-\n");
        scanf("%d",&x);
        insert(arr,i,x);
    }
    for(i=0;i<=10;i++)
    {
        printf("\n%d",arr[i]);

    }
    return;
}

void insert(arr [],int i,int x)
{
    int child , par;
    child=i;
    while(child>1)
    {
        par=child/2;
        if(arr[par]>=x)
        {
            arr[child]=x;
            return;
        }
        arr[child]=arr[par];
        child=par;
    }
    arr[1]=x;
}