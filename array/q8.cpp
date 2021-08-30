// Given an array arr of N integers. Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum.

// Example 1:

// Input:
// N = 5
// arr[] = {1,2,3,-2,5}

// Output:
// 9

// Explanation:
// Max subarray sum is 9
// of elements (1, 2, 3, -2, 5) which
// is a contiguous subarray.

// question link : https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1#
#include <iostream>
using namespace std;

class Solution
{
public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n)
    {
        int sum = 0, maxsum = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            sum = sum + arr[i];

            if (maxsum < sum)
            {
                maxsum = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxsum;
    }
};
int main()
{
    int t, n;

    cin >> t;   //input testcases
    while (t--) //while testcases exist
    {

        cin >> n; //input size of array

        int a[1000000];

        for (int i = 0; i < n; i++)
            cin >> a[i]; //inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
    return 0;
}