class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int top = 0;
        int bottom = rows - 1;
        int targetRow = -1;

        while(top <= bottom) {
            int mid = top + (bottom - top) / 2;

            if(target > matrix[mid][cols-1]) {
                top = mid + 1;
            } else if (target < matrix[mid][0]) {
                bottom = mid - 1;
            } else {
                targetRow = mid;
                break;
            }
        }

        if (targetRow == -1) return false;

        int left = 0;
        int right = cols - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(matrix[targetRow][mid] == target) {
                return true;
            } else if(matrix[targetRow][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
