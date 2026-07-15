class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            if(numSet.find(nums[i]-1) == numSet.end()){
                int currNum = nums[i];
                int currLength = 1;

                while(numSet.find(currNum+1) != numSet.end()){
                    currLength += 1;
                    currNum += 1;
                }

                result = max(result, currLength);
            }
        }
        return result;
    }
};
