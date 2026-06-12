class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    result = max(result, dfs(grid, i, j));
                }
            }
        }

        return result;
    }

    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            return 0;
        }

        if(grid[i][j] == 0) return 0;

        // explore 4 directions and mark this island as visited
        grid[i][j] = 0;
        int result = 1;

        // left
        result += dfs(grid, i, j - 1);

        // right
        result += dfs(grid, i, j + 1);

        // up
        result += dfs(grid, i - 1, j);

        // down
        result += dfs(grid, i + 1, j);

        return result;
    }
};
