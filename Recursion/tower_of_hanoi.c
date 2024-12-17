#include <stdio.h>
int toh(int n,char s,char a,char d)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",s,d);
        return 1;
    }
    toh(n-1,s,d,a);
    printf("Move disk %d from %c to %c\n",n,s,d);
    toh(n-1,a,s,d);
}
int main()
{
    int n;
    printf("Enter the no. disk:\n");
    scanf("%d",&n);
    toh(n,'s','a','d');
    return 0;
}
