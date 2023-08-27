/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }

        int max_profit = 0;
        int min_price = INT_MAX;

        for (int i = 0; i < prices.size(); ++i ) {
            min_price = min(min_price , prices[i]);
            max_profit = max(max_profit, prices[i]-min_price);
        }

        return max_profit;
    }
};
// @lc code=end
