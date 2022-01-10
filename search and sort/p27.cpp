// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

// The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

// Example 1:

// Input:
// n = 5
// k = 3
// arr[] = {5,10,30,20,15}
// Output: 35
// Explanation: The most optimal way will be:
// Painter 1 allocation : {5,10}
// Painter 2 allocation : {30}
// Painter 3 allocation : {20,15}
// Job will be done when all painters finish
// i.e. at time = max(5+10, 30, 20+15) = 35
// Probelm Link: https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1/#
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long check(int arr[],int n,long long int mid){
        long long sum=0,count=1;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum>mid){
                sum=arr[i];
                count++;
            }
            
        }
        return count;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long int mx=INT_MIN;
        long long int sum=0;
        for(int i=0;i<n;i++){
            mx=max(mx,(long long )arr[i]);
            sum+=arr[i];
        }
        long long int lo=mx,hi=sum;
        long long ans=0;
        while(lo<=hi){
            long long int m=(lo+hi)/2;
            
            long long int count=check(arr,n,m);
            if(count<=k){
                ans=m;
                hi=m-1;
            }
            else{
                lo=m+1;
            }
                
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
} 