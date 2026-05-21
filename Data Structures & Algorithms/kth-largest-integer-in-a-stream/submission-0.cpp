class KthLargest {
public:
    int k_limit;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) {
        k_limit = k;

        for(int x : nums) {
            add(x);
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if(minHeap.size() > k_limit) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
