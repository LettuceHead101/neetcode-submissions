class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> one = vector<int>(nums.begin(), nums.end() - 1);
        vector<int> two = vector<int>(nums.begin() + 1, nums.end());
        return max(fun(one), fun(two));
    }

    int fun(vector<int>& nums){
        int numOne = 0;
        int numTwo = 0;

        for(int i = 0; i < nums.size(); i++){
            int temp = max(numOne + nums[i], numTwo);
            numOne = numTwo;
            numTwo = temp;
        }

        return numTwo;
    }
};
