// Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.
 

// Example 1:

// Input: 
// s = "geek", t = "gesek"
// Output: 1
// Explanation: One operation is required 
// inserting 's' between two 'e's of str1.

// Probelm link: https://practice.geeksforgeeks.org/problems/edit-distance3702/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int dp[1001][1001];
    int func(string s,string t,int n,int m){
        if(m==-1)
            return n+1;
            
        if(n==-1)
            return m+1;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(s[n]==t[m])
            return dp[n][m]=func(s,t,n-1,m-1);
        
        int a=func(s,t,n-1,m-1);
        int b=func(s,t,n,m-1);
        int c=func(s,t,n-1,m);
        
        return dp[n][m]=1+min(a,min(b,c));
    }
    int editDistance(string s, string t) {
        // Code here
       memset(dp,-1,sizeof(dp));
       int n=s.length();
       int m=t.length();
       return func(s,t,n-1,m-1);
        
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}