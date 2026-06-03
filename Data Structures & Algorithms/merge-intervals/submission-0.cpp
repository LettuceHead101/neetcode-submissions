class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> result;

        for(const auto& current : intervals) {
            if(result.empty() || result.back()[1] < current[0]) {
                result.push_back(current);
            } else {
                result.back()[1] = max(result.back()[1], current[1]);
            }
        }

        return result;
    }
};
