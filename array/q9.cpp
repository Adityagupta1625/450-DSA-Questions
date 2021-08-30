// Given an array arr[] denoting heights of N towers and a positive integer K, you have to modify the height of each tower either by increasing or decreasing them by K only once. After modifying, height should be a non-negative integer. 
// Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

// A slight modification of the problem can be found here.


// Example 1:

// Input:
// K = 2, N = 4
// Arr[] = {1, 5, 8, 10}

// Output:
// 5

// Explanation:
// The array can be modified as 
// {3, 3, 6, 8}. The difference between 
// the largest and the smallest is 8-3 = 5.

// Probelm Link: https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1

#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr,arr+n);
        
        int result=arr[n-1]-arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]>=k && arr[n-1]>=k){
                int maxEle=max(arr[i-1]+k,arr[n-1]-k);
                int minEle=min(arr[0]+k,arr[i]-k);
               
                result=min(result,(maxEle-minEle));
            }
        }
        return result;
    }
    
   
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[10000];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  