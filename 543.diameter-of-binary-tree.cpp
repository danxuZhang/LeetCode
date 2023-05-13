/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
    int max_val = 0;
    int get_depth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_depth = get_depth(root->left);
        int right_depth = get_depth(root->right);

        max_val = std::max(left_depth + right_depth, max_val);

        return std::max(left_depth, right_depth) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        get_depth(root);
        
        return max_val;
    }
};
// @lc code=end

