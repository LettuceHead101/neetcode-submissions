class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> stk; // temp and index

        for(int i = 0; i < temperatures.size(); i++) {
            int temp = temperatures[i];
            while(!stk.empty() && temp > stk.top().first) {
                result[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push({temp, i});
        }

        return result;
    }
};
