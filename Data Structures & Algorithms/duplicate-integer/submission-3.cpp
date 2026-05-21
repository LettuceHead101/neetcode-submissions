class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seenNums;

        for(int x : nums) {
            if(seenNums.find(x) != seenNums.end()) {
                return true;
            }
            seenNums.insert(x);
        }

        return false;
    }
};