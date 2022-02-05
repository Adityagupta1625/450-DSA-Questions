// Probelm Link: https://practice.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    private:
        void dfs( vector<int> adj[],vector<int>& vis,int idx,string& ans){
            vis[idx]=1;
            
            for(auto x: adj[idx]){
                if(!vis[x]){
                    dfs(adj,vis,x,ans);
                }
            }
            ans=ans+(char)(idx+97);
        }
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<int> adj[k];
        for(int i=0;i<n-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            
            for(int i=0;i<s1.length() && i<s2.length();i++){
                if(s1[i]!=s2[i]){
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
        }
        
        string ans;
        vector<int> vis(k,0);
        for(int i=0;i<k;i++){
            if(!vis[i]){
                dfs(adj,vis,i,ans);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}