class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    if(backtrack(board, word,i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int i) {
        if(i == word.size()) {
            return true;
        }

        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[i]) return false;

        char temp = board[r][c];
        board[r][c] = '#';

        bool sequence = backtrack(board, word, r+1, c, i+1)  || backtrack(board, word, r-1, c, i+1) ||
                        backtrack(board, word, r, c+1, i+1) || backtrack(board, word, r, c-1, i+1);

        board[r][c] = temp;

        return sequence;
    }
};
