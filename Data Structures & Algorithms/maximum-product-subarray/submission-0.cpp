class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int maxproduct = nums[0];
        // int minproduct = nums[0];
        int result = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            int current = 1;
            for(int j = i; j < nums.size(); j++) {
                current *= nums[j];
                if(current > result) result = current;
            }
        }

        return result;
    }
};
