/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
  public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int left = 0, right = nums.size() - 1;
        if (nums[left] < nums[right]) {
            return nums[left];
        }

        while (left < right) {
            int mid = (right - left) / 2 + left;

            if (nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            if (nums[mid] < nums[left]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
// @lc code=end
