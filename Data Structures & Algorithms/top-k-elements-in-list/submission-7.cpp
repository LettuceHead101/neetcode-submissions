class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> m;

        for(int x : nums){
            m[x]++;
        }

        for(auto it : m){
            pq.push({it.second, it.first});
        }

        vector<int> result;

        for(int i = 1; i <= k; i++){
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
