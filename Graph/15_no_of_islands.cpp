// Probelm link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
  int x[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
   int y[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
    bool isSafe(int row,int col,int n,int m,vector<vector<char>>& grid){
        if(row>=0 && row<n && col>=0 && col<m && grid[row][col]=='1')
            return true;
        return false;
    }
    void dfs(int i,int j,vector<vector<char>>& grid){
      
        grid[i][j]='0';
        
        for(int k=0;k<8;k++){
            int new_x=i+x[k];
            int new_y=j+y[k];
            if(isSafe(new_x,new_y,grid.size(),grid[0].size(),grid)){
                dfs(new_x,new_y,grid);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code heref
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,grid);
                }
                    
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}