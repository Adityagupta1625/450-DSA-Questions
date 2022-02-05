// kth permutaion of an array

// Probelm link: https://leetcode.com/problems/permutation-sequence/

class Solution {
private:
    
    int helper(int n,int k,string& ans,int& cnt,vector<int> vis){
        if(ans.size()==n){
            cnt+=1;
            if(k==cnt)
                return 0;
            return 1;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                ans.push_back((char)(i+1+48));
                if(helper(n,k,ans,cnt,vis)==0)
                    return 0;
                vis[i]=0;
                ans.pop_back();
            }
        }
        return 1;
    }
public:
    string getPermutation(int n, int k) {
        
        
        string ans;
        int cnt=0;
        vector<int> vis(n);
        helper(n,k,ans,cnt,vis);
        return ans;
    }
};