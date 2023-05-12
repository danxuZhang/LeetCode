/*
 * @lc app=leetcode id=2140 lang=cpp
 *
 * [2140] Solving Questions With Brainpower
 */

// @lc code=start
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int n = questions.size();
        
        // dp[i]: max points if starts from question i
        // transition function: dp[i] = max(dp[i+1], points[i] + dp[i + brain_power[i] + 1])
        std::vector<long long> dp(n+1, 0);


        for (int i = n-1; i >= 0; --i) {
            if (i + questions[i][1] + 1 > n) {
                dp[i] = std::max(dp[i+1], (long long)questions[i][0]);
            } else {
                dp[i] = std::max(dp[i+1], (long long)questions[i][0] + dp[i + questions[i][1] + 1]);
            }
        }

        return dp[0];
    }
};
// @lc code=end

