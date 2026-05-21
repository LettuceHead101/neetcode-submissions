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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // create an array to hold the vectors of levels with values in them
        vector<vector<int>> levelarrays;
        
        // helper function that uses recursion
        // in order to add levels, and add elements in those levels
        helper(levelarrays, root, 0);

        return levelarrays;
    }

    void helper(vector<vector<int>>& levelarrays, TreeNode* root, int counter) {
        if(!root) return;

        // if this is the first time we're in this level create an array for it so its not empty
        if(counter == levelarrays.size()) {
            levelarrays.push_back(vector<int>());
        }

        // add the current nodes value to the current level in our array
        levelarrays[counter].push_back(root->val);

        // traverse the left and right, passing the next level so incrementing our counter
        helper(levelarrays, root->left, counter + 1);
        helper(levelarrays, root->right, counter + 1);
    }
};
