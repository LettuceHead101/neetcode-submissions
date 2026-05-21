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
        if(preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[0]);

        // find the index of the root node
        auto mid = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();

        // grab the elements from the left tree into the new left subarray preordered
        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + mid + 1);

        // grab the elements from the right tree into the new right subarray preordered
        vector<int> rightPre(preorder.begin() + mid + 1, preorder.end());

        // grab the elements from the left inorder array to this one one
        vector<int> leftIn(inorder.begin(), inorder.begin() + mid);

        // grab the elements from the right inorder arary to this new one
        vector<int> rightIn(inorder.begin() + mid + 1, inorder.end());

        // recursively build the tree on the left side
        root->left = buildTree(leftPre, leftIn);

        // recursively build the tree on the right side
        root->right = buildTree(rightPre, rightIn);

        //return the node to continue building or return the inital node
        return root;
    }

};
