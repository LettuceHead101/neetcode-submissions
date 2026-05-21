class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMaxProduct = nums[0];
        int currentMinProduct = nums[0];
        int maxProduct = nums[0];

        for (int i = 1; i < nums.size(); i++){
            int x = nums[i];
            // if we start fresh vs if we continue the max
            int one = x;
            // if we continue the max
            int two = currentMaxProduct * x;
            // if we continue the min
            int three = currentMinProduct * x;

            currentMaxProduct = max({one, two, three});
            currentMinProduct = min({one, two, three});

            if(maxProduct < currentMaxProduct) maxProduct = currentMaxProduct;
        }

        return maxProduct;
    }
};
