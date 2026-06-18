class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int r = 0;
        int result = 0;
        int temp = 0;
        temp += nums[r];
        result = temp;
        r++;
        
        while(r < nums.size()) {
            if (nums[r] > nums[r - 1]) {
                temp += nums[r];
            } else {
                temp = nums[r];
            }
            r++;
            result = max(result, temp);
        }

        return result;
    }
};