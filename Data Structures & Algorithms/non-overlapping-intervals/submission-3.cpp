class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       sort(intervals.begin(), intervals.end());

       vector<vector<int>> temp;
       for(int i = 0; i < intervals.size(); i++) {
            if(temp.empty() || intervals[i][0] >= temp.back()[1]) {
                temp.push_back(intervals[i]);
                continue;
            }

            temp.back()[1] = min(temp.back()[1], intervals[i][1]);
       } 

       return intervals.size() - temp.size();
    }
};
