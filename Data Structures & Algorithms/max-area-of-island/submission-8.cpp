class DSU {
    vector<int> parents, gs;

public:
    DSU(int n){
        parents.resize(n);
        gs.resize(n);

        for(int i = 0; i < n; i++){
            parents[i] = i;
            gs[i] = 1;
        }
    }

    int find(int node){
        if(parents[node] != node){
            parents[node] = find(parents[node]);
        }
        return parents[node];
    }

    bool unionBySize(int node1, int node2){
        int p1 = find(node1);
        int p2 = find(node2);

        if(p1 == p2) return false;

        if(gs[p1] >= gs[p2]){
            gs[p1] += gs[p2];
            parents[p2] = p1;
        } else{
            gs[p2] += gs[p1];
            parents[p1] = p2;
        }
        return true;
    }

    int getS(int node) {
        return gs[find(node)];
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int area = 0;

        vector<vector<int>> directions = {{0,1}, {0,-1},{-1,0},{1,0}};

        DSU dsu(ROWS * COLS);

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == 1){
                    
                    for(auto& d : directions){
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == 1){
                            dsu.unionBySize(r * COLS + c, nr * COLS + nc);
                        }
                    }

                    area = max(area, dsu.getS(r * COLS + c));
                }
            }
        }

        return area;
    }
};
