/*
 * @lc app=leetcode id=1498 lang=cpp
 *
 * [1498] Number of Subsequences That Satisfy the Given Sum Condition
 */

// @lc code=start
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int res = 0, n = nums.size(), mod = 1e9 + 7;
        std::vector<int> pows(n, 1);
        for (int i = 1; i < n; ++i) {
            pows[i] = 2 * pows[i-1] % mod;
        }

        int left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                --right;
            } else {
                res = (res + pows[right - left]) % mod;
                ++left;
            }
        }

        return res;
    }
};
// @lc code=end

