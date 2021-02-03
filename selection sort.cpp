#include <iostream>
using namespace std;

int partition ( int arr[] , int low , int high)
{
    int pivot = arr[high];
    int i = low -1;
}

void selection_sort(int data[] , int size )
{

    for ( int i=0 ,j , least; i< size-1 ; i++)
    {
        for( j = i+1 ,least=i  ; j< size ; j++)
        {
            if(data[j]<data[least])
            {
                least=j;
            }
        }
        swap(data[least] , data[i]);
    }
    for(int i=0 ; i< size ; i++)
        cout<<data[i]<<endl;
}

int main()
{
    int arr[5]= {10 , 1 , 23 , 100 , 3};
    selection_sort(arr , 5 );
}
