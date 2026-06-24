class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> result;

        for(int i = 0; i < matrix[0].size(); i++) {
            vector<int> temp;
            for(int j = 0; j < matrix.size(); j++) {
                temp.push_back(matrix[j][i]);

            }

            result.push_back(temp);
        }

        return result;
    }
};