class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        vector<vector<bool>> atlantic(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> pacific(ROWS, vector<bool>(COLS, false));

        queue<pair<int, int>> atlQueue;
        queue<pair<int, int>> pacQueue;

        for(int r = 0; r < ROWS; r++) {
            pacific[r][0] = true;
            pacQueue.push({r, 0});

            atlantic[r][COLS - 1] = true;
            atlQueue.push({r, COLS - 1});
        }

        for(int c = 0; c < COLS; c++) {
            pacific[0][c] = true;
            pacQueue.push({0, c});

            atlantic[ROWS - 1][c] = true;
            atlQueue.push({ROWS - 1, c});
        }

        bfs(pacQueue, pacific, heights);
        bfs(atlQueue, atlantic, heights);

        vector<vector<int>> result;

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(atlantic[r][c] && pacific[r][c]){
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

                if(nr < 0 || nc < 0 || nr >= heights.size() || nc >= heights[0].size() || ocean[nr][nc]) continue;

                if(heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                    ocean[nr][nc] = true;
                }
            }
        }
    }
};
