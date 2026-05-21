class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // holds the size of nums array
        int n = nums.size();

        // holds the counts and frequencies of certain numbers
        unordered_map<int,int> counts;

        // insert into the counts map
        for(int num : nums) {
            counts[num]++;
        }

        // buckets where index = frequency
        vector<vector<int>> buckets(n + 1);
        
        // populate the buckets
        for (auto pair : counts) {
            // extract the key and value from the pair to make it easy to read
            int num = pair.first;   
            int freq = pair.second; 
            
            // place the number into the bucket that matches its frequency
            buckets[freq].push_back(num);
        }

        vector<int> result;
        
        // iterate backwards through the buckets to get the most frequent elements first
        for (int i = n; i >= 0; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                
                // stop once we have gathered exactly k elements
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;


    }
};
