class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> temp;
        for(auto interval : intervals){
            if(temp.size() == 0 || temp.back()[1] < interval[0]  ){
                temp.push_back(interval);
            }else{
                int end = 0;
                end = max(temp.back()[1], interval[1]);
                temp.back()[1] = end;

            }
        }
        return temp;
        
    }
};
