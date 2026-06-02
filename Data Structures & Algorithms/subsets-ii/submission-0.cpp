class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> current;
        dfs(current, nums, 0);

        return result;
    }

    void dfs(vector<int>& current, vector<int>& nums, int i) {
        if(i ==  nums.size()) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[i]);
        dfs(current, nums, i+1);

        current.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }

        dfs(current, nums, i+1);
    }
};
