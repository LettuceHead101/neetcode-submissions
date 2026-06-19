class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    result = dfs(grid, i, j);
                    return result;
                }
            }
        }
        return result;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        // if we go out of bounds or if the value of the place we land in is 0
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 0) return 1;
        // mark the land visited
        if(grid[row][col] == 2) return 0;

        grid[row][col] = 2;

        // go these directions
        int up = dfs(grid, row - 1, col);
        int down = dfs(grid, row + 1, col);
        int left = dfs(grid, row, col -1);
        int right = dfs(grid, row, col + 1);

        return left + right + down + up;
    }
};