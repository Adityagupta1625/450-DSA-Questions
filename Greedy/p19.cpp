// There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

// Example 1:

// Input:
// n = 4
// arr[] = {4, 3, 2, 6}
// Output: 
// 29
// Probelm Link: https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long int, vector<long long int>, greater<long long int> > q;
        
        for(int i=0;i<n;i++)
            q.push(arr[i]);
            
        long long a,b;
        long long sum=0;
        while(q.size()>1){
            a=q.top();
            q.pop();
            b=q.top();
            q.pop();
            sum+=(a+b);
            q.push(a+b);
        }
        
        return sum;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}