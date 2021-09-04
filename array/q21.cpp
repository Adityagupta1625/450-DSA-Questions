// Given an array Arr[] that contains N integers (may be positive, negative or zero). Find the product of the maximum product subarray.

// Example 1:

// Input:
// N = 5
// Arr[] = {6, -3, -10, 0, 2}

// Output: 180
// Explanation: Subarray with maximum product
// is [6, -3, -10] which gives product as 180.

// question link: https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1#
#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    // Function to find maximum product subarray

    long long maxProduct(vector<int> arr, int n)
    {
        // code here
        if(n==1){
            return arr[0];
        }
        long long int maxprod = 1, minprod = 1, overallmax = 1;
        long long int c = 1;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                maxprod = maxprod * arr[i];
                minprod = min(minprod * arr[i], c);
                flag = 1;
            }
            else if (arr[i] == 0)
            {
                maxprod = 1;
                minprod = 1;
            }
            else if (arr[i] < 0)
            {
                int care = maxprod;
                maxprod = max(minprod * arr[i], c);
                minprod = care * arr[i];
            }
            overallmax = max(maxprod, overallmax);
        }
        if (flag == 0 && overallmax == 0)
        {
            return 0;
        }
        return overallmax;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
3 12 15 23 33 -35 30 -40 -30 -30 -30 26 28