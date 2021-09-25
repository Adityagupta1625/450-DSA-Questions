// Given two strings S and P. Find the smallest window in the string S consisting of all the characters(including duplicates) of the string P.  Return "-1" in case there is no such window present. In case there are multiple such windows of same length, return the one with the least starting index. 

// Example 1:

// Input:
// S = "timetopractice"
// P = "toc"
// Output: 
// toprac
// Explanation: "toprac" is the smallest
// substring in which "toc" can be found.
// Probelm link: https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int h[256]={0};
        int n=s.length(),m=p.length();
        if(m>n){
            return "-1";
        }
        int min_len=INT_MAX,start=0,start_index=-1;
        for(int i=0;i<m;i++){
            h[p[i]]++;
        }
        int cnt=0,visit[256]={0};
        for(int i=0;i<n;i++){
            visit[s[i]]++;
            if(visit[s[i]]<=h[s[i]]){
                cnt++;
            }
            if(cnt==m){

                while(visit[s[start]]>h[s[start]] || h[s[start]]==0){
                    if(visit[s[start]]>h[s[start]]){
                        visit[s[start]]--;
                    }
                    start++;
                }
                int len=i-start+1;
                if(min_len>len){
                    min_len=len;
                    start_index=start;
                    
                }
            }
        }
        if(start_index==-1){
            return "-1";
        }
        return s.substr(start_index,min_len);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}