// Given two strings wild and pattern where wild string may contain wild card characters and pattern string is a normal string. Determine if the two strings match. The following are the allowed wild card characters in first string :-

// * --> Matches with 0 or more instances of any 
// character or set of characters.
// ? --> Matches with any one character.
// Example 1:

// Input: wild = ge*ks
//        pattern = geeks
// Output: Yes
// Explanation: Replace the '*' with 'e' to obtain 
// the string.
// Probelm link: https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1#
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int ops(string wild, string pattern, int i, int j)
    {
        if (i == wild.length() && j == pattern.length())
            return 1;
        if (wild[i] == '*' && wild[i + 1] != '\0' && pattern[j] == '\0' && wild[i + 1] != '*')
            return 0;
        if (wild[i] == pattern[j] || wild[i] == '?')
            return ops(wild, pattern, i + 1, j + 1);

        if (wild[i] == '*')
        {
            int ch1 = ops(wild, pattern, i + 1, j);
            int ch2 = ops(wild, pattern, i, j + 1);
            return ch1 || ch2;
        }

        return 0;
    }
    bool match(string wild, string pattern)
    {
        int check = ops(wild, pattern, 0, 0);
        if (check == 1)
            return true;
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string wild, pattern;
        cin >> wild >> pattern;

        Solution ob;
        if (ob.match(wild, pattern))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}