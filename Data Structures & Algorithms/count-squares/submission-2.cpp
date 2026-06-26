class CountSquares {
public:
    unordered_map<long,int> hashed_points;// long-hash, count
    vector<vector<int>> v; // keep track of pairs

    long create_key(int x , int y){
        return ((long)x << 32 | (long)y);
    }
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        v.push_back(point);
        long key = create_key(point[0], point[1]);
        hashed_points[key]++;
        
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];
        int ans = 0;

        for(const auto&  vec: v){
            int x = vec[0];
            int y = vec[1];
            if(abs(px - x) != abs(py - y) ||  (x == px) || (y == py))continue;

            ans += hashed_points[create_key(px,y)] * hashed_points[create_key(x,py)]; 
        }
        return ans;
    }
};
