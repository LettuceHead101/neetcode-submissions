class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;
        int left = 0;
        int right = heights.size() - 1;

        while(left < right) {
            int h = min(heights[left], heights[right]);
            result = max(result, h * (right - left));

            if(heights[left] < heights[right]){
                left++;
            } else {
                right--;
            }
        }

        return result;
    }
};
