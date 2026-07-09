class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxside = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1;
                    maxside = 1;
                }
            }
        }


        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == '1'){
                    int up = dp[i-1][j];
                    int left = dp[i][j-1];
                    int upLeft = dp[i-1][j-1];

                    dp[i][j] = min({up, left, upLeft}) + 1;
                    maxside = max(maxside, dp[i][j]);
                }

            }
        }


        return maxside * maxside;
    }
};