class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

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
