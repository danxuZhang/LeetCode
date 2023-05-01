/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start
class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0;
        int max = 999;
        int min = 1000001;

        for (auto num : salary) {
            sum += num;
            max = num > max ? num : max;
            min = num < min ? num : min;
        }

        sum -= max;
        sum -= min;
        return (double) sum / (salary.size()-2);
    }
};
// @lc code=end

