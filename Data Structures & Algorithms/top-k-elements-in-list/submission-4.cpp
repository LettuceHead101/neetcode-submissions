class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashmap;
        
        for(int num : nums) {
            hashmap[num]++;
        }

        vector<vector<int>> buckets(n + 1);

        for(auto it : hashmap) {
            int frequencies = it.second;
            int num = it.first;
            buckets[frequencies].push_back(num);
        }

        vector<int> result;

        for(int i = n; i >= 0; i--) {
            for(int x : buckets[i]) {
                result.push_back(x);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};
