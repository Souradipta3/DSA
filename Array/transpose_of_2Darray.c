#include <stdio.h>
int main()
{
    int i,j,m,n;
    printf("Enter the order of both the matrix =>\n");
    scanf("%d",&m);
    scanf("%d",&n);
    int arr[m][n];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter the elements of the matrix =>\n");
            scanf("%d",&arr[i][j]);
        }
    }

    printf("The given matrix is =>\n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    printf("The output matrix will be =>\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d\t",arr[j][i]);
        }
        printf("\n");
    }

    return 0;
}
