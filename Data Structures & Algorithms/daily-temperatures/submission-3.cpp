class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> stk;

        for(int i = 0; i < temperatures.size(); i++){
            int temp = temperatures[i];

            while(!stk.empty() && temp > stk.top().first){
                pair<int, int> tempAndIdx = stk.top();
                stk.pop();
                result[tempAndIdx.second] = i - tempAndIdx.second; 
            }

            stk.push({temp, i});
        }
        return result;
    }
};
