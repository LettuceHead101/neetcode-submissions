class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(result, nums, curr, 0);

        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& nums, vector<int>& current, int i) {
        if(i == nums.size()) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[i]);
        dfs(result, nums, current, i+1);

        current.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

        dfs(result, nums, current, i+1);
    }
};
