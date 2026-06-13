class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Base case: If ANY array is empty, there is no tree to build return nullptr to represent end of leaf
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }

        // 1. The first element of preorder is always the root
        int root_val = preorder[0];
        TreeNode* root = new TreeNode(root_val);  // we never create any other TreeNode* variable

        // 2. Find the root inside the inorder array (No hashmap, simple search)
        int mid = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root_val) {
                mid = i;
                break;
            }
        }
        // {0 + 1, 0+1+mid] the 0+1 part skips curr root and the 0+1+mid goes one past everything in its left subtree since initilization bounds is {x,y]
        // our left preorder will have everything that is not part of its right child's subtree and itself (verified)
        vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + mid);
        // this will push {0, mid]  (verified)
        vector<int> left_inorder(inorder.begin(), inorder.begin() + mid);

        // everything that left_preorder did not use goes to the right_preorder
        // {0+1+mid, right_preorder.size()] , the 0+1+mid part skips everything to the left of root and also root. the right_preorder.size() begins at right child all the way to end of vector
        vector<int> right_preorder(preorder.begin() + 1 + mid, preorder.end());
        // Right inorder: take everything after the 'mid' pivot
        vector<int> right_inorder(inorder.begin() + mid + 1, inorder.end());

        // important: notice left_inorder and right_inorder did NOT take the item at inorder[mid], so this root is ignored
        //similarly left_inorder and right_inorder did not take the index where inorder[mid] would be

        // 5. Recursively build the children using the newly sliced arrays
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);

        return root;
    }
};