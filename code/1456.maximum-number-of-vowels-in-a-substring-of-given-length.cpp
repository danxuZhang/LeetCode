/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution {
    bool is_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int vowels_max = 0;
        int vowels_cnt = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (is_vowel(s[i])) {
                ++vowels_cnt;
            }

            if (i >= k && is_vowel(s[i-k])) {
                --vowels_cnt;
            }

            vowels_max = std::max(vowels_max, vowels_cnt);
        }

        return vowels_max;
    }
};
// @lc code=end

