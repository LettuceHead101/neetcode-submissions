class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // create our DP array
        // initialize it to amount + 1, because this acts as our "infinity"
        // the maximum number of coins you could possibly need is 'amount'
        // by using all the 1s in the coins array potentially
        vector<int> dp(amount+1, amount+1);

        // base case
        // it takes 0 coins to make an amount of 0
        dp[0] = 0;

        // bottom up calculation
        // iterate through every single amount from 1 up to our target 'amount'
        for(int i = 1; i <= amount; i++){
            // try every coin for the current amount 'i'
            for(int coin : coins) {
                // if the coin fits into the current amount
                if(i - coin >= 0) {
                    // update dp[i] to be the minimum of: 
                    // what we have in dp[i] or 1 + the best answer for the remaining amount
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }
            }
        }

        // return the result
        // if our target amount still has our infinity value, it means theres no combination possible
        return (dp[amount] > amount) ? -1 : dp[amount];

    }
};