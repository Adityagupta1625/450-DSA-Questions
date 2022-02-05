// Probelm link: https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1 

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isSafe(int newx,int newy,int N){
         if(newx>=0 && newx<=N && newy>=0 && newy<=N)
            return true;
         return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int x[8]={ -2, -1, 1, 2, -2, -1, 1, 2 };
	    int y[8]={-1,  -2, -2, -1,  1,  2, 2, 1} ;
	    
	    queue<pair<pair<int,int>,int>> q;
	    
	    int target_x=TargetPos[0];
	    int target_y=TargetPos[1];
	    
	    q.push({{KnightPos[0],KnightPos[1]},0});
	    
	    vector<vector<int>> visited(N+1);
	    for(int i=0;i<=N;i++){
	        for(int j=0;j<=N;j++){
	            visited[i].push_back(0);
	        }
	    }
	    visited[KnightPos[0]][KnightPos[1]]=1;
	    int cnt=0;
	    while(!q.empty()){
	        int posx=q.front().first.first;
	        int posy=q.front().first.second;
	        int dis=q.front().second;
	        
	        q.pop();
	        
	        if(posx==target_x && posy==target_y)
	            return dis;
	            
	        for(int i=0;i<8;i++){
	            int newx=posx+x[i];
	            int newy=posy+y[i];
	            if(isSafe(newx,newy,N)){
	                
    	            if(visited[newx][newy]==0){
    	                visited[newx][newy]=1;
    	                q.push({{newx,newy},dis+1});
    	            }
	            }
	        }
	        
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
} 