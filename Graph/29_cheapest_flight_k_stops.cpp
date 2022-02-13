class Solution {
private:
     struct ele{
         int w;
         int s;
         int stop;
     };
     struct comp{
         bool operator()(ele a,ele b){
             return a.w > b.w;
         }
     }; 
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
                adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});     
        }
        
        priority_queue<ele,vector<ele>,comp> pq;
        pq.push({0,src,k});
        
        vector<vector<int>> visit(n,vector<int>(k+1,INT_MAX));
        for(int i=0;i<=k;i++){
            visit[src][i]=0;
        }
        
        while(!pq.empty()){
           int cost=pq.top().w;
           int v=pq.top().s;
           int stop=pq.top().stop;
            pq.pop();
          
           if(v==dst){
               return cost;
           }
           
           for(auto x: adj[v]){
              
              if(x.first==dst && visit[x.first][stop]>cost+x.second){
                  visit[x.first][stop]=cost+x.second;
                  pq.push({cost+x.second,x.first,stop});
              }
              else if(stop>0 && visit[x.first][stop-1]>cost+x.second){
             
                  visit[x.first][stop-1]=cost+x.second;
                  pq.push({cost+x.second,x.first,stop-1});
              }
           }
        }
        return -1;
    }
};