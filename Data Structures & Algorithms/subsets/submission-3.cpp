class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(result, {}, nums, 0);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int> current, vector<int>& nums, int i) {
        if(i == nums.size()){
            result.push_back(current);
            return;
        }

        current.push_back(nums[i]);
        dfs(result, current, nums, i+1);

        current.pop_back();
        dfs(result, current, nums, i+1);
    }
};
