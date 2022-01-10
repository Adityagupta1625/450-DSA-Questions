// You are given a string s of lower case english alphabets. You can choose any two characters in the string and replace all the occurences of the first character with the second character and replace all the occurences of the second character with the first character. Your aim is to find the lexicographically smallest string that can be obtained by doing this operation at most once.

// Example 1:

// Input:
// A = "ccad"
// Output: "aacd"
// Explanation:
// In ccad, we choose ‘a’ and ‘c’ and after 
// doing the replacement operation once we get, 
// aacd and this is the lexicographically
// smallest string possible.
// Probelm Link: https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1#

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string s){
        // Code Here
        int h[26]={0};
        int n=s.length();
        for(int i=0;i<n;i++){
            h[s[i]-'a']++;
        }
        string ans;
        char ch,c;
        int found=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<(s[i]-'a');j++){
                if(h[j]>=1){
                    found=1;
                    c=s[i];
                    ch=(char)(j+97);
                    break;
                }
            }
            if(found){
                break;
            }
            h[s[i]-'a']=0;
        }
        
        if(!found)
            return s;
        else{
            for(int i=0;i<n;i++){
                if(s[i]==ch)
                    ans=ans+c;
                else if(s[i]==c)
                    ans=ans+ch;
                else
                    ans=ans+s[i];
            }
            
        }
        return ans;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}