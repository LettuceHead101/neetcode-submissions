class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];

        return max( helper(vector<int>(nums.begin() + 1, nums.end())) , helper(vector<int>(nums.begin(), nums.end()-1)  )  );


        
    }

    int helper(vector<int> nums){
        int sum_one = 0;
        int sum_two = 0;

        for(int i = 0; i < nums.size(); ++i){
            int temp = max( sum_one + nums[i], sum_two);
            sum_one = sum_two;
            sum_two = temp;
        }
        return sum_two;
    }
};
