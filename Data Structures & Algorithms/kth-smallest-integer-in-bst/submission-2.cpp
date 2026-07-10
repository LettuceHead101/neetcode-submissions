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
    vector<int> inorder;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root);
        return inorder[k-1];
    }

    void dfs(TreeNode* node){
        if(!node) return;

        dfs(node->left);
        inorder.push_back(node->val);
        dfs(node->right);
    }
};
