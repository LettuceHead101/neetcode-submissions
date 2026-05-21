class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftproduct(n, 1);
        vector<int> rightproduct(n, 1);

        int leftsum = 1;
        for(int i = 1; i < n; i++) {
            leftsum *= nums[i - 1];
            leftproduct[i] = leftsum;
        }

        int rightsum = 1;
        for(int i = n - 2; i >= 0; i--) {
            rightsum *= nums[i + 1];
            rightproduct[i] = rightsum;
        }

        vector<int> result(n, 1);
        for(int i = 0; i < n; i++) {
            result[i] = leftproduct[i] * rightproduct[i];
        }

        return result;
    }
};
