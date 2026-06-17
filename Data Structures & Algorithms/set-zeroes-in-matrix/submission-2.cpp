class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       
        queue<pair<int,int>> q;
        int ROWS = matrix.size();
        int COLS = matrix[0].size();
        auto process_rows = [&](int r)->void{
            for(int i = 0 ; i < COLS ; ++i){
                matrix[r][i] = 0;
            }
            return;
        };

        auto process_cols = [&](int c)->void{
            for(int j = 0; j < ROWS; ++j){
                matrix[j][c] = 0;
            }
            return; 
        };



        for(int i = 0; i < ROWS; ++i ){
            for(int j = 0; j < COLS; ++j){
                if(matrix[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            process_rows(r);
            process_cols(c);
        }

    }

    

};
