/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int count = 0;
    long long target;
    void dfs(TreeNode* root, long long curr_sum,std::unordered_map<long long , int>& pre_sum) {
        if (root == nullptr) {
            return ;
        }

        curr_sum += root->val;

        if (pre_sum.find(curr_sum - target) != pre_sum.end()) {
            count += pre_sum[curr_sum-target];
        }

        if (pre_sum.find(curr_sum) != pre_sum.end()) {
            ++pre_sum[curr_sum];
        } else {
            pre_sum.emplace(curr_sum, 1);
        }

        dfs(root->left, curr_sum, pre_sum);
        dfs(root->right, curr_sum, pre_sum);
        --pre_sum[curr_sum];
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        std::unordered_map<long long, int> pre_sum; // prefix sum : ways to get the sum
        pre_sum.emplace(0, 1);
        dfs(root, 0, pre_sum);
        return count;
    }
};
// @lc code=end

