class DSU {
    vector<int> parent, size;
public:
    DSU(int n){
        parent.resize(n);
        size.resize(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int node){
        if(parent[node] != node){
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool onion(int n1, int n2){
        int p1 = find(n1);
        int p2 = find(n2);
        if(p1 == p2) return false;

        if(size[p1] >= size[p2]){
            size[p1] += size[p2];
            parent[p2] = p1;
        } else{
            size[p2] += size[p1];
            parent[p1] = p2;
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

        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        auto index = [&](int r, int c){
            return r * COLS + c;
        };

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == '1'){
                    islands++;

                    for(auto& d : directions){
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == '1'){
                            if(dsu.onion(index(r, c),index(nr, nc))){
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
