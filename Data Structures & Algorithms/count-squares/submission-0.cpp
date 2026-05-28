class CountSquares {
public:
    unordered_map<long, int> ptsCount;
    vector<vector<int>> pts;

    long getKey(int x, int y) {
        return (static_cast<long>(x) << 32) | static_cast<long>(y);
    }

    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        long key = getKey(point[0], point[1]);
        ptsCount[key]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int result = 0;
        int px = point[0], py = point[1];

        for(const auto& pt : pts) {
            int x = pt[0], y = pt[1];

            if(abs(px - x) != abs(py - y) || x == px || y == py) continue;
            result += ptsCount[getKey(x, py)] * ptsCount[getKey(px, y)];
        }
        return result;
    }
};
