#include <iostream>
using namespace std;

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        cout << "\t";
    }
    cout << "\n";
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j++;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void sorting(int *arr, int low, int high)
{
    int partition_index;

    if (low < high)
    {
        partition_index = partition(arr, low, high);
        sorting(arr, low, partition_index - 1);
        sorting(arr, partition_index + 1, high);
    }
}

int main()
{
    int n;
    int arr[n];
    cout << "Enter the size of the arry:" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the elements of " << i + 1 << " array:" << endl;
        cin >> arr[i];
    }

    cout << "Unsorted array is....." << endl;
    print_array(arr, n);
    cout << "Sorting is in progress....." << endl;
    sorting(arr, 0, n - 1);
    cout << "Sorted array is....." << endl;
    print_array(arr, n);
    return 0;
}