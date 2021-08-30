// Given an array of positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

// Example 1:

// Input:
// 5
// 4 2 -3 1 6

// Output: 
// Yes

// Explanation: 
// 2, -3, 1 is the subarray 
// with sum 0.

// link for question: https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1#
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        unordered_set<int> s1;
    
        int prefixsum=0;
        for(int i=0;i<n;i++){
            prefixsum=prefixsum+arr[i];
            if(s1.find(prefixsum)!=s1.end() || prefixsum==0){
                return true;
            }
            
            else{
                s1.insert(prefixsum);
            }
        }
        return false;
        
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
} 