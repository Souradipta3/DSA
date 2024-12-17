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

void deletion(int *arr, int size, int index, int capacity)
{
    /*if (size <= capacity)
    {
        cout << "Deletion is unsuccessful!" << endl;
    }*/
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    cout << "Deletion is successful!" << endl;
}

int main()
{
    int arr[50] = {3, 6, 9, 11, 12, 15, 21};
    int size = sizeof(arr) / sizeof(int);
    int index, capacity = 50;

    cout << "Enter the index of the element which you want to delete:" << endl;
    cin >> index;

    cout << "The given array is:" << endl;
    display(arr, size);

    cout << "Deletion is in progress....." << endl;
    deletion(arr, size, index, capacity);
    size -= 1;

    cout << "The array after deletion is:"<<endl;
    display(arr, size);

    return 0;
}