class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); i++){
            int difference = target - nums[i];
            if(seen.count(difference)){
                return {seen[difference], i};
            }
            seen.insert({nums[i], i});
        }

        return {-1, -1};
    }
};
