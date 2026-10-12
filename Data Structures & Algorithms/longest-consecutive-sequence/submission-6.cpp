class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        int i = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());


        while(i < nums.size()) {
            if(numSet.find(nums[i] - 1) != numSet.end()){
                i++;
                continue;
            } else {
                int counter = 1;
                int num = nums[i] + 1;
                while(numSet.find(num) != numSet.end()){
                    counter++;
                    num++;
                }
                result = max(result, counter);
                i++;
            }
        }

        return result;
    }
};
