/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalancedX(TreeNode* root, int& height) {
        if (root == nullptr) {
            height = 0;
            return true;
        }

        int left_height, right_height;
        bool left_balance = isBalancedX(root->left, left_height);
        bool right_balance = isBalancedX(root->right, right_height);
        
        height = std::max(left_height, right_height) + 1;

        if (left_height < right_height - 1 || left_height > right_height + 1) {
            return false;
        }

        return left_balance && right_balance;
    }
public:
    bool isBalanced(TreeNode* root) {
        int dummy;
        return isBalancedX(root, dummy);
    }
};
// @lc code=end

