struct DSU{
    vector<int>parents;
    vector<int>groupSize;

    DSU(int n) : groupSize(n, 1) {
        parents.resize(n);
        for(int i = 0; i < n; i++) {
            parents[i] = i;
        }
    }

    int checkParent(int u) {
        if(parents[u] != u) {
            parents[u] = checkParent(parents[u]);
        }
        return parents[u];
    }

    void union_helper(int u, int v) {
        int uP = checkParent(u);
        int vP = checkParent(v);
        if(uP == vP) return;
        if(groupSize[vP] > groupSize[uP]) swap(uP, vP);
        groupSize[uP] += groupSize[vP];
        parents[vP] = uP;
    }

    bool sameParent(int u, int v) {
        return (checkParent(u) == checkParent(v));
    }
};

class Solution {//kruskals algorithm
public:
    int swimInWater(vector<vector<int>>& grid) {

        int N = grid.size();
        vector<pair<int,int>> directions = { {-1,0}, {1,0}, {0,1}, {0,-1}};
        vector<tuple<int,int,int>> pos(N*N);
        DSU dsu(N*N);
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid.size(); j++){
                pos[i * N + j] = { grid[i][j], i, j};
            }
        }
        sort(pos.begin(), pos.end());

        for(const auto& [val, r, c] : pos){

            for(const auto& [x, y] : directions ){
                int ROW = r + x;
                int COL  = c + y;
                if( ROW < 0 || COL < 0 || ROW >= N || COL >= N || grid[r][c]  < grid[ROW][COL])continue;

                int curr = r * N + c;// here we flatten our 2d matrix to cope with our dsu structure
                int prospect =  ROW * N + COL;
                dsu.union_helper(curr, prospect);

            }
            if(dsu.sameParent(0, (N*N)-1 ))return val;

        }
        return -1;
    }
};
