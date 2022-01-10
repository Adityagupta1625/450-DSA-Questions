// Given an array of integers of size N and a number K., Your must modify array arr[] exactly K number of times. Here modify array means in each operation you can replace any array element either arr[i] by -arr[i] or -arr[i] by arr[i]. You need to perform this operation in such a way that after K operations, the sum of the array must be maximum.


// Example 1:

// Input:
// N = 5, K = 1
// arr[] = {1, 2, -3, 4, 5}
// Output:
// 15
// Explanation:
// We have k=1 so we can change -3 to 3 and
// sum all the elements to produce 15 as output.
// Probelm Link: https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        
        int i=0;
        while(i<k && a[i]<0 && i<n){
            a[i]=-a[i];
            i++;
        }
        int left=k-i;
        sort(a,a+n);
        if(left%2!=0)
            a[0]=-a[0];
         
       
        long long int sum=0;
        for(int j=0;j<n;j++){
            sum=sum+a[j];
        }
        return sum;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}