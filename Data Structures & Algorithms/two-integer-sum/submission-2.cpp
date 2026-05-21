class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seenNums;
        for(int i = 0; i < nums.size(); i++) {
            if(seenNums.find(target - nums[i]) != seenNums.end()) return {seenNums[target - nums[i]], i};
            seenNums[nums[i]] = i;
        }

        return {-1, -1};
    }
};
