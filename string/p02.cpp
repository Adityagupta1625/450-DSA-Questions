// Given a string S, check if it is palindrome or not.

// Example 1:

// Input: S = "abba"
// Output: 1
// Explanation: S is a palindrome
// Probelm link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1#
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPlaindrome(string s)
	{
	    // Your code goes here
	    string orgstring=s;
	    int n=s.length();
        for (int i = 0; i < n / 2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }
	    if(s==orgstring){
	        return 1;
	    }
	    return 0;
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
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}