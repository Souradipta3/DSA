#include <iostream>
using namespace std;

/*int linear_search(int *arr, int size, int search)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }
    return -1;
}*/

int binary_search(int *arr, int size, int search)
{
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == search)
        {
            return mid;
        }
        if (search > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    //int arr[] = {86, 9, 11, 45, 62, 3, 8, 22, 6, 1, 71, 35};
    int arr[] = {3, 12, 38, 65, 72, 89, 102, 125, 167, 183, 200};
    int size = sizeof(arr) / sizeof(int);
    int search;
    cout << "Enter the element to be searched:" << endl;
    cin >> search;
    //int index = linear_search(arr, size, search);
    int index = binary_search(arr, size, search);
    cout << "The searched element " << search << " is in the index number : " << index << endl;
    return 0;
}
