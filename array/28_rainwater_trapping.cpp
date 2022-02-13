// Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 
// Example 1:

// Input:
// N = 6
// arr[] = {3,0,0,2,0,4}
// Output:
// 10

// Probelm link: https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater( int arr[], int n){
        // code here
        int left[n],right[n];

        right[n-1]=arr[n-1];
        for( int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],arr[i]);
        }
        left[0]=arr[0];
        for( int i=1;i<n;i++){
            left[i]=max(left[i-1],arr[i]);
        }
        int total=0;
        for(int j=0;j<n;j++){
            total+=min(left[j],right[j])-arr[j];
        }
        return total;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
} 