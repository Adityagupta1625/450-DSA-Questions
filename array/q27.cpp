// Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

// Note: The answer always exists. It is guaranteed that x doesn't exceed the summation of a[i] (from 1 to N).

// Example 1:

// Input:
// A[] = {1, 4, 45, 6, 0, 19}
// x  =  51
// Output: 3
// Explanation:
// Minimum length subarray is 
// {4, 45, 6}

// question link: https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1#

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here
        int start=0,end=0;
        int curr_sum=0;
        int min_len=n+1;
        while(end<n){
            while(curr_sum<=x && end<n){
                curr_sum+=arr[end++];
            }
            while(curr_sum>x && start<n){
                if(end-start<min_len){
                    min_len=end-start;
                }
                curr_sum-=arr[start++];
            }
         }
        return min_len;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
} 