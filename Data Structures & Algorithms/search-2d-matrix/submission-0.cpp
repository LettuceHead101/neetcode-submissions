class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int top = 0;
        int bot = ROWS - 1;
        int targetRow = -1;

        // 1. First Binary Search: Find the correct row
        while (top <= bot) {
            int mid = top + (bot - top) / 2;
            
            if (target > matrix[mid][COLS - 1]) {
                // Target is larger than the biggest element in this row. Look down.
                top = mid + 1;
            } else if (target < matrix[mid][0]) {
                // Target is smaller than the smallest element in this row. Look up.
                bot = mid - 1;
            } else {
                // Target falls within the range of this row!
                targetRow = mid;
                break;
            }
        }

        // If we never found a valid row range, the target isn't in the matrix
        if (targetRow == -1) return false;

        // 2. Second Binary Search: Search within the specific row
        int left = 0;
        int right = COLS - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (matrix[targetRow][mid] == target) {
                return true;
            } else if (matrix[targetRow][mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};