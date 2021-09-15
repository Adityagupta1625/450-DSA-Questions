// Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

// Example 1:

// Input:
// s = V
// Output: 5
// Probelm link: https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1#

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int findval(char str){
            int val;
            if(str=='I'){
                val=1;
            }
            else if(str=='V'){
                val=5;
            }
            else if(str=='X'){
                val=10;
            }
            else if(str=='L'){
                val=50;
            }
            else if(str=='C'){
                 val=100;
            }
            else if(str=='D'){
                 val=500;
            }
            else if(str=='M'){
                 val=1000;
            }
            return val;
    }
    int romanToDecimal(string &str) {
        // code here
        int n=str.length();
        int i=0;
        int num=0;
        int val;
        while(i<n-1){
            
            if(findval(str[i])>=findval(str[i+1])){
                 num=num+findval(str[i]);
            }
            else{
                num=num-findval(str[i]);
            }
            i++;
        }
        num=num+findval(str[i]);
        return num;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}