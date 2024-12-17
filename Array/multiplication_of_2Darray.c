#include <stdio.h>
int main()
{
    int i,j,k,m,n;
    printf("Enter the order of both the martrix =>\n");
    scanf("%d %d",&m,&n);
    int arr[m][n],arr1[m][n],arr2[m][n];
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter the elements of the 1st matrix =>\n");
            scanf("%d",&arr1[i][j]);
        }
    }


    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter the elements of the 2nd matrix =>\n");
            scanf("%d",&arr2[i][j]);
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            arr[i][j] = 0;
            for(k=0;k<n;k++)
            {
                arr[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
