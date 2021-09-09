// Given a string S. The task is to print all permutations of a given string.

// Example 1:

// Input: ABC
// Output:
// ABC ACB BAC BCA CAB CBA
// Explanation:
// Given string ABC has permutations in 6 
// forms as ABC, ACB, BAC, BCA, CAB and CBA .

// question link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    vector<string> str;
	    void permute(string s, int k)
        {
            int n = s.length();
            static char res[5];
            static int visted[5] = {0};
            int i = 0;
            if (s[k] == '\0')
            {
                res[k] = '\0';
                string s;
                for (int j = 0; res[j] != '\0'; j++)
                {
                    s = s + res[j];
                }
    
                str.push_back(s);
            }
            else
            {
                for (i = 0; i < n; i++)
                {
                    if (visted[i] == 0)
                    {
                        visted[i] = 1;
                        res[k] = s[i];
                        permute(s, k + 1);
                        visted[i] = 0;
                    }
                }
            }
        }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    sort(s.begin(),s.end());
		    permute(s,0);
		    return str;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}