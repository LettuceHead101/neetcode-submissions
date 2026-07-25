class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> stk;
        vector<pair<int, int>> pas(position.size());
        for(int i = 0; i < position.size(); i++){
            pas[i] = {position[i], speed[i]};
        }

        sort(pas.begin(), pas.end());

        while(!pas.empty()){
            pair<int, int> item = pas.back();
            pas.pop_back();
            double tta = (double)(target - item.first) / item.second;

            if(stk.empty()){
                stk.push(tta);
                continue;
            }

            if(stk.top() >= tta){
                continue;
            } else {
                stk.push(tta);
            }
        }
        return stk.size();
    }
};
