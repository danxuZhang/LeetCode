/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> us;

        for (int num : nums) {
            if (us.count(num) != 0) 
                return true;
            us.insert(num);
        }

        return false;
    }
};
// @lc code=end

