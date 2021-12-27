// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

// Example 1:

// Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
// Output: 1
// Explanation: The grid is-
// 0 1 2
// 0 1 2
// 2 1 1
// Oranges at positions (0,2), (1,2), (2,0)
// will rot oranges at (0,1), (1,1), (2,2) and 
// (2,1) in unit time.
// Probelm Link: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1#

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    bool valid(int i,int j,int r,int c){
        if(i>=0 && j>=0 && i<r && j<c)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    pair<int,int> t;
                    t.first=i;
                    t.second=j;
                    q.push(t);
                }
            }
        }
        q.push({-1,-1});
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        while(!q.empty()){
            if(q.front().first==-1 && q.front().second==-1){
                if(q.size()==1){
                    q.pop();
                    break;
                }
                else{
                    q.push({-1,-1});
                    q.pop();
                    ans++;
                }
            }
            pair<int,int> h=q.front();
            int i=h.first;
            int j=h.second;
            if(valid(i+1,j,row,col) && grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({i+1,j});
                
            }
             if(valid(i-1,j,row,col) && grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({i-1,j});
                
            }
             if(valid(i,j+1,row,col) && grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push({i,j+1});
                
            }
             if(valid(i,j-1,row,col) && grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({i,j-1});
                
            }
            q.pop();
        }
         for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}