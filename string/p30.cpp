// Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
// For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

// Example 1:

// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"
// Probelm link: https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string findSubString(string str)
    {
        // Your code goes here
        // Your code goes here
        int h[256] = {0};
        int n = str.length();
        if (n <= 1)
        {
            return str;
        }
    
        int cnt = 0, min_len = INT_MAX, start = 0,start_index=-1;
        for (int i = 0; i < str.length(); i++)
        {
            if (h[str[i]] == 0)
            {
                h[str[i]] = 1;
                cnt++;
            }
        }
        int curr[256]={0},dist=0;
        for (int i = 0; i < n; i++)
        {
            curr[str[i]]++;
            if (curr[str[i]]==1)
            {
                dist++;
            }
            if (dist==cnt)
            {
                while (curr[str[start]]>1)
                {
                    if (curr[str[start]]>1)
                    {
                        curr[str[start]]--;
                    }
                    start++;
                }
                int len=i-start+1;
                if (min_len>len)
                {
                    min_len=len;
                    start_index=start;
                }
                
            }
        }
        return str.substr(start_index,min_len);
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
}