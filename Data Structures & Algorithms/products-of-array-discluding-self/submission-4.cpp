class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftProducts(nums.size(), 1);
        vector<int> rightProducts(nums.size(), 1);
        int leftp = 1;
        int rightp = 1;
        for(int i = 1; i < nums.size(); i++) {
            leftp *= nums[i - 1];
            leftProducts[i] *= leftp;
        }

        for(int i = nums.size() - 2; i >= 0; i--) {
            rightp *= nums[i + 1];
            rightProducts[i] *= rightp * leftProducts[i];
        }

        rightProducts.back() *= leftProducts.back();

        return rightProducts;
    }
};
