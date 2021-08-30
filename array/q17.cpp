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
        for (int i = 0; i < n - 1; i++)
        {
            /* code */
            for (int j = i + 1; j < n; j++)
            {

                if (j > i)
                {
                    /* code */
                    int sell = max(prices[i] - prices[j], prices[j] - prices[i]);
                    maxprof = max(maxprof, sell);
                }
            }
        }
        return maxprof;
    }
};
int main()
{
    Solution obj;
    vector<int> price = {2, 4, 1};
    cout << obj.maxProfit(price);

    return 0;
}
// [3,2,6,5,0,3]
// [7,1,5,3,6,4]