#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(vector<int> adj[],vector<int>& order,vector<int>& vis,int curr){
	    vis[curr]=1;
	    
	    for(auto x: adj[curr]){
	        if(!vis[x]){
	            dfs(adj,order,vis,x);
	       }
	    }
	   order.push_back(curr);
	}
	void rdfs(vector<int> adj[],vector<int>& vis,int curr){
	    vis[curr]=1;
	    
	    for(auto x: adj[curr]){
	        if(!vis[x]){
	            rdfs(adj,vis,x);
	       }
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> vis(V,0);
        vector<int> order;
        
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(adj,order,vis,i);
        }
        
        vector<int> tran[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto x: adj[i]){
                tran[x].push_back(i);
            }
        }
        
        int cnt=0;
        for(int i=V-1;i>=0;i--){
            if(!vis[order[i]]){
                cnt++;
                rdfs(tran,vis,order[i]);
            }
        } 
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}