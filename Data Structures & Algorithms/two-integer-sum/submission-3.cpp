class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seenNumbers;

        for(int i = 0; i < nums.size(); i++) {
            if(seenNumbers.find(target - nums[i]) != seenNumbers.end()) {
                return {seenNumbers[target - nums[i]], i};
            }

            seenNumbers.insert({nums[i], i});
        }

        return {};
    }
};
