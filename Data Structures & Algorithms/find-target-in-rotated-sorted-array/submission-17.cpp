class Solution {
   public:
    int search(vector<int>& nums, int target) {
      int l = 0;
      int r = nums.size() - 1;

      while (l <= r) {
         int mid = l + (r - l) / 2;

         if (nums[mid] == target) return mid;

         if (nums[l] <= nums[r]) {  // is it sorted completely
            cout << l << " " << r << " here " << nums[mid] << endl;
            if (nums[mid] > target) {
               r = mid - 1;
            } else {
               l = mid + 1;
            }
         } else if (nums[l] <= nums[mid]) {  // is the left atleast sorted
            cout << l << " " << r << " III " << nums[mid] << endl;

            if (nums[l] <= target && target < nums[mid]) {
               r = mid - 1;
            } else {
               l = mid + 1;
            }
         } else {  // the right half must be sorted
            cout << l << " " << r << " amm " << nums[mid] << endl;
            if (nums[mid] < target && target <= nums[r]) {
               l = mid + 1;
            } else {
               r = mid - 1;
            }
         }
      }

      return -1;
    }
};
