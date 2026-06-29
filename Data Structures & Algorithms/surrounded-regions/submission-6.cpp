class DSU {
    vector<int> parents, groupSize;
public:
    DSU(int n) {
        n += 1;

        parents.resize(n);
        groupSize.resize(n);

        for(int i = 0; i < n; i++) {
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

    bool unionTogether(int node1, int node2) {
        int p1 = find(node1);
        int p2 = find(node2);

        if(p1 == p2) return false;

        if(groupSize[p1] >= groupSize[p2]){
            groupSize[p1] += groupSize[p2];
            parents[p2] = p1;
        } else {
            groupSize[p2] += groupSize[p1];
            parents[p1] = p2;
        }

        return true;
    }

    bool sameParent(int node1, int node2){
        return find(node1) == find(node2);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int ROWS = board.size();
        const int COLS = board[0].size();

        DSU dsu(ROWS * COLS);

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // auto index = [&](int r, int c) {
        //     return r * COLS + c;
        // };

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(board[r][c] != 'O') continue;

                if(r == 0 || c == 0 || r == ROWS - 1 || c == COLS - 1){
                    dsu.unionTogether(ROWS * COLS, r * COLS + c);
                } else {
                    for(auto& d : directions) {
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if(nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || board[nr][nc] != 'O') continue;

                        dsu.unionTogether(r * COLS + c, nr * COLS + nc);
                    }
                }
            }
        }


        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++){
                if(board[r][c] == 'O'){
                    if(!dsu.sameParent(ROWS * COLS, r * COLS + c)){
                        board[r][c] = 'X';
                    }
                }
            }
        }
    }
};
