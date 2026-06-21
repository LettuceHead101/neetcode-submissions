class DSU {
    vector<int> parent;
    vector<int> groupSize;

    public:
    DSU(int n) {
        parent.resize(n + 1);
        groupSize.resize(n + 1);

        for(int i = 0; i < n + 1; i++) {
            parent[i] = i;
            groupSize[i] = 1;
        }
    }

    int find(int u) {
        if(parent[u] != u) {
            parent[u] = find(parent[u]);
        }

        return parent[u];
    }

    bool unionNodes(int u, int v) {
        int up = find(u);
        int vp = find(v);

        if(up == vp) return false;

        if(groupSize[up] >= groupSize[vp]){
            groupSize[up] += groupSize[vp];
            parent[vp] = up;
        } else {
            groupSize[vp] += groupSize[up];
            parent[up] = vp;
        }
        return true;
    }

    bool sameparent(int u, int v) {
        return find(u) == find(v);
    }

};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();
        DSU dsu(ROWS * COLS);

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(board[r][c] == 'O') {
                    if(r == 0 || c == 0 || r == ROWS - 1 || c == COLS - 1) {
                        dsu.unionNodes(ROWS * COLS, r * COLS + c);    
                    } else {
                        for(auto dir : directions) {
                            int newR = r + dir[0];
                            int newC = c + dir[1];

                            if(board[newR][newC] == 'O'){
                                dsu.unionNodes(r * COLS + c, newR * COLS + newC);
                            }
                        }       
                    }
                }
            }
        }

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(!dsu.sameparent(ROWS * COLS, r * COLS + c)) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
