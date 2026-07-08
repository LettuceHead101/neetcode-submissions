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
    unordered_map<TreeNode*, int> cache;
public:
    int rob(TreeNode* root) {
        cache[nullptr] = 0;
        return dfs(root);
    }

    int dfs(TreeNode* node){
        if(cache.find(node) != cache.end()){
            return cache[node];
        }

        int res = node->val;
        if (node->left) {
            res += rob(node->left->left) + rob(node->left->right);
        }
        if (node->right) {
            res += rob(node->right->left) + rob(node->right->right);
        }

        res = max(res, rob(node->left) + rob(node->right));
        cache[node] = res;
        return res;
    }
};
