class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        unordered_map<int, int> freq;

        for(auto& x : nums){
            freq[x]++;
        }

        for(auto& [key, val] : freq){
            minHeap.push({val, key});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        for(int i = 0; i < k; i++){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
