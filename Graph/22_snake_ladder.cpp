class Solution {
private:
    pair<int,int> find_rc(int curr,int new_curr,int n){
        int r=(curr-1)/n;
        int new_r=(new_curr-1)/n;
        int new_c=(new_curr-1)%n;
        
        

            if(new_r%2!=0){
                return {new_r,n-new_c-1};
            }
            else{
                return {new_r,new_c};
            }
        
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int,int>> q;
        
        q.push({1,0});
       
        int n=board.size();
        vector<int> vis(n*n+1,0);
        while(!q.empty()){
            int idx=q.front().first;
            int moves=q.front().second;
            
            q.pop();
            if(idx>n*n)
                continue;
            
            if(idx==n*n)
                return moves;
            
            if(vis[idx]==1)
                continue;
            
            vis[idx]=1;
            for(int i=1;i<=6;i++){
                if(idx+i<=n*n){
                    pair<int,int> rc=find_rc(idx,idx+i,n);
                    
                    int r=n-1-rc.first;
                    int c=rc.second;
                    
                    if(board[r][c]==-1)
                        q.push({i+idx,moves+1});
                    else
                        q.push({board[r][c],moves+1});
                }
            }
   
        }
        return -1;
    }
};