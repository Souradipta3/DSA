#include <stdio.h>
int main()
{
    int i,j,m,n;
    printf("Enter the order of both the matrix =>");
    scanf("%d %d",&m,&n);
    int arr[m][n],arr1[m][n],arr2[m][n];

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter the elements of the 1st matrix =>");
            scanf("%d",&arr1[i][j]);
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter the elements of the 2nd matrix =>");
            scanf("%d",&arr2[i][j]);
        }
    }

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            arr[i][j]=arr1[i][j]-arr2[i][j];
            printf("%d\t",arr[i][j]);

            //arr[i][j]1+=arr2[i][j]; //Directly performing the operation by using addition operator without storing the operation result in any other variable. 
            //printf("%d",arr1[i][j]); //Printing one of the variable which is the updated value result of the operation 

            //printf("%d",arr1[i][j]+arr2[i][j]); //Without storing the operation in any variable, directly performing the operation and printing it.  
        }
        printf("\n");
    }
    return 0;
}
