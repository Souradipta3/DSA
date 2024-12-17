#include <stdio.h>

void maxheapify(int arr[], int m, int n)
{
    int max = m, temp;
    int left = m * 2;
    int right = m * 2 + 1;
    if (left <= n && arr[left] > arr[max])
    {
        max = left;
    }
    if (right <= n && arr[right] > arr[max])
    {
        max = right;
    }
    if (m != max)
    {
        temp = arr[m];
        arr[m] = arr[max];
        arr[max] = temp;
        maxheapify(arr, max, n);
    }
}

void maxheap(int arr[], int beg, int end)
{
    for (int i = end / 2; i >= beg; i--)
    {
        maxheapify(arr, i, end);
    }
}

void heapsort(int arr[], int n)
{
    int temp;
    for (int i = n; i >= 2; i--)
    {
        temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;
        maxheapify(arr, 1, i - 1);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int n;
    printf("Enter the size of the arry:");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %dth element:", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("\nThe unsorted array is=>\n");
    display(arr, n);
    maxheap(arr, 1, n);
    heapsort(arr, n);
    printf("\nThe sorted array is=>\n");
    display(arr, n);
    return 0;
}
