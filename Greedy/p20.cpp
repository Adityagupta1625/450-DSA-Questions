// The task is to find the smallest number with given sum of digits as S and number of digits as D.
// Example 1:

// Input:
// S = 9 
// D = 2
// Output:
// 18
// Explanation:
// 18 is the smallest number
// possible with sum = 9
// and total digits = 2.
// Probelm Link: https://practice.geeksforgeeks.org/problems/smallest-number5829/1#

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(D*9<S)
            return "-1";
        string ans;
        for(int i=D;i>0;i--){
            if(S>9){
                ans.push_back('9');
                S=S-9;
                
            }
            else if(S==1)
                ans.push_back('0');
            else{
                ans.push_back((char)((S-1)+'0'));
                S=1;
            }
                
        }
        reverse(ans.begin(),ans.end());
        int h=ans[0]-'0';
        int r=h+S;
        ans[0]=(char)(r+'0');
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
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 