class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // add in interval
        intervals.push_back(newInterval);

        // sort the intervals into it's new list
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });


        // iterate through the intervals, if there is overlap then merge the two
        // otherwise just insert into the new vector
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
