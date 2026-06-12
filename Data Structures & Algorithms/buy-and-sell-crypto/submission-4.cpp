class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int smallNum = INT_MAX;
        int ans = INT_MIN;

        for(int i = 0; i < prices.size(); ++i){
            smallNum = min(smallNum, prices[i]);
            ans = max(ans, prices[i] - smallNum);

        }
        return ans;
    }
};
