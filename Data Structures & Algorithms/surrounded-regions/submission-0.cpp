class DSU {
    // create two vectors to hold parents of the ith object
    // and another to hold the groupsize of the ith object
    vector<int> parent, size;

    public:
    //constructor
    DSU(int n) {
        // resize parent to n + 1 given the grid size + 1 for the extra node
        // extra node represents the node that cannot be surrounded
        // we will use that node to represent the group that is not able to be surrounded
        parent.resize(n + 1);
        size.resize(n + 1);

        // everyone initially is their own parent and has a size of 1
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // find who the parent of the ith node is
    int find(int node) {
        // recusively find the parent if the node isn't it's own parent
        if(parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        // return the node's parent
        return parent[node];
    }

    //union two nodes together
    bool unionNodes(int u, int v) {
        // find their parents
        int pu = find(u);
        int pv = find(v);

        // if it's the same node we shouldn't be doing this operation
        if(pu == pv) return false;

        // take the bigger group and keep that as the "leader"
        if(size[pu] >= size[pv]) {
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }

    // if the two nodes share the same parent then they are connected
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // store row size and col size in variables
        int ROWS = board.size();
        int COLS = board[0].size();

        // instantiate an object dsu with ROWS * COLS + 1
        // the rows * cols represent the total amount of nodes in the board
        // the + 1 node is representing the "untouchable" node that cannot be surrounded
        DSU dsu(ROWS * COLS + 1);

        // preset of all 4 directions that we'll traverse per node later
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // iterate through the board until we find a node that potentially can be surrounded
        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(board[r][c] != 'O') continue;
                
                // check if the node is on the border, which would instantly make it unable to be surrounded
                // union it to the node that cannot be unioned
                if(r == 0 || c == 0 || r == ROWS - 1 || c == COLS - 1) {
                    // is this 2D array flattening?
                    dsu.unionNodes(ROWS * COLS, r * COLS + c);
                } else {
                    for(auto& dir : directions) {
                        // check the new coordinates after going in a direction
                        int nr = r + dir[0], nc = c + dir[1];
                        
                        // if the node is a O then union it to the node we branched from
                        if (board[nr][nc] == 'O') {
                            dsu.unionNodes(r * COLS + c, nr * COLS + nc);
                        }
                    }
                }
            }
        }

        // iterate through the board again checking to see at every point if the node we're at 
        // isn't connected to the node that's unreachable
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (!dsu.connected(ROWS * COLS, r * COLS + c)) {
                    board[r][c] = 'X';
                }
            }
        }
    }
};
