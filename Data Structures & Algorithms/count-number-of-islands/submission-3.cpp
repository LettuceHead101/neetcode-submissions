class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col] == '1') {
                    result++;
                    sink(grid, row, col);
                }
            }
        }
        return result;
    }

    void sink (vector<vector<char>>& grid, int row, int col) {
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        if(grid[row][col] == '0') return;

        grid[row][col] = '0';

        // explore up
            sink(grid, row - 1, col);
        // explore down
            sink(grid, row + 1, col);
        // explore left
            sink(grid, row, col - 1);
        // explore right
            sink(grid, row, col + 1);
    }
};
