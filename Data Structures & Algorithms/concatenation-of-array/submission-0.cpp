class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n * 2, 0);

        for(int i = 0; i < n*2; i++) {
            if(i < nums.size()) {
                ans[i] = nums[i];
            } else {
                ans[i] = ans[i - n];
            }
        }
        
        return ans;
    }
};