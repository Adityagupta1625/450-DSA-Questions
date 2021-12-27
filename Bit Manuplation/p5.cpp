// Given a string S find all possible subsequences of the string in lexicographically-sorted order.

// Example 1:

// Input : str = "abc"
// Output: a ab abc ac b bc c
// Explanation : There are 7 substrings that 
// can be formed from abc.
// Probelm Link: https://practice.geeksforgeeks.org/problems/power-set4302/1#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n=s.length();
		    int l=pow(2,n);
		    int i=0;
		    vector<string> v;
		    while(i<l){
		       string str="";
		       for(int j=0;j<n;j++){
		           if(i& (1<<j)){
		               str=str+s[j];
		           }
		       }
		       if(str!="")
		        v.push_back(str);
		       i++;
		    }
		    sort(v.begin(),v.end());
		    return v;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
} 