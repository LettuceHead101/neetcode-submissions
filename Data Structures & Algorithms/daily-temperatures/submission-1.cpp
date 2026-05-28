class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> s; // pair: {temp, index}

        for(int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while(!s.empty() && t > s.top().first) {
                auto p = s.top();
                s.pop();
                result[p.second] = i - p.second;
            }
            s.push({temperatures[i], i});
        }

        return result;
    }
};
