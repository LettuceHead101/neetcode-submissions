class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        vector<pair<int, int>> freqAndNum;
        unordered_map<int, int> freq;

        for(auto& x : nums){
            freq[x]++;
        }

        for(auto& [key, val] : freq){
            freqAndNum.push_back({val, key});
        }

        sort(freqAndNum.begin(), freqAndNum.end());

        for(int i = 0; i < k; i++){
            result.push_back(freqAndNum[freqAndNum.size() - 1 - i].second);
        }
        return result;
    }
};
