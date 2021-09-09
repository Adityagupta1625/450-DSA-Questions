// Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.

// Example 1:
// Input:
// R = 3, C = 3
// M = [[1, 3, 5], 
//      [2, 6, 9], 
//      [3, 6, 9]]

// Output: 5
// Explanation:
// Sorting matrix elements gives us 
// {1,2,3,3,5,6,6,9,9}. Hence, 5 is median. 

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        // code here

        int lowval = 1, highval = 2000, midval;
        int n = r * c;
        while (lowval <= highval)
        {
            midval = (lowval + highval) / 2;
            int ans = 0;
            for (int i = 0; i < r; i++)
            {
                int l = 0, h = c - 1;
                while (l <= h)
                {
                    int m = l + (h - l) / 2;
                    if (matrix[i][m] <= midval)
                    {
                        l = m + 1;
                    }
                    else
                    {
                        h = m - 1;
                    }
                }
                ans = ans + l;
            }
            if (ans <= n / 2)
            {
                lowval = midval + 1;
            }
            else
            {
                highval = midval - 1;
            }
        }
        return lowval;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}