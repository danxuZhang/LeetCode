/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int max_sum = INT_MIN;
    int gain_from_subtree(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left  = max(gain_from_subtree(root->left), 0);
        int right = max(gain_from_subtree(root->right), 0);

        max_sum = max(max_sum, left + right + root->val);

        return max(root->val + left, root->val + right);
    }

  public:
    int maxPathSum(TreeNode *root) {
        gain_from_subtree(root);
        return max_sum;
    }
};
// @lc code=end
