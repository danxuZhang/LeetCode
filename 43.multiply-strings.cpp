/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.length();
        int n = num2.length();
        vector<int> positions(m+n, 0);

        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >=0; --j) {
                int product = ((int) num1[i] - '0') * ((int) num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = product + positions[p2];

                positions[p1] += sum / 10;
                positions[p2] = sum % 10;
            }
        }

        std::string res = "";
        for (int i = 0; i < positions.size(); ++i) {
            if (res.length() == 0 && positions[i] == 0) {
                continue;
            }
            res += std::to_string(positions[i]);
        }
        return res == "" ? "0" : res;
    }
};
// @lc code=end

