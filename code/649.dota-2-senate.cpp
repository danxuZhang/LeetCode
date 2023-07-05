/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution {
public:
    string predictPartyVictory(string senate) {
        std::queue<int> q1, q2;
        int n = senate.length();
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                q1.push(i);
            else
                q2.push(i);
        }

        while (!q1.empty() && !q2.empty()) {
            int r_index = q1.front(), d_index = q2.front();
            q1.pop();
            q2.pop();
            if (r_index < d_index) {
                q1.push(r_index + n);
            } else {
                q2.push(d_index + n);
            }
        }

        return q1.size() > q2.size() ? "Radiant" : "Dire";
    }
};
// @lc code=end

