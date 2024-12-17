#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    if (n == 1)
    {
        return;
    }
    int temp;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            count++;
        }
    if (count == 0)
        return;
    bubbleSort(arr, n - 1);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element of the array:", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Unorted array : \n");
    printArray(arr, n);
    bubbleSort(arr, n);
    printf("Sorted array : \n");
    printArray(arr, n);
    return 0;
}
