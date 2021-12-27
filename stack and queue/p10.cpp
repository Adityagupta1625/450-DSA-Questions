// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

// Example 1:

// Input:
// N = 7
// arr[] = {6,2,5,4,5,1,6}
// Output: 12
// Probelm Link: https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1#

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long int> left,right;
        stack<long long int> s;
            int i=0;
            while(i<n){
                if(s.empty()){
                    left.push_back(0);
                    s.push(i);
                    i++;
                }
                else{
                    int t=s.top();
                    s.pop();
                    if(arr[t]<arr[i]){
                        left.push_back(t+1);
                        s.push(t);
                        s.push(i);
                        i++;
                    }
                    
                }
               
            }
        while(!s.empty()){
            s.pop();
        }
        i=n-1;
            while(i>=0){
                if(s.empty()){
                    right.push_back(n-1);
                    s.push(i);
                    i--;
                }
                else{
                    int t=s.top();
                    s.pop();
                    if(arr[t]<arr[i]){
                        right.push_back(t-1);
                        s.push(t);
                        s.push(i);
                        i--;
                    }
                    
                }
               
            }
        reverse(right.begin(),right.end());
        long long int area=0;
        for(int i=0;i<n;i++){
            area=max(area,(right[i]-left[i]+1)*arr[i]);
        }
        return area;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}