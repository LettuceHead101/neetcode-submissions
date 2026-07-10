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
    TreeNode* answer = nullptr;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        int rootVal = root->val;
        int pVal = p->val;
        int qVal = q->val;

        if((rootVal >= pVal && rootVal <= qVal) || (rootVal <= pVal && rootVal >= qVal)){
            return root;
        }

        if(rootVal >= pVal && rootVal >= qVal){
            answer = lowestCommonAncestor(root->left, p, q);
        }

        if(rootVal <= pVal && rootVal <= qVal){
            answer = lowestCommonAncestor(root->right, p, q);
        }

        return answer;
    }
};
