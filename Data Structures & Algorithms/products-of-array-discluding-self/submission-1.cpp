class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        vector<int> lp(n, 1);

        for(int i = 1; i < n; i++) {
            l *= nums[i-1];
            lp[i] *= l; 
        }

        int r = 1;
        for(int i = n - 1; i >= 0; i--) {
            lp[i] *= r;
            r *= nums[i];
        }

        return lp;
    }
};
