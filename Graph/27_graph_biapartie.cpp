class Solution {
private:
    bool dfs(vector<vector<int>>& graph,
            vector<int>& color,int i){
       
        if(color[i]==-1){
            color[i]=0;
        }
        for(auto x: graph[i]){
            if(color[x]==-1){
                 color[x]=1-color[i];
                 if(!dfs(graph,color,x)) return false;   
            }
            else if(color[x]==color[i]) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
         int v=graph.size();
         vector<int> color(v,-1);
            
        
         for(int i=0;i<v;i++){
             if(color[i]==-1){
                 
                 if(dfs(graph,color,i)==false)
                     return false;
             }
         }
         return true;
    }
};