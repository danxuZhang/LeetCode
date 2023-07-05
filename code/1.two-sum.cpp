/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;  // {target-num, num_index}

        for (int i = 0; i < nums.size(); ++i) {
            if (umap.find(nums[i]) != umap.end()) {
                return {umap[nums[i]], i};
            } else {
                umap[target-nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};
// @lc code=end

