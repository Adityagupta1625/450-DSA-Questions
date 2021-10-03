// Given an array arr[] of distinct integers of size N and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.


// Example 1:


// Input: N = 4, sum = 2
// arr[] = {-2, 0, 1, 3}
// Output:  2
// Explanation: Below are triplets with 
// sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
// Probelm link: https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1#
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	    long long ans=0;
	    sort(arr,arr+n);
	    for(int i=0;i<n-2;i++){
	        int j=i+1,k=n-1;
	        while(j<k){
	            if(arr[i]+arr[j]+arr[k]>=sum){
	                k--;
	            }
	            else if(arr[i]+arr[j]+arr[k]<sum){
	               ans=ans+(k-j);
	               j++;
	            }
	           
                	           
	        }
	    }
	    return ans;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}