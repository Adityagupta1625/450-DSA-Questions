// move negative elemets to one side of array

// Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
// Output: -12 -13 -5 -7 -3 -6 11 6 5

#include <iostream>
using namespace std;
void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
int main()
{
    int arr[]={-12,11,-13,-5,6,-7,5,-3,-6};
    int n=9;
    int i=0,j=n-1;
    while (i<j)
    {
        /* code */
        if (arr[i]>0)
        {
            swap(&arr[i],&arr[j]);
            j--;
        }
        else{
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}