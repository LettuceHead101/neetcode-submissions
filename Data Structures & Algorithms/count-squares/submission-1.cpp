class CountSquares {
public:
    unordered_map<long, int> countPoints;
    vector<vector<int>> points;

    // long getkey(int x, int y) {
    //     long lx = (long) x << 32;
    //     return lx | (long)y;
    // }


    long getkey(int x, int y) {
        return (static_cast<long>(x) << 32) | static_cast<long>(y);
    }

    CountSquares() {}
    
    void add(vector<int> point) {
        points.push_back(point);
        long key = getkey(point[0],point[1]);
        countPoints[key]++;
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int cnt = 0;

        for(auto v : points) {
            int x = v[0];
            int y = v[1];

            if(abs(px - x) != abs(py - y) || px == x || py == y) continue;

            
            cnt += countPoints[getkey(x, py)] * countPoints[getkey(px, y)];
        }

        return cnt;
    }
};
