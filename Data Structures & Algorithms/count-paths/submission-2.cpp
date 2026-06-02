class Solution {
public:
    vector<vector<int>> memo;
    
    int uniquePaths(int m, int n) {
        memo = vector<vector<int>>(m, vector<int>(n, -1));

        return helper(0, 0, m-1, n-1);
    }

    int helper(int row, int col, int targetrow, int targetcol) {
        // if we hit the target then return a + 1
        if(row == targetrow && col == targetcol) {
            return 1;
        }

        // if we went out of bounds for our row or col then return a 0
        if(row > targetrow) return 0;
        if(col > targetcol) return 0;

        // check if we've already calculated the work for this square before and return it if so
        if(memo[row][col] != -1) {
            return memo[row][col];
        } else { // otherwise calculate the work
            int down = helper(row + 1, col, targetrow, targetcol);
            int right = helper(row, col + 1, targetrow, targetcol);
            memo[row][col] = down + right;
        }

        return memo[row][col];
    }
};
