#include <iostream>
using namespace std;
int partition(int arr[] , int l , int r)
{
    int e = arr[r];
    int i=l;
    for(int j=l ; j<= r-1 ; j++)
    {
        if(arr[j]<=e)
        {
            swap(arr[i] , arr[j]);
            i++;
        }
    }
    swap(arr[i] , arr[r]);
    return i;
}

int rand_partition( int arr[] , int l , int r)
{
    int n = r-l+1;
    int pivot = rand()%n;
    swap(arr[1+pivot] , arr[r]);
    return partition(arr , l , r);
    }

int rand_select ( int arr[] , int l , int r , int i)
{
    if( i >0 && i<= r-l+1)
    {
        // partitoining around random pivot
        int pos = rand_partition(arr , l , r);

        if(pos-l == i-1 )
            return (arr[pos]);
        if(pos-l > i-1)
            return rand_select (arr , l , pos-l , i);

        return rand_select (arr , pos+1 , r , i-pos+l-1);
    }

    // If k is more than the number of elements in the array
    return INT_MAX;

}




int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26 };
    int n =7, k = 3;
    cout << "K'th smallest element is " << rand_select(arr, 0, n-1, k);
    return 0;
}
