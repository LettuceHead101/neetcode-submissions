class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1, 0}};
    int ROWS;
    int COLS;

    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, -1));
        ROWS = m;
        COLS = n;

        return dfs(grid, 0, 0);
    }

    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r == ROWS - 1 && c == COLS - 1){
            return 1;
        }

        // we are out of bounds
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS){
            return 0;
        }

        if(grid[r][c] != -1){
            return grid[r][c];
        }

        int down = dfs(grid, r+1, c);
        int right = dfs(grid, r, c + 1);

        grid[r][c] = down + right;

        return grid[r][c];
    }
};
