// Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

// Example 1:

// Input:
// S = "001"
// Output: 1
// Explanation: We can flip the 0th bit to 1
// to have "101".
// Probelm link: https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1#
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int n = S.length();
    string res1;
    for (int i = 0; i <= n / 2; i++)
    {
        res1 = res1 + "01";
    }
    string res2;
    for (int i = 0; i <= n / 2; i++)
    {
        res2 = res2 + "10";
    }
    int imbal1=0;
    for (int i = 0; i < n; i++)
    {
        if (res1[i]==S[i])
        {
            imbal1++;
        }
        
    }
    int imbal2=0;
    for (int i = 0; i < n; i++)
    {
        if (res2[i]==S[i])
        {
            imbal2++;
        }
        
    }
    int result=min(imbal1,imbal2);
    return result;
}