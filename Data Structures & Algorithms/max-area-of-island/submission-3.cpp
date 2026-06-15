class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    int temp = 0;
                    dfs(grid, i, j, temp);
                    result = max(result, temp);
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& grid, int r, int c, int& count) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0) return;

        grid[r][c] = 0;
        count += 1;

        dfs(grid, r+1, c, count);
        dfs(grid, r-1, c, count);
        dfs(grid, r, c+1, count);
        dfs(grid, r, c-1, count);
    }
};
