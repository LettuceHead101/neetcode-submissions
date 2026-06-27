class DSU {
    vector<int> parent, gs;
public:
    DSU(int n) {
        gs.resize(n);
        parent.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            gs[i] = 1;
        }
    }

    int find(int u) {
        if(parent[u] != u) {
            parent[u] = find(parent[u]);
        }

        return parent[u];
    }

    bool unionBySize(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if(pv == pu) return false;

        if(gs[pu] >= gs[pv]){
            gs[pu] += gs[pv];
            parent[pv] = pu;
        } else {
            gs[pv] += gs[pu];
            parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        DSU dsu(ROWS * COLS);
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        auto index = [&](int r, int c) {
            return r * COLS + c;
        };

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == '1') {
                    islands++;

                    for(auto& d : directions) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == '1') {
                            
                            if(dsu.unionBySize(index(r, c), index(nr, nc))) {
                                islands--;
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};
