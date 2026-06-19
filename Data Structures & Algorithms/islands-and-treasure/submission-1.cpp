class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(vector<int> direction : directions) {
                int row = r + direction[0];
                int col = c + direction[1];

                if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != INT_MAX) {
                    continue;
                }

                grid[row][col] = grid[r][c] + 1;
                q.push({row, col});
            }
        }
    }
};
