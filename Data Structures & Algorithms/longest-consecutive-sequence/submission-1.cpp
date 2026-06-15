class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        for(int x : nums) {
            m.insert(x);
        }

        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if(m.find(num - 1) == m.end()) {
                int count = 1;

                while(m.find(num+1) != m.end()) {
                    count++;
                    num = num + 1;
                }

                if(count > result) result = count;
            }
        }
        return result;
    }
};
