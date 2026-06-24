class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val) {
                int idx = i;
                while(idx < nums.size()) {
                    if(nums[idx] != val) {
                        swap(nums[idx], nums[i]);
                        break;
                    }
                    idx++;
                }
            } else {
                continue;
            }

        }

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == val) {
                return i;
            }
        }

        return nums.size();
    }
};