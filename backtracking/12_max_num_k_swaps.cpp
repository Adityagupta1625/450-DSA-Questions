// Maximum String from k Swaps  

// Probelm link: https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void helper(string s,int k,string& ans,int ind){
        if(k==0) return;
        
        if(ind==s.length()) return;
        
        int maxchar=s[ind]-'0';
        for(int i=ind+1;i<s.length();i++){
           if(s[i]-'0'>maxchar)
            maxchar=s[i]-'0';
        }
        
        if(maxchar!=s[ind]-'0')
            k--;
            
        for(int j=s.length()-1;j>=ind;j--){
            if(maxchar==s[j]-'0'){
                swap(s[ind],s[j]);
                
                if(ans<s)
                    ans=s;
                    
                helper(s,k,ans,ind+1);
                
                swap(s[j],s[ind]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans=str;
       int ind=0;
       helper(str,k,ans,ind);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}