class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result;
        unordered_map<int, int> counts;

        for(const int& num : nums){
            counts[num]++;
        }

        for(auto& [key, val] : counts){
            pq.push({val, key});

            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
