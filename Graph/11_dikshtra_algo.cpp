// Probelm link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> s;
        vector<int> ans(V,INT_MAX);
        
        s.insert({0,S});
        ans[S]=0;
        
        while(!s.empty()){
            pair<int,int> tmp=*(s.begin());
            int vertex=tmp.second;
            int dist=tmp.first;
            
            s.erase(s.find({dist,vertex}));
            
            for(auto x: adj[vertex]){
                int u=x[0],w=x[1];
                if(ans[u]>w+dist){
                    ans[u]=w+dist;
                    s.insert({ans[u],u});
                }
            }
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}