/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        int left = 0, right = 0;
        while (right < prices.size()) {
            if (prices[right] > prices[left]) {
                ans = max(ans, prices[right] - prices[left]);
            } else {
                left = right;
            }

            ++right;
        }

        return ans;
    }
};
// @lc code=end

