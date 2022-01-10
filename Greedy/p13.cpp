// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

// Example 1:

// Input:
// N = 8, M = 5
// A = {3, 4, 1, 9, 56, 7, 9, 12}
// Output: 6
// Explanation: The minimum difference between 
// maximum chocolates and minimum chocolates 
// is 9 - 3 = 6 by choosing following M packets :
// {3, 4, 9, 7, 9}
// Probelm Link: https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    
      if (m == 0 || n == 0)
         return 0;
         
      if (n < m)
          return -1;
     
      sort(a.begin(),a.end());
      long long int min_diff = INT_MAX;
 

 
        for (int i = 0; i + m - 1 < n; i++) {
            long long int diff = a[i + m - 1] - a[i];
            if (diff < min_diff)
                min_diff = diff;
        }
        return min_diff;
    }    
};

// { Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}