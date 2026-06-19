class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshCount = 0;
        int time = 0;
        queue<pair<int, int>> rottQueue;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    rottQueue.push({i, j});
                } else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(freshCount > 0 && !rottQueue.empty()) {
            int length = rottQueue.size();

            for(int i = 0; i < length; i++) {
                int r = rottQueue.front().first;
                int c = rottQueue.front().second;
                rottQueue.pop();

                for(vector<int> direction : directions) {
                    int row = r + direction[0];
                    int col = c + direction[1];
                    
                    if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != 1) {
                        continue;
                    }

                    grid[row][col] = 2;
                    freshCount--;

                    rottQueue.push({row, col});
                }
            }

            time++;
        }


        return (freshCount == 0) ? time : -1; 
    }
};
