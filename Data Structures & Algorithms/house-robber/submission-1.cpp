class Solution {
public:
    int rob(vector<int>& nums) {

        int sum_one = 0;
        int sum_two = 0;

        for(int i = 0 ; i < nums.size(); ++i){
            int temp = max(nums[i] + sum_one, sum_two);

            sum_one = sum_two;
            sum_two = temp;
        }

        return sum_two;
    }
};
