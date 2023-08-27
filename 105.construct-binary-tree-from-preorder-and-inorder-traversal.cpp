/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    int preorder_index = 0;
    unordered_map<int, int> inorder_indexes;

    TreeNode *array2tree(vector<int> &preorder, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int val = preorder[preorder_index];
        preorder_index++;

        TreeNode *root = new TreeNode(val);

        root->left  = array2tree(preorder, left, inorder_indexes[val] - 1);
        root->right = array2tree(preorder, inorder_indexes[val] + 1, right);
        return root;
    }

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        preorder_index = 0;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_indexes.insert({inorder[i], i});
        }
        return array2tree(preorder, 0, preorder.size() - 1);
    }
};
// @lc code=end
