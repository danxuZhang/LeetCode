/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
  public:
    bool isPalindrome(string s) {
        string t = "";
        for (char ch : s) {
            if (isalnum(ch)) {
                t += tolower(ch);
            }
        }

        int left = 0, right = t.size() - 1;
        while (left < right) {
            if (t[left] != t[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};
// @lc code=end
