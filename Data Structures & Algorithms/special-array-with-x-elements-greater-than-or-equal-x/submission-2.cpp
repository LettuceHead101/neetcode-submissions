class Solution {
public:
    int specialArray(vector<int>& nums) {
        unordered_map<int, int> numToFreq;
        int n = nums.size();

        for(int i = 0; i <= n; i++) {
            numToFreq[i] = 0;
        }


        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < n; j++) {
                if(i <= nums[j]){
                    numToFreq[i]++;
                }
            }
        }

        for(auto it : numToFreq){
            if(it.first == it.second)
            return it.first;
        }


        return -1;
    }
};