// Nqueens probelm

// probelm link: https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(vector<vector<int>> b,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(b[row][i]==1)
                return false;
        }
        
        for(int i=0;i<n;i++){
            if(b[i][col]==1)
                return false;
        }
        
        for(int i=row,j=col;j>=0 && i>=0 ;i--,j--){
            if(b[i][j]==1)
                return false;
        }
        for(int i=row,j=col;j<n && i<n ;i++,j++){
            if(b[i][j]==1)
                return false;
        }
        for(int i=row,j=col;j<n && i>=0;i--,j++){
            if(b[i][j]==1)
                return false;
        }
        for(int i=row,j=col;j>=0 && i<n;i++,j--){
            if(b[i][j]==1)
                return false;
        }
        return true;
    }
    void solve(vector<vector<int>>& ans,int n,vector<vector<int>> b,int row,vector<int> sol){
        if(row==n){
            ans.push_back(sol);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafe(b,row,col,n)){
                b[row][col]=1;
                sol.push_back(col+1);
                solve(ans,n,b,row+1,sol);
                sol.pop_back();
                b[row][col]=0;
            }
            
        }
       
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        
        vector<vector<int>> b;
        for(int i=0;i<n;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
               v.push_back(0);
            }
            b.push_back(v);
        }
        vector<vector<int>> ans;
        vector<int> sol;
        solve(ans,n,b,0,sol);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
