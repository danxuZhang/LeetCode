/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> res;

        if (matrix.size() == 0) {
            return res;
        }

        int row_begin = 0;
        int row_end = matrix.size() - 1;
        int col_begin = 0;
        int col_end = matrix[0].size() - 1;

        while (row_begin <= row_end && col_begin <= col_end) {
            // traverse from left to right
            for (int i = col_begin; i <= col_end; ++i) {
                res.push_back(matrix[row_begin][i]);
            }
            ++row_begin;

            // traverse from top to bottom
            for (int i = row_begin; i <= row_end; ++i) {
                res.push_back(matrix[i][col_end]);
            }
            --col_end;

            // traverse from right to left
            if (row_begin <= row_end) {
                for (int i = col_end; i >= col_begin; --i) {
                    res.push_back(matrix[row_end][i]);
                }
            --row_end;
            }

            // traverse from bottom to top
            if (col_begin <= col_end) {
                for (int i = row_end; i >= row_begin; --i) {
                    res.push_back(matrix[i][col_begin]);
                }
            }
            ++col_begin;
        }

        return res;
    }
};
// @lc code=end

