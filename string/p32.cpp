// Given a string S with repeated characters. The task is to rearrange characters in a string such that no two adjacent characters are the same. 
// Note: The string has only lowercase English alphabets and it can have multiple solutions. Return any one of them.

// Example 1:

// Input : 
// str = "geeksforgeeks"
// Output: 1
// Explanation:
// All the repeated characters of the 
// given string can be rearranged so 
// that no adjacent characters in the 
// string is equal. Any correct 
// rearrangement will show a output of 1.

// Probelm Link: https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1/#
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    struct key{
        int freq;
        char c;
        bool operator<(const key &k) const
        {
            return freq < k.freq;
        }
    };
    string rearrangeString(string str)
    {
        //code here
        int h[26] = {0};
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            h[str[i] - 'a']++;
        }
        string s = "";
        priority_queue<key> k;
        key prev{-1, '#'};
        for (int i = 0; i < 26; i++)
        {
            if(h[i]>str.length()/2){
                return "-1";
            }
            if (h[i] >= 1)
            {
                char ch = (char)(i+97);
                k.push(key{h[i], ch});
            }
            
        }

        while (!k.empty())
        {
            key x = k.top();
            k.pop();
            s = s + x.c;
            if (prev.freq > 0)
            {
                k.push(prev);
            }
            x.freq--;
            prev = x;
          
        }
        return s;
        
    }
    
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}