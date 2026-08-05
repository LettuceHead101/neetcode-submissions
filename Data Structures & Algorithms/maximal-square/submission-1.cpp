class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int largest_seen = 0;

        vector<vector<int>> memo(rows, vector<int>(cols, -1));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1') {
                    largest_seen = max(largest_seen, dfs(matrix, memo, r, c));
                }
            }
        }

        return largest_seen * largest_seen;
    }

    int dfs(const vector<vector<char>>& matrix, vector<vector<int>>& memo, int r, int c) {
        if (r < 0 || c < 0 || matrix[r][c] == '0') {
            return 0;
        }

        if (memo[r][c] != -1) {
            return memo[r][c];
        }

        int up     = dfs(matrix, memo, r - 1, c);
        int left   = dfs(matrix, memo, r, c - 1);
        int upleft = dfs(matrix, memo, r - 1, c - 1);

        return memo[r][c] = 1 + min({up, left, upleft});
    }
};