class Solution {
public:
    bool check(vector<int>& nums) {
        bool has_drop = false; 

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) {
                // If we already found a drop previously, this is the second one
                if(has_drop) return false; 
                has_drop = true;
            }
        }

        // If there was a drop, the last element must be <= the first element
        if(has_drop && nums.back() > nums.front()) {
            return false;
        }

        return true;
    }
};