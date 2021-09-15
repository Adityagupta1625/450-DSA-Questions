// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
// Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

// Example 1:

// Input:
// str1 = aab
// str2 = xxy
// Output: 1
// Explanation: There are two different
// charactersin aab and xxy, i.e a and b
// Probelm link: https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#

// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int m1[MAX_CHARS]={0},m2[MAX_CHARS]={0};
        string s1,s2;
        for(int i=0;i<str1.length();i++){
            m1[str1[i]-'a']++;
        }
        for(int i=0;i<str2.length();i++){
            m2[str2[i]-'a']++;
        }
        int i=0,j=0;
        while(i<str1.length() && j<str2.length()){
            if(m1[str1[i]-'a']!=m2[str2[j]-'a']){
                return false;
            }
            i++;
            j++;
        }
        if(i!=str1.length() || j!=str2.length()){
            return false;
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}