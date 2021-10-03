// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

// Example 1:

// Input:
// n = 6
// arr[] = {0,0,5,5,0,0}
// Output: 6
// Explanation: The 6 subarrays are 
// [0], [0], [0], [0], [0,0], and [0,0].
// Probelm link: https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#
#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<ll, ll> m;
        ll sum = 0;
        ll count = 0;
        
        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];
            if (sum==0)
                count++;
            
            count+=m[sum];    
            m[sum]++;
        }
        
        
        return count;
        }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
} 