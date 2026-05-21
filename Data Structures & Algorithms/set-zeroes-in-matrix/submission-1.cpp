class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<pair<int,int>> zero_Indexes;

        //find all the indexes where the value is 0
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == 0) {
                    zero_Indexes.push_back({i,j});
                }
            }
        }

        for(int i = 0; i < zero_Indexes.size(); i++) {
            setRow(zero_Indexes[i].first, matrix);
            setColumn(zero_Indexes[i].second, matrix);
        }
    }

    void setRow(int i, vector<vector<int>>& matrix) {
        for(int j = 0; j < matrix[0].size(); j++) {
            matrix[i][j] = 0;
        }
    }

    void setColumn(int j, vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            matrix[i][j] = 0;
        }
    }
};
