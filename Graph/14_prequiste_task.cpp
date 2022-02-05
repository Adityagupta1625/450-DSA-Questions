// Probelm Link: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    int find(vector<int> parent,int i){
        if(parent[i]==i)
            return i;
        return find(parent,parent[i]);
    }
    void Union(vector<int>& parent,int x,int y){
        parent[x]=find(parent,y);
    }
public:
	bool isPossible(int N, vector<pair<int, int> >& v) {
	    // Code here
	   vector<int> parent(N,-1);
	   for(int i=0;i<N;i++){
	       parent[i]=i;
	   }
	   for(auto x: v){
	       int a=find(parent,x.first);
	       int b=find(parent,x.second);
	       
	       if(a==b){
	           return false;
	       }
	       
	       Union(parent,a,b);
	   }
	   return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}