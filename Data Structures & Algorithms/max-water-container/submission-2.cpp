class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0;

        int l = 0;
        int r = heights.size() - 1;

        while(l < r){
            int m = min(heights[l], heights[r]);

            result = max(result, (r - l) * m);

            if(heights[r] > heights[l]){
                l++;
            } else{
                r--;
            }

        }

        return result;
    }
};
