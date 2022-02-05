// Probelm Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],int V,vector<int>& vis,vector<int>& order,int i){
        vis[i]=1;
        order[i]=1;
        
        for(auto x: adj[i]){
           if(!vis[x]){
                
                if(dfs(adj,V,vis,order,x))
                 return true;
            }
            else if(order[x]){
                return true;
            }
         
        }
        order[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> order(V,0);
        
        for(int i=0;i<V;i++){
           if(!vis[i]){
               bool c=dfs(adj,V,vis,order,i);
           
               if(c==true)
                 return true;
           }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}