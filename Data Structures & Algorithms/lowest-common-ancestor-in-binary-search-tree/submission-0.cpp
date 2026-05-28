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
private:
    TreeNode* answer = nullptr;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;


        int rootval = root->val;
        int pval = p->val;
        int qval = q->val;

        // does it split? then this is the lca
        if((rootval >= pval && rootval <= qval) || (rootval <= pval && rootval >= qval)) {
            return root;
        }

        // are they both to our right?
        if(rootval < pval && rootval < qval) {
            answer = lowestCommonAncestor(root->right, p, q);
        }

        // are they both to our left?
        if(rootval > pval && rootval > qval) {
            answer = lowestCommonAncestor(root->left, p, q);
        }

        return answer;
    }
};
