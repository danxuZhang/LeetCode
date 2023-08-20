/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set;

        for (int num : nums) {
            set.insert(num);
        }

        int longest_streak = 0;

        for (int num : set) {
            // if the previous number doest not exist
            if (set.find(num - 1) == set.end()) {
                int current_num    = num;
                int current_streak = 1;

                while (set.find(current_num + 1) != set.end()) {
                    current_num++;
                    current_streak++;
                }

                longest_streak = max(longest_streak, current_streak);
            }
        }

        return longest_streak;
    }
};
// @lc code=end
