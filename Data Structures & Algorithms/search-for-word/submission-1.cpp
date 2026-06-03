class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int idx) {
        if(idx == word.size()) {
            return true;
        }

        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[idx]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, r - 1, c, idx + 1) || // Move Up
                     dfs(board, word, r + 1, c, idx + 1) || // Move Down
                     dfs(board, word, r, c - 1, idx + 1) || // Move Left
                     dfs(board, word, r, c + 1, idx + 1);   // Move Right

        board[r][c] = temp;

        return found;
    }
};
