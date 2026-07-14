class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> lp(n, 1);
        vector<int> rp(n, 1);

        int left = 1;
        int right = 1;

        for(int i = 1; i < n; i++){
            left *= nums[i-1];
            lp[i] = left;
        }

        rp.back() = lp.back();

        for(int i = n - 2; i >= 0; i--){
            right *= nums[i+1];
            rp[i] = right * lp[i];
        }

        return rp;
    }
};
