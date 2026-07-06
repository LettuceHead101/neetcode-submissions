class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();

        queue<pair<int, int>> atlantaQueue;
        queue<pair<int, int>> pacificQueue;

        vector<vector<bool>> atlantaOcean(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> pacificOcean(ROWS, vector<bool>(COLS, false));

        for(int i = 0; i < ROWS; i++){
            pacificQueue.push({i, 0});
            
            atlantaQueue.push({i, COLS - 1});
        }

        for(int i = 0; i < COLS; i++){
            pacificQueue.push({0, i});

            atlantaQueue.push({ROWS - 1, i});
        }

        bfs(pacificQueue, pacificOcean, heights);
        bfs(atlantaQueue, atlantaOcean, heights);

        vector<vector<int>> result;

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(pacificOcean[r][c] && atlantaOcean[r][c]){
                    result.push_back({r, c});
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

            ocean[r][c] = true;

            for(auto& d : directions){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr >= 0 && nc >= 0 && nr < heights.size() && nc < heights[0].size() && heights[nr][nc] >= heights[r][c] && !ocean[nr][nc]){
                    q.push({nr, nc});
                    // ocean[nr][nc] = true;
                }
            }
        }
    }
};
