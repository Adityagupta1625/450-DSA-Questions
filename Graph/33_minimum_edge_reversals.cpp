#include <set>
#include <climits>
int reverseEdges(int n, int start, int end, vector<vector<int>> &edgeList)
{
	// Write your code here
    vector<pair<int,int>> adj[n];
    for(auto x: edgeList){
        adj[x[0]].push_back({x[1],0});
        adj[x[1]].push_back({x[0],1});
    }
    
    set<pair<int,int>> s;
    s.insert({0,start});
    vector<int> distance(n,INT_MAX);
    distance[start]=0;
    while(!s.empty()){
        pair<int,int> p=*s.begin();
        int curr=p.second;
        int dis=p.first;
        
        s.erase(s.begin());
        
        for(auto x: adj[curr]){
            if(distance[x.first]>distance[curr]+x.second){
                if(distance[x.first]!=INT_MAX){
                    s.erase(s.find({distance[x.first],x.first}));
                }
                distance[x.first]=distance[curr]+x.second;
                s.insert({distance[x.first],x.first});
            }
        }
    }
    
    return distance[end];
}