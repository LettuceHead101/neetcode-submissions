class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        int minPrice = prices[0];

        for(int i = 0; i < prices.size(); i++) {
            //check if the current min price is still the min price
            if(minPrice < prices[i])
            {
                int profit = prices[i] - minPrice;
                if(profit > mp) mp = profit;
            }
            else
            {
                minPrice = prices[i];
            }
        }

        return mp;
    }
};
