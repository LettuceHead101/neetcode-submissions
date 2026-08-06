class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if (n < 4) return result;
        sort(nums.begin(), nums.end());

        int first = 0;
        
        // Loop 1: Anchor the first number
        while (first < n - 3) {
            // Skip duplicates for the first number
            if (first > 0 && nums[first] == nums[first - 1]) {
                first++;
                continue;
            }

            int second = first + 1;
            
            // Loop 2: Anchor the second number
            while (second < n - 2) {
                // Skip duplicates for the second number
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    second++;
                    continue;
                }

                // Loop 3: Your exact inner two-pointer logic
                int l = second + 1;
                int r = n - 1;
                long long newTarget = (long long)target - nums[first] - nums[second];

                while (l < r) {
                    if (nums[l] + nums[r] == newTarget) {
                        result.push_back({nums[first], nums[second], nums[l], nums[r]});
                        l++;
                        r--;

                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    } else if (nums[l] + nums[r] < newTarget) {
                        l++;
                    } else {
                        r--;
                    }
                }
                // Advance the second number
                second++;
            }
            // Advance the first number
            first++;
        }

        return result;
    }
};