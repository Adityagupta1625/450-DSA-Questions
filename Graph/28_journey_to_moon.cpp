void dfs(vector<int>& vis,vector<int> adj[],int curr,int& size){
    vis[curr]=1;
    size++;
    for(auto x: adj[curr]){
        if(!vis[x]){
            dfs(vis,adj,x,size);
        }
    }
}
int journeyToMoon(int n, vector<vector<int>> a) {
    vector<int> adj[n];
    for(int i=0;i<a.size();i++){
        adj[a[i][0]].push_back(a[i][1]);
        adj[a[i][1]].push_back(a[i][0]);
    }
    
    vector<int> vis(n,0);
    vector<int> v;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            int size=0;
            dfs(vis,adj,i,size);
            v.push_back(size);
        }  
    }
    
    long long int total=n*(n-1)/2;
    
    long long int x=0;
    for(int i=0;i<v.size();i++){
        x+=(v[i]*(v[i]-1)/2);
        
    }
    return total-x;
}