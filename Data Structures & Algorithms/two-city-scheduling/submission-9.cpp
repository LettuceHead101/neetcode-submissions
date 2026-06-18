class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<int, vector<int>> pq;
        int result = 0;
        int twoN = costs.size();
        int n = twoN / 2;

        // originally send everyone to A
        for(int i = 0; i < costs.size(); i++) {
            result += costs[i][0];
        }

        // keep a list of N people
        for(int i = 0; i < costs.size(); i++) {
            // the cost of moving them from A to B
            int cost = costs[i][1] - costs[i][0];
            pq.push(cost);
            if(pq.size() > n) pq.pop();
        }

        for(int i = 0; i < n; i++) {
            result += pq.top();
            pq.pop();
        }


        return result;
    }
};


/*
Imagine you initially sent everyone to City A.
You've spent some amount of money, but you've sent too many people to A
(exactly 2n people).
To balance the groups, you need to move $n$ people from City A to City B.
Which people would be the 'cheapest' to move?
*/