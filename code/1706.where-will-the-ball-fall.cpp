/*
 * @lc app=leetcode id=1706 lang=cpp
 *
 * [1706] Where Will the Ball Fall
 */

// @lc code=start
class Solution {
private:
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<int> res(n);

        for (int i = 0; i < n; ++i) {
            int pos_x = i;
            int new_x = 0;
            for (int j = 0; j < m; ++j) {
                new_x = pos_x + grid[j][pos_x];
                if (new_x < 0 || new_x >= n || grid[j][pos_x] != grid[j][new_x]) {
                    pos_x = -1;
                    break;
                }
                pos_x = new_x;
            }
            res[i] = pos_x;
        }

        return res;
    }
};
// @lc code=end

