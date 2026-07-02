class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for(int& x : nums){
            if(!s.insert(x).second){
                return true;
            }
            
        }
        return false;
    }
};