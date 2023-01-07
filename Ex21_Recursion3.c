#include<stdio.h>
        //Power by recursion...
int power(int,int);

int main()
{
    int x,z,y;
    printf("Enter number and then it's power : \n");
    scanf("%d" "%d",&x,&y);
    printf("The answer is %d ",power(x,y));
    return 0;
}

int power(int x,int y)
{
    if(y==0)
        return 1;
    else if(y==1)
        return x;
    else
        return power(x,y-1)*x;
}