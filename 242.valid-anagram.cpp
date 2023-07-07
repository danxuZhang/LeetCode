/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> counts;

        for (char ch : s)
            counts[ch]++;

        for (char ch : t)
            counts[ch]--;
        
        for (auto count : counts) 
            if (count.second) return false;
        
        return true;
    }
};
// @lc code=end

