class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<vector<int>> grid(n, vector<int>(n, -1));
        grid[0][0] = 1;
        int count = 1;

        //                                right   down    left     up
        vector<vector<int>> d = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        int idx = 0;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(count == n*n) break;


            int nr = r + d[idx][0];
            int nc = c + d[idx][1];

            if(nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] != -1) {
                idx = (idx + 1) % 4; // turn 90 degrees clockwise if we hit a wall or visited cell
                nr = r + d[idx][0];
                nc = c + d[idx][1];
            }
            
            count += 1;
            q.push({nr,nc});
            grid[nr][nc] = count;
        }

        return grid;
    }
};