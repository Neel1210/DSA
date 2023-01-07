#include<stdio.h>
        //need to debug...
int BinarySrch(int [] , int , int );

int main()
{   int x;
    int arr[]={1,2,3,4,5,6,8,10,13,15,17};
    x=BinarySrch(arr,sizeof(arr),13);
    if(x==-1)
    {
        printf("Element not found ");
        return 0;
    }
    printf("Element is at %d th position ...",x);
    return 0;
}
int BinarySrch(int arr[],int x,int z)
{
    int i=0,h=x-1,m;

    while(i<=h)
    {
        m=(i+h)/2;
        if(arr[m]==z)
            return m;
        if(z > arr[m])
            i=m+1;
        else
            h=m-1;
    }
    return -1;
}