// Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.
 
// Example 1:

// Input:
// arr1[] = {2, 3, 6, 7, 9}
// arr2[] = {1, 4, 8, 10}
// k = 5
// Output:
// 6
// Explanation:
// The final sorted array would be -
// 1, 2, 3, 4, 6, 7, 8, 9, 10
// The 5th element of this array is 6.

// Probelm link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int search(int *arr1, int *arr2, int *end1, int *end2, int k){
        if(arr1==end1)
            return arr2[k];
        if(arr2==end2)
            return arr1[k];
            
        int mid1=(end1-arr1)/2;
        int mid2=(end2-arr2)/2;
        if(mid1+mid2<k){
            if(arr1[mid1]>arr2[mid2])
                return search(arr1,arr2+mid2+1,end1,end2,k-mid2-1);
            else
                return search(arr1+mid1+1,arr2,end1,end2,k-mid1-1);
        
        }
        else{
            if(arr1[mid1]>arr2[mid2])
                return search(arr1,arr2,arr1+mid1,end2,k);
            else
                return search(arr1,arr2,end1,arr2+mid2,k);
        }
    }
    int kthElement(int *arr1, int *arr2, int n, int m, int k)
    {
        return search(arr1,arr2,arr1+n,arr2+m,k-1);
        
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  