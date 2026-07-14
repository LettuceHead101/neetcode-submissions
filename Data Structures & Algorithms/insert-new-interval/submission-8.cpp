class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        for(int i = 0; i < intervals.size(); i++){
            if(intervals[i][0] > newEnd){
                result.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(result));
                return result;
            } else if(intervals[i][1] < newStart){
                result.push_back(intervals[i]);
            } else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }

        result.push_back(newInterval);
        return result;
    }
};
