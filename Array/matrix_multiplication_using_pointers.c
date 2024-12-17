#include <stdio.h>
#include <stdlib.h>
void MatrixMultiplication(int **arr_1, int **arr_2, int r_1, int c_1, int r_2, int c_2){
    int **res=(int **)malloc(r_1*sizeof(int *));
    for (int i=0; i<r_1; i++){
        res[i]=(int *)malloc(c_2*sizeof(int));
    }
    if (c_1==r_2){
        for (int i=0; i<r_1; i++){
            for (int j=0; j<c_2; j++){
                res[i][j]=0;
                for (int k=0; k<r_2; k++){
                    res[i][j]+=(*(*(arr_1+i)+k))*((*(*(arr_2+k)+j)));
                }
                printf("%d ",res[i][j]);
            }
            printf("\n");
        }
    }
}
int main(){
    int r_1, c_1, r_2, c_2;
    printf("Enter the number of rows of the first matrix: ");
    scanf("%d",&r_1);
    printf("Enter the number of columns of the first matrix: ");
    scanf("%d",&c_1);
    printf("Enter the number of rows of the second matrix: ");
    scanf("%d",&r_2);
    printf("Enter the number of columns of the second matrix: ");
    scanf("%d",&c_2);
    int **arr_1=(int **)malloc(r_1*sizeof(int *));
    for (int i=0; i<r_1; i++){
        arr_1[i]=(int *)malloc(c_1*sizeof(int));
    }
    int **arr_2=(int **)malloc(r_2*sizeof(int *));
    for (int i=0; i<r_2; i++){
        arr_2[i]=(int *)malloc(c_2*sizeof(int));
    }
    printf("Enter the elements of the first matrix:\n");
    for (int i=0; i<r_1; i++){
        for (int j=0; j<c_1; j++){
            scanf("%d",&arr_1[i][j]);
        }
    }
    printf("Enter the elements of the second matrix:\n");
    for (int i=0; i<r_2; i++){
        for (int j=0; j<c_2; j++){
            scanf("%d",&arr_2[i][j]);
        }
    }
    MatrixMultiplication(arr_1,arr_2,r_1,c_1,r_2,c_2);
    return 0;
}
