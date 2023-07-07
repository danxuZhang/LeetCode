/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> unique_nums1;
        std::unordered_set<int> unique_nums2;

        for (auto num : nums1) {
            unique_nums1.insert(num);
        }

        for (auto num : nums2) {
            unique_nums2.insert(num);
        }

        std::vector<int> only_in_1, only_in_2;

        for (auto num : unique_nums1) {
            if (unique_nums2.count(num) == 0) {
                only_in_1.push_back(num);
            }
        }
        for (auto num : unique_nums2) {
            if (unique_nums1.count(num) == 0) {
                only_in_2.push_back(num);
            }
        }

        return {only_in_1, only_in_2};
    }
};
// @lc code=end

