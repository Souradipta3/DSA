#include <iostream>
using namespace std;

void display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        cout << "\t";
    }
    cout << "\n";
}

void insertion(int *arr, int size, int capacity, int element, int index)
{
    if (size >= capacity)
    {
        cout << "Unsuccessful insertion!" << endl;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    cout << "Successful insertion!" << endl;
}

int main()
{
    int arr[50] = {3, 6, 9, 15, 18, 21};
    int size = sizeof(arr) / sizeof(int);
    int element, index, capacity = 50;

    cout << "Enter the element to be inserted in the given array: " << endl;
    cin >> element;

    cout << "Enter the index where the element need to be inserted: " << endl;
    cin >> index;

    cout << "The given array is: " << endl;
    display(arr, size);

    cout << "Insertion is in progress....." << endl;
    insertion(arr, size, capacity, element, index);
    size += 1;

    cout << "The array after inserting is: " << endl;
    display(arr, size);

    return 0;
}