// Given a sequence of strings, the task is to find out the second most repeated (or frequent) string in the given sequence.

// Note: No two strings are the second most repeated, there will be always a single string.

// Example 1:
// Input:
// N = 6
// arr[] = {aaa, bbb, ccc, bbb, aaa, aaa}
// Output: bbb

// Explanation: "bbb" is the second most 
// occurring string with frequency 2.
#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int maxi=0;
        for (auto x : m){
            int val=x.second;
             maxi=max(maxi,val);
        }
        int a=0;
        string f;
        for(auto x: m){
            int val=x.second;
            if(a<val && val<maxi){
                a=x.second;
                
            }
        }
        for(auto x: m){
            int val=x.second;
            if(a==val){
                f=x.first;
            }
        }
        return f;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}