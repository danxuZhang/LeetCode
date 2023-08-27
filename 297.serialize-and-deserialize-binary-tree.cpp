/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void encode(TreeNode *root, ostringstream &out) {
        if (root == nullptr) {
            out << "N ";
            return;
        }

        out << to_string(root->val) << " ";

        encode(root->left, out);
        encode(root->right, out);
    }

    TreeNode *decode(istream &in) {
        string value = " ";
        in >> value;

        if (value == "N") {
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(value));
        root->left     = decode(in);
        root->right    = decode(in);

        return root;
    }

  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        ostringstream out;
        encode(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream in(data);
        return decode(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
