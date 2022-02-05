// Probelm link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
private:
    void bfs( vector<int> v[],int i,vector<int>& vis){
        vis[i]=1;
        for(auto x: v[i]){
            if(!vis[x])
                bfs(v,x,vis);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        
        vector<int> vis(n,0);
        vector<int> v[n];
        
        for(int i=0;i<connections.size();i++){
            v[connections[i][0]].push_back(connections[i][1]);
            v[connections[i][1]].push_back(connections[i][0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                bfs(v,i,vis);
            }
                
        }
        
        return ans-1;
    }
};