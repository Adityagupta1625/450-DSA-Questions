// Given an array nums[] of size n, construct a Product Array P (of same size n) such that P[i] is equal to the product of all the elements of nums except nums[i]

// Example 1:

// Input:
// n = 5
// nums[] = {10, 3, 5, 6, 2}
// Output:
// 180 600 360 300 900
// Explanation: 
// For i=0, P[i] = 3*5*6*2 = 180.
// For i=1, P[i] = 10*5*6*2 = 600.
// For i=2, P[i] = 10*3*6*2 = 360.
// For i=3, P[i] = 10*3*5*2 = 300.
// For i=4, P[i] = 10*3*5*6 = 900.
// Probelm link: https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {

        //code here
        vector<long long int> left, right, v;
        long long int prod = 1;
        left.push_back(1);
        for (int i = 1; i < nums.size(); i++)
        {
            left.push_back(left[i - 1] * nums[i - 1]);
        }
        int k = 0;
        right.push_back(1);
        for (int i = n - 2; i >= 0; i--)
        {
            right.push_back(right[k] * nums[i + 1]);
            k++;
        }
        reverse(right.begin(), right.end());

        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back(left[i] * right[i]);
        }

        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}