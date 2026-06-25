class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left_sum = 0;
        int right_sum = 0;
        int max_score = 0;
        int n = cardPoints.size();

        // 1. Calculate the initial sum as if we take all k cards from the left
        for(int i = 0; i < k; i++) {
            left_sum += cardPoints[i];
        }
        
        max_score = left_sum;

        // 2. Slide the window: remove one from the left, add one from the right
        int right_index = n - 1;
        for(int i = k - 1; i >= 0; i--) {
            left_sum -= cardPoints[i];
            right_sum += cardPoints[right_index];
            right_index--;

            max_score = max(max_score, left_sum + right_sum);
        }

        return max_score;
    }
};