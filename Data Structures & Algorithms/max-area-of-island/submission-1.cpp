class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;

        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col] == 1) {
                    result = max(result, counting(grid, row, col));
                }
            }
        }

        return result;
    }

    int counting(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return 0;
        if(grid[row][col] == 0) return 0;

        int total = 1;
        grid[row][col] = 0;

        int left = counting(grid, row, col - 1);
        int right = counting(grid, row, col + 1);
        int up = counting(grid, row - 1, col);
        int down = counting(grid, row + 1, col);

        total = total + left + right + up + down;

        return total;
    }
};
