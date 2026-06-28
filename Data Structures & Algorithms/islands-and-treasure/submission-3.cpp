class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1, 0}};

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++) {
                if(grid[r][c] == 0){
                    q.push({r,c});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();
            for(auto& d : directions){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
        
    }
};
