class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // 1. Iterate through every cell in the matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // 2. If the first character matches, launch the DFS search
                if (board[i][j] == word[0]) {
                    // If the DFS returns true, we found the word.
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        
        // 3. If we check every cell and never return true, the word isn't there
        return false;
    }

private:
    // Helper function to handle the recursive search
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int idx) {
        // BASE CASE: We successfully matched every letter in the word.
        if (idx == word.size()) {
            return true;
        }

        // BOUNDARY & MATCH CHECK:
        // Return false if we go out of bounds OR if the current cell doesn't match the letter we need.
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[idx]) {
            return false;
        }

        // VISITED TRACKING:
        // Temporarily store the current character, then change the board cell to '#' 
        // to mark it as visited for this current path.
        char temp = board[r][c];
        board[r][c] = '#';

        // SEARCH IN 4 DIRECTIONS:
        // We call DFS recursively for Up, Down, Left, and Right. 
        // We advance 'idx + 1' to look for the next letter in the word.
        // The || (OR) operator means if ANY of these directions return true, 'found' becomes true.
        bool found = dfs(board, word, r - 1, c, idx + 1) || // Move Up
                     dfs(board, word, r + 1, c, idx + 1) || // Move Down
                     dfs(board, word, r, c - 1, idx + 1) || // Move Left
                     dfs(board, word, r, c + 1, idx + 1);   // Move Right

        // BACKTRACKING:
        // We have finished exploring all paths from this cell. 
        // We MUST restore the original character so that entirely different paths 
        // originating from other starting points can use this cell.
        board[r][c] = temp;

        return found;
    }
};