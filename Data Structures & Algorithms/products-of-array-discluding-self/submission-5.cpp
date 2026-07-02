class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftprod(nums.size(), 1);
        vector<int> rightprod(nums.size(), 1);

        int lp = 1;
        int rp = 1;

        for(int i = 1; i < nums.size(); i++){
            lp *= nums[i-1];
            leftprod[i] = lp;
        }

        rightprod.back() = leftprod.back();

        for(int i = nums.size() - 2; i >= 0; i--){
            rp *= nums[i+1];
            rightprod[i] = rp * leftprod[i];
        }

        return rightprod;
    }
};
