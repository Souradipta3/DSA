#include <stdio.h>
int main()
{
    int i,j,m,n;
    printf("Enter the order of the matrix =>");
    scanf("%d %d",&m,&n);
    int arr[m][n]; 

    for(i=0;i<m;i++)
    {
        for (j=0;j<n; j++)
        {
            printf("Enter the elements of the matrix =>");
            scanf("%d",&arr[i][j]);
        }
    }

    for(i=0;i<m;i++)
    {
        for (j=0;j<n; j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
