class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int result = nums[0];

        while(left <= right) {
            if (nums[left] < nums[right]) {
                result = min(result, nums[left]);
                break;
            }
            
            int mid = left + (right - left) / 2;

            result = min(result, nums[mid]);

            // the answer is to the right side of mid
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            } else { // my answer is to the left
                right = mid - 1;
            }
        }

        return result;
    }
};
