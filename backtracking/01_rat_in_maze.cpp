// Rat in maze
// probelm link: https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int x,int y,vector<vector<int>> vis,int n,vector<vector<int>>m){
        if((x<n && x>=0) && (y<n && y>=0) && vis[x][y]==0 && m[x][y]==1)
            return true;
        return false;
    }
    void solve(vector<vector<int>>& m,int n,int x,int y,
    vector<string>& ans,vector<vector<int>> vis,string path){
        
      
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
         vis[x][y]=1;
        
        // down
        int newx=x+1;
        int newy=y;
        if(isSafe(newx,newy,vis,n,m)){
            path.push_back('D');
            solve(m,n,newx,newy,ans,vis,path);
            path.pop_back();
        }
        
        // left
        newx=x;
        newy=y-1;
        if(isSafe(newx,newy,vis,n,m)){
            path.push_back('L');
            solve(m,n,newx,newy,ans,vis,path);
            path.pop_back();
        }
        
        // right
        newx=x;
        newy=y+1;
        if(isSafe(newx,newy,vis,n,m)){
            path.push_back('R');
            solve(m,n,newx,newy,ans,vis,path);
            path.pop_back();
        }
        
        // up
        newx=x-1;
        newy=y;
        if(isSafe(newx,newy,vis,n,m)){
            path.push_back('U');
            solve(m,n,newx,newy,ans,vis,path);
            path.pop_back();
        }
    
        vis[x][y]=0;
       
       
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>> vis=m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=0;
            }
        }
        if(m[0][0]==0)
            return {};
        vector<string> ans;
        solve(m,n,0,0,ans,vis,"");
        sort(ans.begin(),ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} 