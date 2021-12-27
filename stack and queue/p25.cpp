// Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
// The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.
 
// Example 1:

// Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
// Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
// Explanation: The grid is-
// 0 1 1 0 
// 1 1 0 0 
// 0 0 1 1 
// 0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
// (2,1) are at a distance of 1 from 1's at (0,1),
// (0,2), (0,2), (2,3), (1,0) and (1,1)
// respectively.
// Probelm Link: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    bool isValid(int row,int col,int i,int j){
        if(i>=0 && i<row && j<col && j>=0)
            return true;
        return false;
        
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    
	    vector<vector<int>> v(grid.size(),vector<int>(grid[0].size(),INT_MAX));
	    queue<pair<int,int>> q;
	    for(int i=0;i<grid.size();i++){
	        for(int j=0;j<grid[i].size();j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                v[i][j]=0;
	            }
	                
	        }
	    }
	    q.push({-1,-1});
	    int move=1;
	    int row=grid.size();
	    int col=grid[0].size();
	 
	    while(!q.empty()){
	        if(q.front().first==-1){
    	        if(q.size()==1){
    	            q.pop();
    	            break;
    	        }
    	        else{
    	            q.pop();
    	            q.push({-1,-1});
    	            move++;
    	        }
	        }
	        int i=q.front().first;
	        int j=q.front().second;
	        if(isValid(row,col,i+1,j) && grid[i+1][j]==0){
	            grid[i+1][j]=1;
	            v[i+1][j]=move;
	            q.push({i+1,j});
	        }
	        if(isValid(row,col,i-1,j) && grid[i-1][j]==0){
	            grid[i-1][j]=1;
	            v[i-1][j]=move;
	            q.push({i-1,j});
	        }
	        if(isValid(row,col,i,j+1) && grid[i][j+1]==0){
	            grid[i][j+1]=1;
	            v[i][j+1]=move;
	            q.push({i,j+1});
	        }
	        if(isValid(row,col,i,j-1) && grid[i][j-1]==0){
	            grid[i][j-1]=1;
	            v[i][j-1]=move;
	            q.push({i,j-1});
	        }
	        q.pop();
	    }
	    return v;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  