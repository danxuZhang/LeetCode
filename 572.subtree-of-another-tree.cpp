/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 */

// @lc code=start
class Solution {

    void serialize(TreeNode *root, string &res) {
        if (root == nullptr) {
            res += "$";
            return;
        }

        res += "#";
        res += to_string(root->val);
        serialize(root->left, res);
        serialize(root->right, res);
    }

  public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        string root_str = "";
        serialize(root, root_str);

        string sub_str = "";
        serialize(subRoot, sub_str);

        return (root_str.find(sub_str) != string::npos);
    }
};
// @lc code=end
