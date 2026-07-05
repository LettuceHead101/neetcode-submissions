class DSU {
    vector<int> parents, groupSize;

public:
    DSU(int n ){
        parents.resize(n);
        groupSize.resize(n);

        for(int i = 0; i < n; i++){
            parents[i] = i;
            groupSize[i] = 1;
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

        if(groupSize[p1] >= groupSize[p2]){
            groupSize[p1] += groupSize[p2];
            parents[p2] = p1;
        } else{
            groupSize[p2] += groupSize[p1];
            parents[p1] = p2;
        }

        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int islands = 0;

        DSU dsu(ROWS * COLS);

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        auto index = [&](int r, int c){
            return r * COLS + c;
        };

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == '1'){
                    islands += 1;

                    for(auto& d : directions){
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == '1'){
                            if(dsu.unionBySize(index(r,c),index(nr,nc))){
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
