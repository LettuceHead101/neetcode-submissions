class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // holds the size of nums array
        int n = nums.size();
        
        // holds the counts and frequencies of certain numbers
        unordered_map<int,int> counts;

        // insert into the counts map
        for(int x : nums) {
            counts[x]++;
        }

        // buckets where index = frequency
        vector<vector<int>> buckets(n+1);
        // why do we do n + 1? i get that if all elements are unique it would be n buckets from the array but why n + 1 i dont get that part specifically

        // populate the buckets
        for(auto pair : counts) {
            // extract the key and value from the pair to make it easy to read
            int frequency = pair.second;
            int num = pair.first;

            // place the number into the bucket that matches its frequency
            buckets[frequency].push_back(num);
        }
        vector<int> solution;

        // iterate backwards through the buckets to get the most frequent elements first
        for (int i = n; i >= 0; --i) {
            for (int num : buckets[i]) {
                solution.push_back(num);
                
                // stop once we have gathered exactly k elements
                if (solution.size() == k) {
                    return solution;
                }
            }
        }
        
        return solution;
    }
};
