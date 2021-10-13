/*

13-10-2021
Author: G. Vimal Keerthi
Description:
This program consists of 4 modules : main(), build_maxheap(), max_heapify() and swap()
main() - read the elements of heap, call build_maxheap()
build_maxheap() - use a loop to build a max heap by calling max_heapify()
max_heapify() - arranges the elements to form a max heap
swap() - swap the desired elements

*/


#include <iostream>
using namespace std;

int hs; // heap size

void swap(int *x, int *y)
{
    // swap elements using third variable
    int temp = *x;
    *x = *y;
    *y = temp;
}

void max_heapify(int arr[], int i)
{
    int lc = 2*i+1, rc = 2*(i+1), largest; // find the indices of left child and right child of i
    if(lc<hs && arr[lc]>arr[i]) largest = lc; // find max between lc, i th elements
    else largest = i;
    if(rc<hs && arr[rc]>arr[largest]) largest = rc; // find max between largest, rc th elements
    if(largest!=i)
    {
        //swap largest, i th elements
        swap(&arr[largest],&arr[i]);
        max_heapify(arr,largest);
    }
}

void build_maxheap(int arr[], int n)
{
    for(int i=(n/2)-1;i>=0;i--)
        max_heapify(arr,i);
}

int main()
{
    int n;
    cout<<"Enter the size of heap: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    hs = n;
    build_maxheap(arr,n);
    cout<<"The heap is : ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
