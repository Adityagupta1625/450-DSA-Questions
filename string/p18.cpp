// You are given a string S of 2N characters consisting of N ‘[‘ brackets and N ‘]’ brackets. A string is considered balanced if it can be represented in the for S2[S1] where S1 and S2 are balanced strings. We can make an unbalanced string balanced by swapping adjacent characters. Calculate the minimum number of swaps necessary to make a string balanced.
// Note - Strings S1 and S2 can be empty.

// Example 1:

// Input  : []][][
// Output : 2
// Explanation :
// First swap: Position 3 and 4
// [][]][
// Second swap: Position 5 and 6
// [][][]

// probelm link: https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1#

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here
        int cl = 0, op = 0, sw = 0,imbal=0;
        int n = S.length();
        int i = 0;
        while (i < n)
        {
            if (S[i] == '[')
            {
                op++;
                if(imbal>0){
                    sw+=imbal;
                    imbal--;
                }
                
            }
            else
            {
                cl++;
                imbal=cl-op;
            }
            i++;
        }
        return sw;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 