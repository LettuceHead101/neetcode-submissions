class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dummy(n, vector<int>(n, 0));

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                int num = matrix[i][j];

                dummy[j][n - 1 - i] = num;
            }
        }

        matrix = dummy;
    }
};
