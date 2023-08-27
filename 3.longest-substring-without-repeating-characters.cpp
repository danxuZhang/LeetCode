/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count_map;

        int max_len = 0;
        int left = 0, right = 0;

        while (right < s.size()) {
            count_map[s[right]]++;
            while (count_map[s[right]] > 1) {
                count_map[s[left]]--;
                left++;
            }
            max_len = max(max_len, right-left+1);
            right++;
        }
        
        return max_len;
    }
};
// @lc code=end

