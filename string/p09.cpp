// Given an expression string x. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.
// For example, the function should return 'true' for exp = “[()]{}{[()()]()}” and 'false' for exp = “[(])”.

// Example 1:

// Input:
// {([])}
// Output: 
// true
// Explanation: 
// { ( [ ] ) }. Same colored brackets can form 
// balaced pairs, with 0 number of 
// unbalanced bracket.

// Probelm link: https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1#
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    int ismatching(char exp,char e){
        if(exp=='{' && e=='}'){
            return 1;
        }
        if(exp=='(' && e==')'){
            return 1;
        }
        if(exp=='[' && e==']'){
            return 1;
        }
        return 0;
    }
    bool ispar(string x)
    {
        // Your code here
        stack <char> st;
        for(int i=0;i<x.length();i++){
            if(x[i]=='{' || x[i]=='(' || x[i]=='['){
                st.push(x[i]);
            }
            else if(x[i]=='}' || x[i]==')' || x[i]==']'){
                if(st.empty()){
                    return false;
                }
                char exp=st.top();
                if(!ismatching(exp,x[i])){
                    return false;
                }
                
                st.pop();
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
    
};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
} 