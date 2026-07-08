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
    int totalSum = 0;
    TreeNode* convertBST(TreeNode* root) {
        totalSum = getSum(root);
        dfs(root);
        return root;
    }

    int getSum(TreeNode* node) {
        if(!node) return 0;
        return node->val + getSum(node->left) + getSum(node->right);
    }

    void dfs(TreeNode* node){
        if(!node) return;

        dfs(node->left);
        int val = node->val;
        node->val = totalSum;
        totalSum -= val;
        dfs(node->right);
    }
};