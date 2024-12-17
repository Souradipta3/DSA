#include <stdio.h>
#include <stdlib.h>

void bubble(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection(int arr[], int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
            }
        }
        temp = arr[i];
        arr[i] = min;
        min = temp;
    }
}

void reverseselection(int arr[], int n)
{
    int max, temp;
    for (int i = 0; i <= 0; i--)
    {
        max = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            if (max < arr[j])
            {
                max = arr[j];
            }
        }
        temp = arr[n - 1 - i];
        arr[n - 1 - i] = max;
        max = temp;
    }
}

void insertion(int arr[], int n)
{
    int key, i, j;
    for (i = 0; i <= n; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

/*void merge(int arr[], int low, int mid, int high, int n)
{
}

void mergesort(int arr, int low, int high, int n)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,mid,low,high,n);
    }
}*/

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
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
        printf("Enter the elements of the array:");
        scanf("%d", &arr[i]);
    }
    int choice;
    while (1)
    {
        printf("Enter 1 for Bubble sort\n");
        printf("Enter 2 for Selection sort\n");
        printf("Enter 3 for Reversed Selection sort\n");
        printf("Enter 4 for Insertion sort\n");
        printf("Enter 5 for exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubble(arr, n);
            printf("The array is sorted by bubble method\n");
            display(arr, n);
            break;
        case 2:
            selection(arr, n);
            printf("The array is sorted by selection method\n");
            display(arr, n);
            break;
        case 3:
            reverseselection(arr, n);
            printf("The array is sorted by reverse selection method\n");
            display(arr, n);
            break;
        case 4:
            insertion(arr, n);
            printf("The array is sorted by insertion sort\n");
            display(arr, n);
            break;
        /*case 5:
            mergesort(arr, 0, n);
            printf("The array is sorted by merge sort\n");
            display(arr, n);
            break;*/
        case 6:
            exit(0);
        default:
            printf("Wrong choice!\n");
        }
    }
    return 0;
}
