// Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.
 
// Example 1:

// Input: A = "aabc"
// Output: "a#bb"
// Explanation: For every character first non
// repeating character is as follow-
// "a" - first non-repeating character is 'a'
// "aa" - no non-repeating character so '#'
// "aab" - first non-repeating character is 'b'
// "aabc" - first non-repeating character is 'b'

// Probelm Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    int h[26]={0};
		    queue<char> q;
	        for(int i=0;i<A.length();i++){
	            h[A[i]-'a']++;
	            
	            if(h[A[i]-'a']==1)
	                q.push(A[i]);
	            
	            while(!q.empty() && h[q.front()-'a']!=1){
	                q.pop();
	            }
	            if(q.empty())
	                A[i]='#';
	            else
	                A[i]=q.front();
	                
	        }
	        return A;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}