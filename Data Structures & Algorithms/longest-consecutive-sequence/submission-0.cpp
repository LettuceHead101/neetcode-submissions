class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();
        
        // add everything to the set
        for(int i = 0; i < n; i++) {
            seen.insert(nums[i]);
        }

        // check for repetitions;
        int result = 0;
        for(int i = 0; i < n; i++) {
            int count = 1;
            int num = nums[i];

            // are we at the beginning of a sequence?
            if(seen.find(nums[i] - 1) == seen.end()) {

                // we are the first in the sequence so loop until we find the end and increment the sequence
                while(seen.find(num + 1) != seen.end()){
                    count++;
                    num = num + 1;
                }
            } else {
                // we're not in the beginning of a sequence so skip
            }

            if (count > result) result = count;

        }

        return result;
    }
};
