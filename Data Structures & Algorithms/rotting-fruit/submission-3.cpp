class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int time = 0;
        int fresh = 0;
        int ROWS = grid.size();
        int COLS = grid[0].size();

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int r = 0; r < ROWS; r++) {
            for(int c = 0; c < COLS; c++){
                if(grid[r][c] == 2){
                    q.push({r,c});;
                } else if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }

        while(fresh > 0 && !q.empty()){
            time++;
            int length = q.size();

            for(int i = 0; i < length; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(auto& d : directions){
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr >= 0 && nc >= 0 && nr < ROWS && nc < COLS && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return (fresh == 0) ? time : -1;
    }
};
