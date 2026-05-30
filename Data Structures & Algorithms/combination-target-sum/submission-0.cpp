class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        backtrack(nums, target, current, 0);
        return result;
    }


    void backtrack(vector<int>& nums, int target, vector<int>& current, int i) {
        // if we reach our target this is a solution
        if (target == 0) {
            result.push_back(current);
            return;
        }
        // if we go out of bounds we should return, this is not a valid solution set
        if(target < 0 || i >= nums.size()) {
            return;
        }

        // explore pushing this item to our list again
        current.push_back(nums[i]);
        backtrack(nums, target - nums[i], current, i);

        // explore not pushing this item to our list again
        current.pop_back();
        backtrack(nums, target, current, i + 1);

    }
};
