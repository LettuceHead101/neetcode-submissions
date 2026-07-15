class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int result = 0;

        while(l < r){
            int h = min(heights[l], heights[r]);
            result = max(result, (r-l)*h);

            if(heights[l] < heights[r]){
                l++;
            } else{
                r--;
            }
        }
        return result;
    }
};
