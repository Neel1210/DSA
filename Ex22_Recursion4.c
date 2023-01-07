#include<stdio.h>
        //fibonacci series by recursion...
int fibo(int);
int main()
{
    int x;
    printf("Enter nth element for fibonacci series : \n");
    scanf("%d",&x);
    printf("The answer is %d ",fibo(x));
    return 0;
}

int fibo(int n)
{
    if(n<=1)
        return n;
    else    
        return fibo(n-2)+fibo(n-1);
}
