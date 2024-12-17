#include <iostream>
using namespace std;


void print_array(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
        cout<<"\t";
    }
    cout<<endl;
}


void sorting(int *arr,int n)
{
    int temp;
    int sorted=0;
    for(int i=0;i<n-1;i++)
    {
        //sorted=1;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        /*if(sorted)
        {
            return;
        }*/
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
