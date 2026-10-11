class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftp(n, 1);
        vector<int> rightp(n, 1);

        int lm = 1;
        for(int i = 1; i < n; ++i) {
            lm *= nums[i - 1];
            leftp[i] = lm;
        }

        rightp.back() = leftp.back();
        int rm = 1;

        for(int i = n - 2; i >= 0; --i) {
            rm *= nums[i + 1];
            rightp[i] = rm * leftp[i];
        }


        return rightp;
    }
};
