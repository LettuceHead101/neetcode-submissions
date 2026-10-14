class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        int n = temperatures.size();
        vector<int> result(n, 0);

        for(int i = 0; i < n; ++i){
            int temp = temperatures[i];

            while(!stk.empty() && temp > stk.top().first) {
                int pastTemp = stk.top().first;
                int pastIdx = stk.top().second;

                result[pastIdx] = i - pastIdx;
                stk.pop();
            }

            stk.push({temp, i});
        }

        return result;
    }
};
