// Probelm link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis;
        vector<int> ans;
        for(int i=0;i<V;i++){
            vis.push_back(0);
        }
        queue<int> q;
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int id=q.front();
            q.pop();
            ans.push_back(id);
            for(auto x: adj[id]){
                if(!vis[x]){
                   q.push(x);
                   vis[x]=1;
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  