#include <stdio.h>
void lower(int m,int n,int arr[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
                printf("0");
            else
                printf("%d", arr[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

void upper(int m, int n,int arr[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
                printf("0");
            else
                printf("%d", arr[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
int main()
{

    int i, j, m, n;
    printf("Enter the no of rows and columns the martrix =>\n");
    scanf("%d %d", &m, &n);
    int arr[m][n];
    if (m == n)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("Enter the elements of the matrix =>\n");
                scanf("%d", &arr[i][j]);
            }
        }
        printf("\nLower Triangular Matrix is :\n");
        lower(m, n, arr);
        printf("\nUpper Triangular Matrix is :\n");
        upper(m, n, arr);
    }
    else
    {
        printf("The matrix must be square matrix.\n");
    }
    return 0;
}