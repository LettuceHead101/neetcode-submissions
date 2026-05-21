class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        int n = prices.size();
        for(int i = 0; i < n; i++) {
            int buy = prices[i];
            for(int j = i + 1; j < n; j++) {
                if(buy < prices[j] && prices[j] - buy > mp) {
                    cout << buy << " " << prices[j] << " ";
                    mp = prices[j] - buy;
                    cout << mp << endl;
                } 
            }
        }

        return mp;
    }
};
