// Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
// Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.


// Example 1:

// Input: n = 6 
// arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
// dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3
// Explanation: 
// Minimum 3 platforms are required to 
// safely arrive and depart all trains.
// Probelm Link: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,int>> v;
    	for(int i=0;i<n;i++) v.push_back({arr[i],dep[i]});
    	
    	sort(v.begin(),v.end());
    	
    	int platform=1;
    	priority_queue <int, vector<int>, greater<int> > pq;
    	pq.push(v[0].second);
    	for(int i=1;i<n;i++){
    	    if(pq.top()<v[i].first){
    	        pq.pop();
    	        pq.push(v[i].second);
    	    }
    	    else{
    	        platform++;
    	        pq.push(v[i].second);
    	    }
    	    
    	}
    	
    	return platform;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  