class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pairs;

        for(int i = 0; i < n; ++i) {
            pairs.push_back({position[i], speed[i]});
        }

        sort(pairs.begin(), pairs.end());
        stack<double> result;

        for(int i = n - 1; i >= 0; --i) {
            if(result.empty()) {
                result.push((double)(target - pairs[i].first) / pairs[i].second);
                continue;
            }

            double stk_tta = result.top();
            double curr_tta = (double)(target - pairs[i].first) / pairs[i].second;

            if(stk_tta < curr_tta){
                result.push(curr_tta);
            }
        }

        return result.size();
    }
};
