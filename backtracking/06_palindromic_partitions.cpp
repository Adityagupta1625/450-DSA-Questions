// Palindromic Partitions

// Probelm Link: https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  private:
    bool isPalindrome(string s){
        string rev=s;
        reverse(s.begin(),s.end());
        return rev==s;
    }
    void helper(string s,vector<vector<string>>& ans,vector<string>& res){
        if(s.length()==0){
            ans.push_back(res);
            return;
        }
        for(int i=0;i<s.length();i++){
            string prefix=s.substr(0,i+1);
            string left=s.substr(i+1);
            if(isPalindrome(prefix)){
                res.push_back(prefix);
                helper(left,ans,res);
                res.pop_back();
            }
        }
    }
  public:
    vector<vector<string>> allPalindromicPerms(string S) {
        // code here
        vector<vector<string>> ans;
        vector<string> res;
        helper(S, ans,res);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}