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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case 1: Both nodes are null. They match perfectly here.
        if (p == nullptr && q == nullptr) {
            return true;
        }
        
        // Base case 2: One node is null but the other isn't. They don't match.
        if (p == nullptr || q == nullptr) {
            return false;
        }
        
        // Base case 3: Both nodes exist, but their values are different.
        if (p->val != q->val) {
            return false;
        }

        // Recursive step: Both current nodes match. 
        // Now, check if their left subtrees AND right subtrees also match.
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};