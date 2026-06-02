class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        vector<bool> pick(nums.size(), false);
        backtrack(current, nums, pick);

        return result;
    }

    void backtrack(vector<int>& current, vector<int>& nums,vector<bool>& pick) {
        if(current.size() == nums.size()){
            result.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(pick[i] == false) {
                pick[i] = true;
                current.push_back(nums[i]);
                
                backtrack(current, nums, pick);
                
                current.pop_back();
                pick[i] = false;
            }
        }
    }
};
