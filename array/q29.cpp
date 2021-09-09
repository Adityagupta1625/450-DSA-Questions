// Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.

// Example 1:

// Input : arr[ ] = {2, 1, 5, 6, 3} and K = 3
// Output : 1
// Explanation:
// To bring elements 2, 1, 3 together, swap element '5' with '3'
// such that final array will be- arr[] = {2, 1, 3, 6, 5}

// Probelm link: https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1#
#include <bits/stdc++.h>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    // Complet the function
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k){
            cnt++;
        }
    }
    int ans,bad=0;
    for(int i=0;i<cnt;i++){
        if(arr[i]>k){
            bad++;
        }
    }
    ans=bad;
    int i=0,j=cnt;
    while(j<n){
        if(arr[i]>k){
            --bad;
        }
        if(arr[j]>k){
            ++bad;
        }
        ans=min(ans,bad);
        i++;
        j++;
    }
    return ans; 
    
}