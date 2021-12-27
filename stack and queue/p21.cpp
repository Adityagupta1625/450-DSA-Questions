// Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of ‘k’ characters. The value of a string is defined as the sum of squares of the count of each distinct character.

// Example 1:

// Input: s = abccc, k = 1
// Output: 6
// Explaination:
// We remove c to get the value as 12 + 12 + 22
// Probelm Link: https://practice.geeksforgeeks.org/problems/game-with-string4100/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        int h[26]={0};
        for(int i=0;i<s.length();i++){
            h[s[i]-'a']++;
        }
        priority_queue<int> q;
        for(int i=0;i<26;i++){
            if(h[i]>0)
                q.push(h[i]);
        }
        while(k!=0){
            int x=q.top();
            x--;
            q.pop();
            q.push(x);
            k--;
        }
        int sum=0;
        while(!q.empty()){
            int d=q.top();
            sum+=d*d;
            q.pop();
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}