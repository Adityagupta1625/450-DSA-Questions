class Solution {
private:
    
    void dfs(vector<int> adj[],int curr,int parent,vector<int>& vis,vector<int>& low,vector<int>& tin,int& time,vector<vector<int>>& ans){
        vis[curr]=1;
        time++;
        low[curr]=tin[curr]=time;
        
        for(auto x: adj[curr]){
            if(!vis[x]){
                dfs(adj,x,curr,vis,low,tin,time,ans);
                 low[curr]=min(low[x],low[curr]);
                
                if(low[x]>tin[curr]){
                     ans.push_back({curr,x});
                }
            }
            else if(x!=parent){
                low[curr]=min(low[x],low[curr]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)    {
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        vector<int> vis(n,0);
        vector<int> low(n,0);
        vector<int> tin(n,0);
        vector<vector<int>> ans;
        int time=0;
        dfs(adj,0,-1,vis,low,tin,time,ans);
        return ans;
    }
};