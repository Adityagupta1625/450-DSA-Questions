// M-colouring Probelm

// Probelm Link: https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101], int m,vector<int>& colour,int i,int done){
    for(int k=0;k<101;k++){
        if(graph[i][k]==1){
            if(colour[k]==done)
                return false;
        }
    }
    return true;
}
bool helper(bool graph[101][101], int m,vector<int>& colour,int i){
    if(i>=colour.size()){
        return true;
    }
    for(int k=0;k<m;k++){
        if(isSafe(graph,m,colour,i,k)){
            colour[i]=k;
            if(helper(graph,m,colour,i+1)==true)
                return true;
            colour[i]=-1;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    vector<int> colour;
    for(int i=0;i<V;i++){
        colour.push_back(-1);
    }
    return helper(graph,m,colour,0);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}