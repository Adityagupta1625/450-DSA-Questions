
// Probelm Link: https://practice.geeksforgeeks.org/problems/
// consecutive-elements2306/1#
// Given a string S delete the characters which are appearing more than once consecutively.

// Example 1:

// Input:
// S = aabb
// Output:  ab 
// Explanation: 'a' at 2nd position is
// appearing 2nd time consecutively.
// Similiar explanation for b at
// 4th position.

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        int n=S.length();
        stack<char> st;
        string res="";
        st.push(S[0]);
        res=res+S[0];
        for(int i=1;i<n;i++){
            if(S[i]!=st.top()){
                res=res+S[i];
            }
            st.push(S[i]);
        }
        return res;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 