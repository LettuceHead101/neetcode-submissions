class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;

        dfs(result, curr, nums, target, 0);

        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int> curr, vector<int>& nums, int target, int i){
        if(target == 0){
            result.push_back(curr);
            return;
        }

        if(target < 0 || i >= nums.size()){
            return;
        }

        curr.push_back(nums[i]);
        dfs(result, curr, nums, target-nums[i], i);

        curr.pop_back();
        dfs(result, curr, nums, target, i+1);
    }
};
