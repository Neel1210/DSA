#include<stdio.h>
        //need to debug...
void mergeSort(int [],int,int);
void merge(int [],int ,int);

int main()
{
    int arr[]={8,3,1,192,26,1,45,3,27,21,19,10,12};
    int x;
    mergeSort(arr,0,13);
    for(x=0;x<13;x++)
    {
        printf("%d\n",arr[x]);
    }
    return  0;
}

void mergeSort(int arr[],int first , int last)
{
    int mid;
    if(first < last)
    {
        mid=(first+last)/2;
        mergeSort(arr,first,mid);
        mergeSort(arr,mid+1,last);
        merge(arr,first,last);
    }
}

void merge(int arr[],int first , int last)
{
    int temp[10];
    int mid,i,i1,i2,i3;

    mid=(first+last)/2;

    i1=0;
    i2=first;
    i3=mid+1;

    while(i2 <= mid && i3 <= last)
    {
        if(arr[i2]<arr[i3])
        {
            temp[i1]=arr[i2];
            i2=i2+1;
        }
        else
        {
            temp[i1]=arr[i3];
            i3=i3+1;
        }
        i1=i1+1;
    }
    if(i2 <= mid)
    {
        while(i2 <= mid)
        {
            temp[i1]=arr[i2];
            i2=i2+1;
            i1=i1+1;
        }
    }
    else
    {
        while(i3 <= last)
        {
            temp[i1]=arr[i3];
            i3=i3+1;
            i1=i1+1;
        }
    }
    i=0;
    while(i<i1)
    {
        arr[first+1]=temp[i];
        i++;
    }
}