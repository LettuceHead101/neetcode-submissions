class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == 0){
                    q.push({r,c});
                }
            }
        }

        while(!q.empty()){
            int length = q.size();

            for(int i = 0; i < length; i++){
                int r = q.front().first;
                int c = q.front().second;

                q.pop();
                for(auto& d : directions){
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == INT_MAX){
                        q.push({nr,nc});
                        grid[nr][nc] = grid[r][c] + 1;
                    }
                }
            }
        }
    }
};
