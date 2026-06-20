class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<bool>> pacificBool(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlanticBool(ROWS, vector<bool>(COLS, false));

        vector<vector<int>> result;

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        // set the edges to true
        for(int i = 0; i < ROWS; i++) {
            pacificBool[i][0] = true;       // Fixed: Left edge for Pacific
            pacificQueue.push({i, 0});

            atlanticBool[i][COLS - 1] = true;
            atlanticQueue.push({i, COLS - 1});
        }

        for(int i = 0; i < COLS; i++) {
            pacificBool[0][i] = true;       // Top edge for Pacific
            pacificQueue.push({0, i});

            atlanticBool[ROWS - 1][i] = true;
            atlanticQueue.push({ROWS - 1, i});
        }

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // process Pacific queue
        while(!pacificQueue.empty()) {
            int r = pacificQueue.front().first;
            int c = pacificQueue.front().second;
            pacificQueue.pop();

            for(vector<int> dir : directions) {
                int row = r + dir[0];
                int col = c + dir[1];

                // Fixed: Skip if already visited
                if(row < 0 || col < 0 || row >= ROWS || col >= COLS || pacificBool[row][col]) continue;

                // Fixed: Check if water can flow backwards (next cell is higher or equal)
                if(heights[row][col] >= heights[r][c]) {
                    pacificBool[row][col] = true;
                    pacificQueue.push({row, col});
                }
            }
        }

        // process Atlantic queue
        while(!atlanticQueue.empty()) {
            int r = atlanticQueue.front().first;
            int c = atlanticQueue.front().second;
            atlanticQueue.pop();

            for(vector<int> dir : directions) {
                int row = r + dir[0];
                int col = c + dir[1];

                // Fixed: Skip if already visited
                if(row < 0 || col < 0 || row >= ROWS || col >= COLS || atlanticBool[row][col]) continue;

                // Fixed: Check if water can flow backwards (next cell is higher or equal)
                if(heights[row][col] >= heights[r][c]) {
                    atlanticBool[row][col] = true;
                    atlanticQueue.push({row, col});
                }
            }
        }

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(atlanticBool[i][j] && pacificBool[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};