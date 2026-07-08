class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;

        while(row < matrix.size()){
            if(matrix[row][0] <= target && matrix[row][col] >= target){
                int l = 0;
                int r = col;

                while(l <= r){
                    int mid = l + (r - l) / 2;
                    if(matrix[row][mid] == target){
                        return true;
                    } else if(matrix[row][mid] < target){
                        l = mid + 1;
                    } else{
                        r = mid - 1;
                    }
                }
                return false;
            } else if(matrix[row][col] < target){
                row++;
            } else{
                return false;
            }
        }

        return false;
    }
};
