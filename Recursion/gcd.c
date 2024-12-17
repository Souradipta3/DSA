#include <stdio.h>
int gcd(int num1, int num2)
{
    if(num1 % num2==0)
    {
        return num2;
    }
    else
    {
        return(num2,num1%num2);
    }
}
int main()
{
    int num1,num2;
    printf("Enter two numbers:");
    scanf("%d %d",&num1,&num2);
    printf("The gcd of %d and %d is %d.",num1,num2,gcd(num1,num2));
    return 0;
}
