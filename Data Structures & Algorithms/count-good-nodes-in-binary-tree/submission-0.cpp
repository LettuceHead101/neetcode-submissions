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
    int goodNodes(TreeNode* root) {
        return helper(root, root->val);
    }

    int helper(TreeNode* root, int max) {
        if(!root) {
            return 0;
        }
        if(root->val >= max) {
            max = root->val;
            return helper(root->left, max) + helper(root->right, max) + 1;
        } else {
            return helper(root->left, max) + helper(root->right, max);
        }
    }
};
