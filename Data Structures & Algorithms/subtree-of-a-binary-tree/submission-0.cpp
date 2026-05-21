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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Base case: if the main tree is empty, it can't contain a subtree
        if (!root) {
            return false;
        }
        
        // If the current nodes match and their subtrees are identical, we found it
        if (check(root, subRoot)) {
            return true;
        }

        // Otherwise, recursively check both the left and right children
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool check(TreeNode* node1, TreeNode* node2) {
        if(!node1 && !node2) {
            return true;
        }
        if((!node1 && node2) || (node1 && !node2) || (node1->val != node2->val)) {
            return false;
        }

        bool left = check(node1->left, node2->left);
        bool right = check(node1->right, node2->right);


        return (left && right);
    }
};
