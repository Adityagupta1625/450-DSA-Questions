// To find the duplicate element in an array

// link for the question: https://leetcode.com/problems/find-the-duplicate-number/

#include <iostream>
#include <algorithm>
using namespace std;
void insert_sorted(int arr[], int n,int index)
{
  int i=n-1;
  while (i<n-1 || arr[i]>arr[i+1])
  {
      swap(arr[i],arr[i+1]);
      i++;
  }
  
   
}
int main()
{
    int arr2[] = {0, 2, 6, 8, 9};
    int arr1[] = {1, 3, 5, 7};
  
    int n = 4, m = 5;

    int i = 0, j = 0;
    while (i < n)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            swap(arr1[i], arr2[j]);
            insert_sorted(arr2,n,j);
        }
    }

    for (i = 0; i < n; i++)
    {
        /* code */
        cout << arr1[i] << " ";
    }
    for ( j = 0; j < m; j++)
    {
        /* code */
        cout << arr2[j] << " ";
    }

    return 0;
}