/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        std::sort(strs.begin(), strs.end());

        std::string first = strs[0];
        std::string last = strs[strs.size()-1];

        std::string prefix = "";
        int i = 0;
        while (i < first.length() && i < last.length()) {
            if (first[i] == last[i]) {
                prefix += first[i];
                ++i;
            } else {
                return prefix;
            }
        }

        return prefix;
    }
};
// @lc code=end

