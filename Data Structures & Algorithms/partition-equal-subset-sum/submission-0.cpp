class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // get the total sum of the array
        int totalSum = 0;
        for(int x: nums) {
            totalSum += x;
        }

        // cout << totalSum;
        // if the sum is odd, that means that no matter how we split the array
        // we cannot divide it into two sub arrays that are each half the size, so return false
        if(totalSum % 2 == 1) return false;

        
        return helper(nums, 0, totalSum/2);
    }

    bool helper(vector<int>& nums, int idx, int target) {
        // we exhausted options of current path
        if(idx == nums.size()) return false;

        // base case, is target = 0?
        if(target == 0) return true;

        // did we go over?
        if(target < 0) return false;

        // two options, choose to add the number, and make our target - nums[idx]
        // or we can not add it and move to the next number
        // either way incremenet idx to the next option
        return (helper(nums, idx + 1, target - nums[idx]) || helper(nums, idx + 1, target));
    }
};
