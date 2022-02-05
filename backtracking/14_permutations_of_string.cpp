// Permutations of a Given String

// Probelm Link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:
        void solve(string S,vector<string>& ans,string str,map<char,int>& visited){
            if(str.length()==S.length()){
                ans.push_back(str);
                return;
            }
            
            for(int i=0;i<S.length();i++){
                if(!visited[S[i]]){
                    
                    visited[S[i]]=1;
                    str.push_back(S[i]);
                    solve(S,ans,str,visited);
                    str.pop_back();
                    visited[S[i]]=0;
                }
            }
           
        }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    map<char,int> visited;
		    solve(S,ans,"",visited);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}