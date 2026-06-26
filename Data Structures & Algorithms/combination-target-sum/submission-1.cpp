class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        dfs(nums, curr, target, 0);
        return result;
    }

    void dfs(vector<int>& nums, vector<int> curr, int target, int i) {
        if(target == 0) {
            result.push_back(curr);
            return;
        }

        if(target < 0 || i >= nums.size()) {
            return;
        }

        curr.push_back(nums[i]);
        dfs(nums, curr, target-nums[i], i);

        curr.pop_back();
        dfs(nums, curr, target, i+1);
    }
};
