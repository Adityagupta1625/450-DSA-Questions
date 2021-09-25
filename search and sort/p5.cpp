// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Probelm link: https://leetcode.com/problems/search-in-rotated-sorted-array/
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l=0,h=arr.size()-1,m;
        int n=arr.size();
        if(n==1){
            if(arr[0]==target)
                return 0;
            return -1;
        }
        while(l<=h){
            m=(l+h)/2;
            if(arr[m]==target)
                return m;
            else if(arr[l]<=arr[m]){
                if(target>=arr[l] && target<=arr[m])
                    h=m-1;
                else
                    l=m+1;
            }
            else{
                if(target>=arr[m+1] && target<=arr[h])
                    l=m+1;
                else
                    h=m-1;
            }
        }
        return -1;
    }
};
int main()
{
 
return 0;
}