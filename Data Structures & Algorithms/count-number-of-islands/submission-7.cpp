class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    result++;
                    sinkIsland(grid, i, j);
                }
            }
        }
        return result;
    }

    void sinkIsland(vector<vector<char>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != '1') return;
        grid[r][c] = '0';
        sinkIsland(grid, r+1, c);
        sinkIsland(grid, r-1, c);
        sinkIsland(grid, r, c+1);
        sinkIsland(grid, r, c-1);
    }
};
