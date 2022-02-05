// Probelm link: https://practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto x: adj[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                 q.push(i);
            }
        }
    
	    while(!q.empty()){
            int idx=q.front();
            q.pop();
            ans.push_back(idx);
            for(auto x: adj[idx]){
                indegree[x]--;
                    
                if(indegree[x]==0)
                    q.push(x);
                
            }
        }
        
	    return ans;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}