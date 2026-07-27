/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;

        for(std::size_t i = 0; i < intervals.size(); i++){
            m[intervals[i].start]++;
            m[intervals[i].end]--;
        }
        int result = 0;
        int working = 0;

        for(const auto& [k,v] : m){
            working += v;
            result = max(result, working);
        }
        return result;
    }
};
