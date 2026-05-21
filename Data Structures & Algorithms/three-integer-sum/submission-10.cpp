class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            // skip duplicate values for nums[i].
            // If i > 0 and the current number is the same as the previous one, 'continue'.
            // this prevents the exact same starting number from creating duplicate triplets.
            if((i > 0) && (nums[i] == nums[i-1])) continue;

            int left = i + 1;
            int right = n - 1;
            int target = -1 * nums[i]; 
            
            while(left < right) {
                if(nums[left] + nums[right] == target) {
                    
                    // you found a match! Add {nums[i], nums[left], nums[right]} to 'result'.
                    result.push_back({nums[i], nums[left], nums[right]});

                    // advance 'left' by 1 and decrement 'right' by 1 to keep looking.
                    left++;
                    right--;

                    // skip over duplicate 'left' values
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    // keep decrementing 'right'
                    while(right > left && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if(nums[left] + nums[right] > target) { 
                    right--;
                } else { 
                    left++;
                }
            }
        }

        return result;
    }
};