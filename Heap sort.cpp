#include <iostream>
using namespace std;

void heapify (int arr[] , int n , int i)
{
    int mx = i;
    int l = 2*i +1;
    int r = 2*i +2;

    if(l<n && arr[l]>arr[mx])
        mx = l;
    if(r<n && arr[r]>arr[mx])
        mx = r;
    if(mx!=i){
        swap(arr[i],arr[mx]);
        heapify(arr , n , mx);
    }
    }
void heapSort(int arr[] , int n)
{
    for(int i = n/2-1 ; i>=0 ; i--)
        heapify(arr , n , i);
    for(int i=n-1 ; i>0 ; i--)
        {
            swap(arr[0] , arr[i]);
            heapify(arr , i , 0);
        }

}


int main()
{
    int arr[] = { 44 , 11 , 1 , 5 , 0 , 99 , 100 , 123 , 4 , 94 };
    int n = 10;
    heapSort(arr, n);
    cout<<"Array after sorting"<<endl;
    for(int i=0 ; i<n ; i++)
        cout<<arr[i]<<" ";
}
