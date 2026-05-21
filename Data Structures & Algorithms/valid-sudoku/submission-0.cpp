class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i < n; i++) {
            //check row and col
            unordered_set<char> seen_row;
            unordered_set<char> seen_col;

            for(int j = 0; j < n; j++) {
                // if the character is in the row
                if(seen_row.find(board[i][j]) != seen_row.end()) {
                    return false;
                }

                if(seen_col.find(board[j][i]) != seen_col.end()) {
                    return false;
                }

                if(board[i][j] != '.') {
                    seen_row.insert(board[i][j]);
                }

                if(board[j][i] != '.') {
                    seen_col.insert(board[j][i]);
                }
            }
        }

        //nine boxes to check
        for(int i = 0; i < 9; i++) {
            unordered_set<char> seen_box;

            for(int j = 0; j < 9; j++) {
                if(seen_box.find(board[(i / 3) * 3 + (j / 3)][(i % 3) * 3 + (j % 3)]) != seen_box.end()) {
                    return false;
                }
                if(board[(i / 3) * 3 + (j / 3)][(i % 3) * 3 + (j % 3)] != '.') {
                    seen_box.insert(board[(i / 3) * 3 + (j / 3)][(i % 3) * 3 + (j % 3)]);
                }
            }
        }


        return true;
    }
};
