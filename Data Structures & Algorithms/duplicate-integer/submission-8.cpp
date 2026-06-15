class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for(int x : nums) {
            if(m.count(x)) {
                return true;
            }
            m.insert(x);
        }
        return false;
    }
};