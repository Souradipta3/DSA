#include <iostream>
using namespace std;


void print_array(int *arr, int n)
{
    cout<<arr[0];
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        cout<<"\t";
    }
    cout<<"\n";
}

void merge(int *arr, int low, int mid, int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int array[100];
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            array[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            array[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        array[k]=arr[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        array[k]=arr[j];
        j++;
        k++;
    }
    for(int i=low;i<high;i++)
    {
        arr[i]=array[i];
    }
}


void sorting(int *arr, int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        sorting(arr,low,mid);
        sorting(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main()
{
    int n;
    int arr[n];
    cout<<"Enter the size of the array: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the elements of the "<<i+1<<" array:"<<endl;
        cin>>arr[n];
    }
    cout<<"Unsorted array is....."<<endl;
    print_array(arr,n);
    cout<<"Sorting is in progress....."<<endl;
    sorting(arr,0,n);
    cout<<"Sorted array is....."<<endl;
    print_array(arr,n);
    return 0;
}