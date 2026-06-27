class DSU {
    vector<int> parent, groupSize;

public:
    DSU(int n) {
        groupSize = vector<int>(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int find(int node){
        if(parent[node] != node){
            parent[node] = find(parent[node]);
        }

        return parent[node];
    }

    bool unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pv == pu) return false;

        if(groupSize[pu] >= groupSize[pv]){
            groupSize[pu] += groupSize[pv];
            parent[pv] = pu;
        } else {
            groupSize[pv] += groupSize[pu];
            parent[pu] = pv;
        }

        return true;
    }

    int getSize(int node) {
        return groupSize[find(node)];
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int area = 0;
        DSU dsu(ROWS * COLS);

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        auto index = [&](int r, int c) {
            return r * COLS + c;
        };

        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++) {
                if(grid[r][c] == 1) {
                    for(auto& d : directions) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == 1) {
                            dsu.unionBySize(index(r, c), index(nr, nc));
                        }
                    }
                    area = max(area, dsu.getSize(r * COLS + c));
                }
            }
        }

        return area;
    }
};
