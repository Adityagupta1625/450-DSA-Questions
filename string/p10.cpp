// Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

// Example 1:

// Input: N = 6
// arr = {1, 2, 3, 6, 5, 4}
// Output: {1, 2, 4, 3, 5, 6}
// Explaination: The next permutation of the 
// given array is {1, 2, 4, 3, 5, 6}.

// Probelm link: https://practice.geeksforgeeks.org/problems/next-permutation5226/1#
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
     
        int idx=-1;
        for(int i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                idx=i;
                break;
            }
        }
        if (idx==-1)
        {
            reverse(arr.begin(),arr.end());
           
        }
        else{
           
            int prev=idx;
            for (int i = idx+1; i < n; i++)
            {
                if (arr[i] > arr[idx - 1] && arr[prev]>=arr[i])
                {
                    prev=i;
                }
            }
            swap(arr[prev], arr[idx - 1]);
            reverse(arr.begin()+idx,arr.end());
            
        }
        return arr;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}