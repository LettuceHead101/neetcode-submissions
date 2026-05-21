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
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> in_vals(1,-1);
        inorder(root, in_vals);
        return in_vals[k];
    }

    void inorder(TreeNode* node, vector<int>& in_vals) {
        if(!node) return;

        inorder(node->left, in_vals);
        in_vals.push_back(node->val);
        inorder(node->right, in_vals);
    }
};
