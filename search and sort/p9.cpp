// Given two sorted arrays arr1[] of size N and arr2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

// Example 1:

// Input:
// N = 4, M = 5
// arr1[] = {1, 3, 5, 7}
// arr2[] = {0, 2, 6, 8, 9}
// Output: 0 1 2 3 5 6 7 8 9
// Explanation: Since you can't use any 
// extra space, modify the given arrays
// to form 
// arr1[] = {0, 1, 2, 3}
// arr2[] = {5, 6, 7, 8, 9}

// Probelm link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
    
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    int i=0,j=0,k=n-1;
	    while(i<=k && j<m){
	        if(arr1[i]<arr2[j]){
	            i++;
	        }
	        else{
	            swap(arr1[k],arr2[j]);
	            k--;
	            j++;
	        }
	    }
	    sort(arr1,arr1+n);
	    sort(arr2,arr2+m);
	}
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}