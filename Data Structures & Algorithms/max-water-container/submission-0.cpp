class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int n = heights.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int height = min(heights[i], heights[j]);
                if((j - i) * height > result) result = (j - i) * height;
            }
        }
        return result;
    }
};
