#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	typedef pair<int,int> pli;
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int ans=0;
        vector<int> vis(V,0);
        priority_queue<pli,vector<pli>,greater<pli>> pq;
        pq.push({0,0});
      
        vector<int> w(V,INT_MAX);
        w[0]=0;
        while(!pq.empty()){
            int vertex=pq.top().second;
            int weight=pq.top().first;
            pq.pop();
            if(vis[vertex])
                continue;
            vis[vertex]=1;    
            for(auto x: adj[vertex]){
                if(w[x[0]]>x[1] && vis[x[0]]==0){
                    w[x[0]]=x[1];
                    pq.push({x[1],x[0]});
                }
            }
        }
        for(auto i:w){
            ans+=i;
        }
        return ans;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
