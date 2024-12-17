#include <iostream>
using namespace std;


void print_array(int *arr, int n) 
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        cout<<"\t";
    }
    cout<<endl;
}


void sorting(int *arr, int n)
{
    int min_index,temp;
    for(int i=0;i<n-1;i++)
    {
        min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
}


int main()
{
    int n;
    int arr[n];
    cout<<"Enter the size of the array:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the elements of the "<<i+1<<" array:"<<endl;
        cin>>arr[i];
    }
    cout<<"Unsorted array is....."<<endl;
    print_array(arr,n);
    cout<<"Sorting in progress....."<<endl;
    sorting(arr,n);
    cout<<"Sorted array is....."<<endl;
    print_array(arr,n);
    return 0;
}
