// Combinational Sum

// Probelm Link: https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void helper(vector<int>& v,int b,vector<vector<int>>& ans,int idx,
                int n,vector<int>& res){
        
        if(b==0){
            ans.push_back(res);
            return;
        }
        
        if(idx==n)
            return;
      
        if(v[idx]<=b){
            res.push_back(v[idx]);
            helper(v,b-v[idx],ans,idx,n,res);
            res.pop_back();
        }
        helper(v,b,ans,idx+1,n,res);
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        set<int> s;
        
        for(int i=0;i<A.size();i++){
            s.insert(A[i]);
        }
        A.clear();
        for(auto x: s){
            A.push_back(x);
        }
        
        vector<vector<int>> ans;
        vector<int> res;
        int n=A.size();
        int idx=0;
        helper(A,B,ans,idx,n,res);
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
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}