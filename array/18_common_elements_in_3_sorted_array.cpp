// Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.
// Note: can you take care of the duplicates without using any additional Data Structure?

// Example 1:

// Input:
// n1 = 6; A = {1, 5, 10, 20, 40, 80}
// n2 = 5; B = {6, 7, 20, 80, 100}
// n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}

// Output: 20 80
// Explanation: 20 and 80 are the only
// common elements in A, B and C.
// Question : https://practice.geeksforgeeks.org/problems/common-elements1132/1#
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        //code here.
        int i = 0, j = 0, k = 0;
        vector<int> d;
        int z = 0;
        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] < B[j] )
            {
                i++;
            }
            else if (B[j] < C[k])
            {
                j++;
            }
            else if (B[j] == C[k] && A[i]==C[k])
            {
                d.push_back(A[i]);
                i++;
                k++;
                j++;
            }
            else
            {
                k++;
            }
        }
        vector<int>::iterator ip;

        ip = std::unique(d.begin(), d.end());

        d.resize(std::distance(d.begin(), ip));
        return d;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
}
// -69 -68 -39 -25 -6 18 33 39 42 46 52 55 55 64 71

// -97 -92 -90 -90 -87 -85 -82 -77 -77 -77 -75 -71 -67 -64 -60 -59 -58 -52 -49 -48 -48 -47 -47 -46 -41 -36 -35 -29 -28 -26 -25 -20 -19 -14 -13 -13 -11 -10 -6 -4 2 3 9 12 15 17 20 22 23 24 27 29 36 36 37 38 39 42 45 47 48 48 50 52 52 53 57 59 60 63 63 64 64 65 68 70 71 76 76 77 83 83 84 85 86 89 97 97
// -95 -95 -86 -83 -70 -67 -57 -53 -52 -35 -33 -32 -30 -20 -16 -15 -15 -11 -10 -10 -4 0 4 15 18 34 36 37 39 41 43 43 48 49 50 51 58 63 64 67 69 77 79 84 84 94 95 97

// -39 -25 -6 18 33 39 42 46 52 55 64 71