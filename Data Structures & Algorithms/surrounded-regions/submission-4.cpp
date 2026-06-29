class DSU {
    vector<int> parents, size;
public:
    DSU(int n){
        parents.resize(n+1);
        size.resize(n+1);

        for(int i = 0; i < n + 1; i++) {
            parents[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        if(parents[node] != node) {
            parents[node] = find(parents[node]);
        }
        return parents[node];
    }

    bool unionBySize(int node1, int node2){
        int parent1 = find(node1);
        int parent2 = find(node2);

        if(parent1 == parent2) return false;

        if(size[parent1] >= parent2){
            size[parent1] += size[parent2];
            parents[parent2] = parent1;
        } else {
            size[parent2] += size[parent1];
            parents[parent1] = parent2;
        }

        return true;
    }

    bool sameParent(int node1, int node2) {
        return find(node1) == find(node2);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        DSU dsu(ROWS * COLS);

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        auto index = [&](int r, int c){
            return r * COLS + c;
        };

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++){
                if(board[r][c] != 'O') continue;

                if(r == 0 || c == 0 || r == ROWS - 1 || c == COLS - 1){
                    dsu.unionBySize(ROWS * COLS, index(r, c));
                } else {
                    for(auto& dir : directions){
                        int nr = r + dir[0];
                        int nc = c + dir[1];

                        if(board[nr][nc] == 'O'){
                            dsu.unionBySize(index(r,c), index(nr,nc));
                        }
                    }
                }
            }
        }

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(board[r][c] == 'O'){
                    if(!dsu.sameParent(ROWS*COLS, index(r,c))){
                        board[r][c] = 'X';
                    }
                }
            }
        }
    }
};
