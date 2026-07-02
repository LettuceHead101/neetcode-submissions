class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); ++i){
            unordered_set<int> s;
        

            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == '.')continue;
                if(!s.insert(board[i][j]).second)return false;
            }
            
        }

        for(int j = 0; j < board.size(); ++j){
            unordered_set<int> s;

            for(int i = 0; i < board[0].size(); ++i){
                if( board[i][j] != '.' && !s.insert(board[i][j]).second) return false;
            }
        }

        return (
            // Top row of 3x3 grids
            helper(board, 2, 2) && helper(board, 2, 5) && helper(board, 2, 8) &&
            // Middle row of 3x3 grids
            helper(board, 5, 2) && helper(board, 5, 5) && helper(board, 5, 8) &&
            // Bottom row of 3x3 grids
            helper(board, 8, 2) && helper(board, 8, 5) && helper(board, 8, 8)
            );

    }

    bool helper(vector<vector<char>>& board, int r , int c){
        unordered_map<int,int> m;


        for(int i = r -2 ; i <= r; i++){
            for(int j = c -2; j <= c; ++j){
                if(board[i][j] == '.')continue;
                m[board[i][j]]++;
                if(m[board[i][j]] > 1)return false;
            }
        }
        return true;
    }
};
