class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> pick(nums.size(), false);
        dfs(nums, curr, pick);

        return result;
    }

    void dfs(vector<int>& nums, vector<int>& curr, vector<bool>& pick) {
        if(curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }

        for(int j = 0; j < nums.size(); j++) {
            if(pick[j] == false) {
                pick[j] = true;

                curr.push_back(nums[j]);
                dfs(nums, curr, pick);

                curr.pop_back();
                pick[j] = false;       
            }
        }

    }
};
