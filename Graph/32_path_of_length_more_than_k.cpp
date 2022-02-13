bool helper(vector<int>& vis,int src,vector<pair<int,int>> adj[],int k){
    if(k<0){
        return true;
    }
    vis[src]=1;
    for(auto x: adj[src]){
        int idx=x.first;
         int wt=x.second;
        if(!vis[idx]){
           
            if(helper(vis,idx,adj,k-wt)) return true;
           
        }
    }
    vis[src]=0;
    return false;
}
string pathMoreThanK(int n, int m, int k, vector<vector<int>>& edges)
{
    // Write your code here.
    vector<pair<int,int>> adj[n];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    vector<int> vis(n,0);
    
    int src=0;
    int path=0;
    if(helper(vis,src,adj,k)){
        return "YES";
    }
    return "NO";	
}