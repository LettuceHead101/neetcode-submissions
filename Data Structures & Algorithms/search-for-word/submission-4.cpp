class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[0].size(); c++){
                if(board[r][c] == word[0] && backtrack(board, word, r, c, 0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>>& board, string word, int r, int c, int i){
        if(i == word.size()){
            return true;
        }

        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[i]){
            return false;
        }

        char ch = board[r][c];
        board[r][c] = '#';
        
        // check up down left right for next letter
        bool up = backtrack(board, word, r-1, c, i+1);
        bool down = backtrack(board, word, r+1, c, i+1);
        bool left = backtrack(board, word, r, c-1, i+1);
        bool right = backtrack(board, word, r, c+1, i+1);

        board[r][c] = ch;

        return up || down || left || right;
    }
};
