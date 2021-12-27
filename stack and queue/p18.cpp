// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.
// Example 1:

// Input : 
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2

// Output : 
// -8 0 -6 -6

// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6

// Probelm link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long> v;
    queue<long long> q;
    for(int i=0;i<K;i++){
        
        if(A[i]<0)
            q.push(i);
    }
    for(int i=K;i<N;i++){
        if(!q.empty())
            v.push_back(A[q.front()]);
        else
            v.push_back(0);
            
        while(!q.empty() && q.front()<i-K+1)
            q.pop();
        
        if(A[i]<0)
            q.push(i);
        
    }
    if(!q.empty()){
        v.push_back(A[q.front()]);
        q.pop();
    }
    else{
        v.push_back(0);
    }
    return v;
                                                 
 }