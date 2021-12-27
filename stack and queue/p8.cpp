// Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
// NOTE: Length of the smallest valid substring ( ) is 2.

// Example 1:

// Input: S = "(()("
// Output: 2
// Explanation: The longest valid 
// substring is "()". Length = 2.

// Probelm Link: https://practice.geeksforgeeks.org/problems/valid-substring0624/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int left=0,rigth=0;
        int len=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                left++;
            else
                rigth++;
            
            if(left==rigth)
                len=max(len,2*rigth);
            else if(left<rigth)
                left=rigth=0;
        }
        left=rigth=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='(')
                left++;
            else
                rigth++;
            
            if(left==rigth)
                len=max(len,2*rigth);
            else if(left>rigth)
                left=rigth=0;
        }
        return len;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}