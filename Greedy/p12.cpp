// Given an array A of N integers. Your task is to write a program to find the maximum value of ∑arr[i]*i, where i = 0, 1, 2,…., n – 1.
// You are allowed to rearrange the elements of the array.
// Note: Since output could be large, hence module 109+7 and then print answer.


// Example 1:

// Input : Arr[] = {5, 3, 2, 4, 1}
// Output : 40
// Explanation:
// If we arrange the array as 1 2 3 4 5 then 
// we can see that the minimum index will multiply
// with minimum number and maximum index will 
// multiply with maximum number. 
// So 1*0+2*1+3*2+4*3+5*4=0+2+6+12+20 = 40 mod(109+7) = 40
// Probelm Link: https://practice.geeksforgeeks.org/problems/maximize-arrii-of-an-array0026/1#
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        long long sum=0;
        long long int mod=1e9+7;
        for(long long i=0;i<n;i++){
            sum=sum+(a[i]*i);
        }
        int ans=(int)(sum%mod);
        return ans;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}