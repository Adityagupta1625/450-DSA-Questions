// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order without actual sorting.

// Example:

// Input:
// N = 5
// arr[]= {0 2 1 2 0}

// Output:
// 0 0 1 2 2

// Link for the problem: https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

#include <iostream>
using namespace std;
class Solution
{
public:
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void sort012(int a[], int n)
    {
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high)
        {
            if (a[mid] == 0)
            {
                swap(&a[low], &a[mid]);
                mid++;
                low++;
            }
            else if (a[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(&a[mid], &a[high]);
                high--;
            }
        }
    }
};

int main()

{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[10000];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}
