class Solution {
public:
    vector<vector<int>> ans;
    int subsetXORSum(vector<int>& nums) {
        int res = 0;
        int temp = 0;
        helper(nums,{},0);
        for(auto & v : ans){
            if(v.empty())continue;
            temp = v[0];
            for(int i = 1; i < v.size(); ++i){
                int x = v[i];
                temp ^= x;
            }
            res += temp;
        }
        return res;
    }

    void helper(vector<int>& nums, vector<int> temp,  int size){
        if(size == nums.size()){
            ans.push_back(temp);
        }
        if(size >= nums.size() )return;

        temp.push_back(nums[size]);
        helper(nums,temp,size+1);
        temp.pop_back();

        helper(nums,temp,size+1);
    }
};