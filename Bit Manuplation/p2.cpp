// You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

// Example 1:

// Input: A = 10, B = 20
// Output: 4
// Explanation:
// A  = 01010
// B  = 10100
// As we can see, the bits of A that need 
// to be flipped are 01010. If we flip 
// these bits, we get 10100, which is B.
// probelm link:https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1#
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int n=a^b;
        int cnt=0;
        while(n!=0){
            if(n&1==1)
                cnt++;
            n=n>>1;
        }
        return cnt;
        // Your logic here
        
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
	int t;
	cin>>t;// input the testcases
	while(t--) //while testcases exist
	{
		int a,b;
		cin>>a>>b; //input a and b

        Solution ob;
		cout<<ob.countBitsFlip(a, b)<<endl;
	}
	return 0;
}