class Solution {
public:
    int climbStairs(int n) {
        // Initialize a memo array with -1 to represent uncalculated steps
        std::vector<int> memo(n + 1, -1);
        return help(n, 0, memo);
    }

    int help(int n, int current, std::vector<int>& memo) {
        if (current == n) return 1;
        if (current > n) return 0;
        
        // If we have already calculated the result from this step, return it immediately
        if (memo[current] != -1) {
            return memo[current];
        }

        int left = help(n, current + 1, memo);
        int right = help(n, current + 2, memo);
        
        // Store the result in our memo before returning
        memo[current] = left + right;
        return memo[current];
    }
};