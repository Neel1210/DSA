#include<stdio.h>

void insertionSort(int [],int);

int main()
{
    int i ;
    int arr[]={9,8,7,6,5,4,3,2,1,99,88,77,66,55,44,33};
    insertionSort(arr,16);
    for(i=0;i<16;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}

void insertionSort(int arr[],int x)
{
    int i,j,temp;
    for(i=0;i<x-1;i++)
    {
        for(j=i+1;j>0;j--)
        {
            if(arr[j]<arr[j-1])
            {
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
            else
                break;
        }
    }
}