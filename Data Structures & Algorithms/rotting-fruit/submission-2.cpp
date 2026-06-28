class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int freshCount = 0;
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(int r = 0; r < grid.size(); r++) {
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 2) {
                    q.push({r, c});
                } else if(grid[r][c] == 1){
                    freshCount++;
                }
            }
        }

        while(freshCount > 0 && !q.empty()) {
            int length = q.size();
            
            for(int i = 0; i < length; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(auto& d : directions) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        freshCount--;
                    }
                }
            }

            minutes++;
        }

        return (freshCount == 0) ? minutes : -1; 
    }
};
