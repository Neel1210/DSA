#include<stdio.h>
        //sum of natural numbers by recursion
int sum(int);

int main()
{   int x,j;
    printf("Enter nth place for natural number :-");
    scanf("%d",&x);
    j=sum(x);
    printf("\nSum of Natural no is %d ",j);
    return 0;
}

int sum(int x)
{
    if(x==1)
        return x;
    else
        return sum(x-1)+x;
}