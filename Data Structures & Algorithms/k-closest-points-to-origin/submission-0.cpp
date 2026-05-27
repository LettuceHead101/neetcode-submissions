class Solution {
private:
    struct CustomCompare {
        bool operator()(const std::pair<vector<int>, double>& a, const std::pair<vector<int>, double>& b) {
            return a.second > b.second; // Min-heap based on the second element
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<vector<int>, double>, vector<pair<vector<int>, double>>, CustomCompare> pq;
        for(int i = 0; i < points.size(); i++) {
            // get the current points x and y
            int x = points[i][0];
            int y = points[i][1];
            
            // get the distance
            double distance = sqrt((x * x) + (y * y));

            pq.push({{x, y}, distance});
        }

        vector<vector<int>> result;

        for(int i = 0; i < k; i++) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};
