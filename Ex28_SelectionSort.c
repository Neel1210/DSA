#include<stdio.h>

void selectionSort(int[],int);

int main()
{   int i;
    int arr[]={9,8,7,6,5,4,3,2,1};
    selectionSort(arr,9);
    for(i=0;i<9;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}

void selectionSort(int arr[],int n)
{
    int x,j,temp,min;
    for(x=0;x<n-1;x++)
    {
        min=x;
        for(j=x+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                    min=j;
        }
        if(x!=min)
        {
            temp=arr[x];
            arr[x]=arr[min];
            arr[min]=temp;
        }
    }
}