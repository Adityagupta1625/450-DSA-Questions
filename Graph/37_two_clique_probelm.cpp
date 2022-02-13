#include <queue>
bool bfs(vector<vector<int>>& adj,vector<int>& color,int i,int n){
    queue<int> q;
    q.push(i);
    color[i]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        
        for(int j=0;j<adj[curr].size();j++){
            if(adj[curr][j]){
               if(color[j]==-1){
                    color[j]=1-color[curr];
                    q.push(j);
            	}
                else if(color[j]==color[curr]){
                    return false;
                }
            }     
        }
    }
    return true;
}

bool twoCliques(int n, vector<vector<int>> &edgeList)
{
	vector<vector<int>> adj(n,vector<int>(n,1));
    for(auto x: edgeList){
        int i=x[0],j=x[1];
        adj[i][j]=0;
        adj[j][i]=0;
    }
   	for(int i=0;i<n;i++){
        adj[i][i]=0;
    }
     vector<int> color(n,-1);
     for(int i=0;i<n;i++){
         if(color[i]==-1){
             if(bfs(adj,color,i,n)==false)
                 return false;
         }
     }
     return true;
}