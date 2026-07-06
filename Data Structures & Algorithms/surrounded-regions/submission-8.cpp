class DSU {
    vector<int> parent, size;

public:
    DSU(int n){
        n += 1;
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

    bool unionBySize(int node1, int node2){
        int p1 = find(node1);
        int p2 = find(node2);

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

    bool sameParent(int node1, int node2){
        return find(node1) == find(node2);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int ROWS = board.size();
        int COLS = board[0].size();

        DSU dsu(ROWS *  COLS);
        vector<vector<int>> directions = {{0,1}, {0, -1}, {-1, 0}, {1, 0}};

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(board[r][c] != 'O') continue;

                if(r == 0 || c == 0 || r == ROWS - 1 || c == COLS - 1){
                    dsu.unionBySize(ROWS * COLS, r * COLS + c);
                } else {
                    for(auto& d : directions){
                        int nr = r + d[0];
                        int nc = c + d[1];

                        if(nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || board[nr][nc] != 'O') continue;

                        dsu.unionBySize(r * COLS + c, nr * COLS + nc);
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
