class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            // is the left half sorted correctly?
            if(nums[left] <= nums[mid]) {
                if(target >= nums[left] && target < nums[mid]) { // is our target strictly within this sorted left range?
                    right = mid - 1; // Adjust index, not value
                } else { 
                    left = mid + 1;  // Adjust index, not value
                }
            } else { // the right half must be sorted correctly

                if(target > nums[mid] && target <= nums[right]) { // is our target strictly within this sorted right range?
                    left = mid + 1;  // adjust index not value
                } else { 
                    right = mid - 1; // adjust index not value
                }
            }
        }
        return -1;
    }
};