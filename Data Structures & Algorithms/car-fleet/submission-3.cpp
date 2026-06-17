class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> posAndSpeed;
        stack<pair<int, int>> stk;

        for(int i = 0; i < position.size(); i++) {
            posAndSpeed.push_back({position[i], speed[i]});
        }

        sort(posAndSpeed.begin(), posAndSpeed.end());
        
        while(!posAndSpeed.empty()) {
            pair<int, int> p = posAndSpeed.back();
            posAndSpeed.pop_back();
            int position = p.first;
            int speed = p.second;
            
            if(stk.empty()) {
                stk.push({position, speed});
                continue;
            }

            int stkcarposition = stk.top().first;
            int stkcarspeed = stk.top().second;

            double timeToArrivalStk = (double)(target - stkcarposition) / stkcarspeed;
            double timeToArrivalCur = (double)(target - position) / speed;

            if(timeToArrivalStk >= timeToArrivalCur) {
                continue;
            } else {
                stk.push({position, speed});
            }
        }

        return stk.size();
    }
};
