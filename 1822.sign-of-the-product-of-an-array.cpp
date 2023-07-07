/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

// @lc code=start
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt_pos = 0;
        int cnt_neg = 0;
        bool has_zero = false;

        for (auto num : nums) {
            if (num == 0) {
                return 0;
            } else if (num > 0) {
                ++cnt_pos;
            } else if (num < 0) {
                ++cnt_neg;
            }
        }

        return cnt_neg % 2 ? -1 : 1;
    }
};
// @lc code=end

