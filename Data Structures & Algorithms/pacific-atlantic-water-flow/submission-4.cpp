class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int, int>> pacQueue;
        queue<pair<int, int>> atlQueue;

        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<bool>> pacTable(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atlTable(ROWS, vector<bool>(COLS, false));

        for(int i = 0; i < ROWS; i++) {
            pacTable[i][0] = true;
            pacQueue.push({i, 0});

            atlTable[i][COLS - 1] = true;
            atlQueue.push({i, COLS - 1});
        }

        for(int i = 0; i < COLS; i++) {
            pacTable[0][i] = true;
            pacQueue.push({0, i});

            atlTable[ROWS - 1][i] = true;
            atlQueue.push({ROWS - 1, i});
        }

        bfs(pacQueue, pacTable, heights);
        bfs(atlQueue, atlTable, heights);

        vector<vector<int>> result;

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(pacTable[r][c] && atlTable[r][c]) {
                    result.push_back({r,c});
                }
            }
        }

        return result;
    }

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(auto& d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr >= 0 && nc >= 0 && nr < heights.size() && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    q.push({nr, nc});
                    ocean[nr][nc] = true;
                }
            }
        }
    }
};
