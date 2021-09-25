// Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

// Example 1:

// Input:
// N = 5
// words[] = {act,god,cat,dog,tac}

// Output: 
// god dog
// act cat tac
// Explanation:
// There are 2 groups of
// anagrams "god", "dog" make group 1.
// "act", "cat", "tac" make group 2.

// probelm link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    
    vector<vector<string>>Anagrams(vector<string>& string_list) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < string_list.size(); i++)
        {

            string s = string_list[i];
            sort(s.begin(), s.end());
            m[s].push_back(string_list[i]);
        }
        vector<vector<string>> vec;
        for (auto x : m)
        {
            vec.push_back(x.second);
        }
        return vec;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}