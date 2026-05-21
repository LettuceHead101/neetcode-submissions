class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> leftproduct(n, 1);
        vector<int> rightproduct(n, 1);

        int leftP = 1;
        for(int i = 1; i < n; i++) {
            leftP *= nums[i-1];
            leftproduct[i] = leftP;
        }

        int rightP = 1;
        for(int i = n - 2; i >= 0; i--) {
            rightP *= nums[i+1];
            rightproduct[i] = rightP * leftproduct[i];
        }

        rightproduct[n-1] *= leftproduct[n-1];
        
        return rightproduct;
    }
};
