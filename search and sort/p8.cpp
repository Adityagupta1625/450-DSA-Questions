// Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

// Example 1:

// Input:
// N = 5, K = 3
// A[] = {0,0,2,1,1}
// Output: 0 0 1 2 $
// Explanation: Sum of 0, 0, 1, 2 is equal
// to K.
// Probelm link : https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> s;
        set<vector<int>> sett;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-3;i++){
            for(int j=i+1;j<arr.size()-2;j++){
                int l=j+1,h=arr.size()-1;
                while(l<h){
                    if(arr[i]+arr[j]+arr[l]+arr[h]==k){
                        
                        sett.insert({arr[i],arr[j],arr[l],arr[h]});
                        l++;
                        h--;
                    }
                    else if(arr[i]+arr[j]+arr[l]+arr[h]<k)
                        l++;
                    else
                        h--;
                }
            }
        }
        for (vector<int> v : sett) 
            s.push_back(v);
        return s;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} 

