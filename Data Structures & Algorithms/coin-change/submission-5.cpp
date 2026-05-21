class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 1. Create our DP array
        // We initialize it with 'amount + 1' because that acts as our "Infinity".
        // The maximum number of coins you could possibly need is 'amount' (using all 1s).
        vector<int> dp(amount + 1, amount + 1);
        
        // 2. Base Case
        // It takes 0 coins to make an amount of 0.
        dp[0] = 0;
        
        // 3. Bottom-Up Calculation
        // Iterate through every single amount from 1 up to our target 'amount'
        for (int i = 1; i <= amount; i++) {
            
            // Try every coin for the current amount 'i'
            for (int coin : coins) {
                // If the coin fits into the current amount
                if (i - coin >= 0) {
                    // Update dp[i] to be the minimum of:
                    // A) What we already have in dp[i]
                    // B) 1 (for the current coin) + the best answer for the remaining amount
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        
        // 4. Return the result
        // If our target amount still has our "Infinity" value, it means no combination worked.
        return dp[amount] > amount ? -1 : dp[amount];
    }
};