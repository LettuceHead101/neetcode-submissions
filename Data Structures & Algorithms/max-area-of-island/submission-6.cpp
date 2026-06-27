class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size = vector<int>(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(parent[u] != u){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return false;

        if(size[pu] >= size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }

        return true;
    }

    int getSize(int node) {
        return size[find(node)];
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        DSU dsu(ROWS * COLS);

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

        int area = 0;

        auto index = [&](int r, int c) {
            return r * COLS + c;
        };

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 1){
                    for(auto& d : directions) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == 1) {
                            dsu.unionBySize(index(r, c), index(nr, nc));
                        }
                    }
                    area = max(area, dsu.getSize(index(r, c)));
                }
            }
        }

        return area;
    }
};
