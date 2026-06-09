class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // Return the max of robbing (first to second-to-last) OR (second to last)
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

private:
    // Standard House Robber I logic
    int robRange(vector<int>& nums, int start, int end) {
        int rob1 = 0; // Represents max loot up to the house before the previous (i-2)
        int rob2 = 0; // Represents max loot up to the previous house (i-1)
        
        for (int i = start; i <= end; ++i) {
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        
        return rob2;
    }
};