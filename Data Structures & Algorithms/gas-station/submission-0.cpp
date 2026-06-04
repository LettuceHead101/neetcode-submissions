class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0;
        int costSum = 0;
        int n = gas.size();

        int result = 0;
        int total = 0;
        for(int i = 0; i < n; i++) {
            gasSum += gas[i];
            costSum += cost[i];
        }

        if(gasSum < costSum) return -1;

        for(int i = 0; i < n -1 ; i++) {
            total += gas[i] - cost[i];
            if(total < 0) {
                total = 0;
                result = i + 1;
            }
        }

        return result;
    }
};
