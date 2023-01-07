#include<stdio.h>

void insert(int [],int,int);
int del1(int[],int);

int main()
{
    int arr[8];
    int i,x;

    for(i=1;i<=7;i++)
    {
        printf("Enter no :-\n");
        scanf("%d",&arr[i]);
        insert(arr,i,x);
    }

    printf("Heap is :-\n");

    for(i=0;i<=7;i++)
    {
        printf("%d",arr[i]);
    }

    for(i=7;i>=1;i--)
    {
        x=del1(arr,i);
        arr[i]=x;
    }
    printf("\nSorted array is :-");
    for(i=0;i<=7;i++)
    {
        printf("\n%d",arr[i]);
    }
    return 0;
}

void insert(int arr[],int child,int n)
{
    int par;
    while(child > 1)
    {
        par=child/2;
        if(arr[par]>n)
        {
            arr[child]=n;
            return;
        }
        arr[child]=arr[par];
        child=par;
    }
    arr[1]=n;
}

int del1(int arr[],int n)
{
    int temp;
    int x=arr[1];
    arr[1]=arr[n];
    n--;
    int i=1,j=2*i;
    while(j<n)
    {
        if(j<n)
        {
            if(arr[j+1]>arr[j])
                j=j+1;
        }
        if(arr[i]<arr[j])
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i=j;
            j=2*j;
        }
        else    
            break ;
    }
    return x;
}