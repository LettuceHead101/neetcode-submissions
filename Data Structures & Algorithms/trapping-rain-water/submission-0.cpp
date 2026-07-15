class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        int n = height.size();

        for(int i = 0; i < n; i++){
            int leftMax = height[i];
            int rightMax = height[i];

            for(int j = 0; j < i; j++){
                leftMax = max(leftMax, height[j]);
            }

            for(int k = i+1; k < n; k++){
                rightMax = max(rightMax,height[k]);
            }

            result += min(leftMax, rightMax) - height[i];
        }

        return result;
    }
};
