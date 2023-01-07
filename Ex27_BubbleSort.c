#include<stdio.h>
        //need to debug...
void bubbleSort1(int [],int);
void bubbleSort2(int [],int);

int main()
{   int i;
    int arr[]={9,7,19,12,15,11,6,4,5};
    printf("main1");
    bubbleSort2(arr,9);
    //  printf("\nabhs%d\n",sizeof(arr));

    for(i=0;i<9-1;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}

void bubbleSort1(int arr[],int x)
{    printf("fun1");
    int i,j,temp;
    for(i=0;i<x-1;i++)
    {
        for(j=0;j<x-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void bubbleSort2(int arr[],int x)
{
    int n,j,temp,swap;
    for(n=0;n<x-1;n++)
    {
        swap=0;
        for(j=0;j<x-n-1;j++)
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            swap=1;
        }
        if(!swap)
            break;
    }
}