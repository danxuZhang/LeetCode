/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> mat(n, std::vector<int>(n));

        int row_begin = 0;
        int row_end = n-1;
        int col_begin = 0;
        int col_end = n-1;

        int p = 1;
        while (row_begin <= row_end && col_begin <= col_end) {
            // left to right
            for (int i = row_begin; i <= row_end; ++i) {
                mat[col_begin][i] = p++;
            }
            ++col_begin;

            // top to bottom
            for (int i = col_begin; i <= col_end; ++i) {
                mat[i][row_end] = p++;
            }
            --row_end;

            // right to left
            if (col_begin <= col_end) { 
                for (int i = row_end; i >= row_begin; --i) {
                    mat[col_end][i] = p++;
                }
            }
            --col_end;

            // bottom to top
            if (row_begin <= row_end) {
                for (int i = col_end; i >= col_begin; --i) {
                    mat[i][row_begin] = p++;
                }
            }
            ++row_begin;
        }

        return mat;
    }
};
// @lc code=end

