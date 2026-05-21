class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;

        for(int x:stones) {
            maxHeap.push(x);
        }

        while(!maxHeap.empty()){
            if(maxHeap.size() == 1) {
                return maxHeap.top();
            }

            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();



            if(x == y) continue;
            if(x < y) {
                y -= x;
                maxHeap.push(y);
            } else if(y < x) {
                x -= y;
                maxHeap.push(x);
            }
        }
        return 0;
    }
};
