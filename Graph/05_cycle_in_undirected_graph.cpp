// Probelm Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool solve(int idx,int parent,vector<int>& vis,vector<int> adj[]){
        vis[idx]=1;
        
        for(auto x: adj[idx]){
            if(!vis[x]){
                if(solve(x,idx,vis,adj)) return true;
            }
            else if(x!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V);
        if(solve(0,-1,vis,adj))
            return true;
            
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
                
        //     }
            
        // }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}