class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            int tempsum = nums[i];
            maxsum = max(maxsum, tempsum);
            
            for(int j = i + 1; j < nums.size(); j++) {

                tempsum += nums[j];
                maxsum = max(maxsum, tempsum);
            }
        }

        return maxsum;
    }
};
