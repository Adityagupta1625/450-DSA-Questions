// Given three integers  'A' denoting the first term of an arithmetic sequence , 'C' denoting the common difference of an arithmetic sequence and an integer 'B'. you need to tell whether 'B' exists in the arithmetic sequence or not.

// Example 1:

// Input: A = 1, B = 3, C = 2
// Output: 1
// Explaination: 3 is the second term of the 
// sequence starting with 1 and having a common 
// difference 2.
// Probelm link: https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1#
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int inSequence(int A, int B, int C){
        // code here
        long double n;
        long double diff=B-A;
      
        if(A==B)
            return 1;
        if(C==0)
            return 0;
        
        n =diff/C;
            
        if(n-1<0)
            return 0;
        if((ceil)(n-1)==(floor)(n-1))
            return 1;
        else
            return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
} 