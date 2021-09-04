// Given an array arr of size n and an integer X. Find if there's a triplet in the array which sums up to the given integer X.

// Example 1:

// Input:
// n = 6, X = 13
// arr[] = [1 4 45 6 10 8]

// Output:
// 1
// Explanation:
// The triplet {1, 4, 8} in 
// the array sums up to 13.

// question link https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //Function to find if there exists a triplet in the
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int x)
    {
        //Your Code Here
        sort(arr, arr + n);
        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[j];
                if (sum + arr[k] > x)
                {
                    k--;
                }
                else if (sum + arr[i] == x)
                {
                    return true;
                }
                else
                {
                    j++;
                }
            }
        }
        return false;
    }
};
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}