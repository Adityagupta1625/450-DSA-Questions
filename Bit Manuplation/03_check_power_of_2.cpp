// Given a non-negative integer N. The task is to check if N is a power of 2. More formally, check if N can be expressed as 2x for some x.

// Example 1:

// Input: N = 1Output: YESExplanation:1 is equal to 2 raised
// Probelm Link: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        int cnt=0;
        if(n==0)
             return false;
        while(n!=0){
            if(n&1==1)
                cnt++;
            if(cnt>1)
                return false;
            n=n>>1;
        }
        return true;
        // Your code here    
        
    }
};

// { Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}