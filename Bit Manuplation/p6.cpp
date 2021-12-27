// Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers.

// Example 1:

// Input: 
// N = 2
// arr[] = {1, 2, 3, 2, 1, 4}
// Output:
// 3 4 
// Explanation:
// 3 and 4 occur exactly once.
// Probelm link: https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> arr) 
    {
        // Code here.
        vector<int> v;
        int n=arr.size();
        int Xor=arr[0];
        for(int i=1;i<n;i++){
            Xor=Xor^arr[i];
        }
        int x=0,y=0;
        int right=Xor & ~(Xor-1);
        for(int i=0;i<n;i++){
            if(right & arr[i])
                x=x^arr[i];
            else
                y=y^arr[i];
        }
        v.push_back(x);
        v.push_back(y);
        sort(v.begin(),v.end());
        return v;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
} 