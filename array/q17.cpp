// You are given an array prices where prices[i] is the price of a given stock on the ith day.You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5

// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// question link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprof = 0;
        int n = prices.size();
        int min_so_far = prices[0];
        for (int i = 0; i < n; i++)
        {
            /* code */
            min_so_far=min(min_so_far,prices[i]);
            int sell = prices[i] - min_so_far;
            maxprof = max(sell, maxprof);
        }
        return maxprof;
    }
};
int main()
{
    Solution obj;
    vector<int> price = {7,1,5,3,6,4};
    cout << obj.maxProfit(price);

    return 0;
}
// [3,2,6,5,0,3]
// [7,1,5,3,6,4]