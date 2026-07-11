class Solution {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> flag(nums.size(), false);
        dfs(result, curr, nums, flag);

        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int> curr, vector<int>& nums, vector<bool>& flag){
        if(curr.size() == nums.size()){
            result.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!flag[i]){
                curr.push_back(nums[i]);
                flag[i] = true;
                dfs(result, curr, nums, flag);

                flag[i] = false;
                curr.pop_back();
            }
        }
    }
};
