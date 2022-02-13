// Given an integer N, find its factorial.

// Example 1:

// Input: N = 5
// Output: 120
// Explanation : 5! = 1*2*3*4*5 = 120

//Probelm link: https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void multiply(vector<int> &f, int k)
    {
        int carry = 0, prod = 0;

        int i;
        for (i = 0; i < f.size(); i++)
        {
            prod = f[i] * k + carry;
            f[i] = prod % 10;
            carry = prod / 10;
        }

        while (carry)
        {
            f.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    vector<int> factorial(int N)
    {
        // code here
        vector<int> f;
        f.push_back(1);
        for (int i = 2; i <= N; i++)
        {
            /* code */

            multiply(f, i);
        }
        reverse(f.begin(), f.end());
        return f;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}

// 10
// 8 -2 -2 0 8 0 -6 -8 -6 -1