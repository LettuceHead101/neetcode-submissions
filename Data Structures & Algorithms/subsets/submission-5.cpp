class Solution {
public:
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        dfs(result, curr, nums, 0);

        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int> curr, vector<int>& nums, int i){
        if(i == nums.size()){
            result.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(result, curr, nums, i+1);

        curr.pop_back();
        dfs(result, curr, nums, i+1);
    }
};
