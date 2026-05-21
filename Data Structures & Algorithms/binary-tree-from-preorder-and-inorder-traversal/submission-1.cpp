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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() || inorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder[0]);

        auto idx = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        vector<int> left_Preorder(preorder.begin() + 1, preorder.begin() + idx + 1);

        vector<int> right_Preorder(preorder.begin() + idx + 1, preorder.end());

        vector<int> left_Inorder(inorder.begin(), inorder.begin() + idx);
        
        vector<int> right_Inorder(inorder.begin() + idx + 1, inorder.end());

        root->left = buildTree(left_Preorder, left_Inorder);
        root->right = buildTree(right_Preorder, right_Inorder);

        return root;
    }
};
