// Negative cycle code also
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(n,INT_MAX);
	    dist[0]=0;
	    for(int j=0;j<n-1;j++){
    	    for(int i=0;i<edges.size();i++){
    	        int u=edges[i][0];
    	        int v=edges[i][1];
    	        int w=edges[i][2];
    	        
    	        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
    	            dist[v]=dist[u]+w;
    	        }
    	    }
	    }
	    
	    for(int i=0;i<edges.size();i++){
	        int u=edges[i][0];
    	    int v=edges[i][1];
    	    int w=edges[i][2];
    	        
    	   if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
    	       return true;
    	   }
	    }
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}