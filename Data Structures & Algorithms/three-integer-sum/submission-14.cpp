class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> solution;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            
            int left = i+1;
            int right = n-1;
            int target = -1 * nums[i];

            while(left < right) {
                if(nums[left] + nums[right] == target) {
                    solution.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }

                    while(right > left && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if(nums[left] + nums[right] < target) {
                    left++;
                } else {
                    right--;
                }

            }
            
        }

        return solution;
    }
};
