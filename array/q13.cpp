// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

// question link: https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> merged;
    
    for (auto interval: intervals)
    {
        /* code */
        if (merged.empty() || merged.back()[1]<interval[0] )
        {
            /* code */
            
            merged.push_back(interval);
        }
        else{
            merged.back()[1]=max(merged.back()[1],interval[1]);
        }
    }
    
    
    for (int i = 0; i < merged.size(); i++)
    {
        /* code */
        cout<<merged[i][0]<<" "<<merged[i][1]<<endl;
    }
    
   
    return 0;
}