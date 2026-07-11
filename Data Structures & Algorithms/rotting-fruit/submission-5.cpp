class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        int fresh = 0;
        int time = 0;

        queue<pair<int, int>> rottQ;

        vector<vector<int>> directions = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == 2){
                    rottQ.push({r,c});
                } else if(grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        while(fresh > 0 && !rottQ.empty()){
            int length = rottQ.size();
            time++;

            for(int i = 0; i < length; i++){
                int r = rottQ.front().first;
                int c = rottQ.front().second;
                rottQ.pop();

                for(auto& d : directions){
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == 1){
                        fresh--;
                        rottQ.push({nr,nc});
                        grid[nr][nc] = 2;
                    }
                }                
            }

        }
        return (fresh == 0) ? time : -1;
    }
};
