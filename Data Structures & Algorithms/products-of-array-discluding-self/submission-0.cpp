class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n,1);
        vector<int> rightProduct(n,1);

        int runningproduct = 1;
        // get the left products
        for(int i = 1; i < n; i++) {
            runningproduct *= nums[i-1];
            leftProduct[i] = runningproduct;
        }

        runningproduct = 1;
        // get the right products
        for(int i = n - 2; i >= 0; i--) {
            runningproduct *= nums[i+1];
            rightProduct[i] = runningproduct;
        }

        // multiply both products to get the solution
        for(int i = 0; i < n; i++) {
            nums[i] = leftProduct[i] * rightProduct[i];
        }

        return nums;
    }
};
