/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
    int find_pivot(vector<int> &nums) {
        if (nums.size() < 2) {
            return -1;
        }

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }

  public:
    int search(vector<int> &nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }

        const int pivot = find_pivot(nums);

        const int n = nums.size();
        int left    = 0;
        int right   = n - 1;
        while (left <= right) {
            int mid      = (right - left) / 2 + left;
            int real_mid = (mid + pivot) % n;
            if (nums[real_mid] == target) {
                return real_mid;
            } else if (nums[real_mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
// @lc code=end
