// Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

// Example 1:

// Input: s = "abab"
// Output: 2
// Explanation: "ab" is the longest proper prefix and suffix. 

// question link: https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n=s.length();
	    int lps[n];
	    int i=1,len=0,maxlen=0;
	    lps[0]=0;
	    while(i<n){
	        if(s[i]==s[len]){
	            len++;
	            lps[i]=len;
	            i++;
	
	        }
	        else{
	            if(len!=0){
	                len=lps[len-1];
	            }
	            else{
	                lps[i]=0;
	                i++;
	            }
	           
	        }
	      
	    }
	    return lps[n-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}