#include <iostream>
using namespace std;

void print_array(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        cout<<"\t";
    }
    cout<<"\n";
}

void sorting(int *arr,int n)
{
    int key,j;
    for(int i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(arr[j]>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
