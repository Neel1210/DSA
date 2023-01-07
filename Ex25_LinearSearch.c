#include<stdio.h>

int LinearSrch(int [],int ,int);
int main()
{
    int arr[]={2,1,6,8,4,16,9,11,10,29,27};
    int i=0,x;
    x=LinearSrch(arr,sizeof(arr),29);
    if(x==-1)
    {
        printf("Element not found in the array ...");
        return 0;
    }
    printf("The element is at %d th position ",x);
    return 0;
    
}

int LinearSrch(int arr[],int x,int z)
{
    int i=0;
    for(i=0;i<x;i++)
    {
        if(arr[i]==z)
            return i;
    }
    return -1;
}