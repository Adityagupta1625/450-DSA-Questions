// Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

// Example 1:

// Input:
// nums = {2, 8, 5, 4}
// Output:
// 1
// Explaination:
// swap 8 with 4.
// Probelm link: https://practice.geeksforgeeks.org/problems/minimum-swaps/1#
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> vec;
	    for(int i=0;i<nums.size();i++)
	        vec.push_back(make_pair(nums[i],i));
	   
	    sort(vec.begin(),vec.end());
	    int ans=0;
	    for(int i=0;i<nums.size();i++){
	        if(i==vec[i].second)
	            continue;
	        else{
	            swap(vec[i].first,vec[vec[i].second].first);
	            swap(vec[i].second,vec[vec[i].second].second);
	        }
	        
	        if(i!=vec[i].second)
	            --i;
	       ans++;
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}