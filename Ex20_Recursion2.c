#include<stdio.h>

        //factorial by recursion

int factorial(int);

void main()
{
    int x;
    // int n;
    printf("Enter number for factorial\n");
    scanf("%d",&x);
    // n=factorial(x);
    printf("The factorial is %d ",factorial(x));

}

int factorial(int x)
{
    if(x<=1)
        return 1;
    else
        return factorial(x-1)*x;
}