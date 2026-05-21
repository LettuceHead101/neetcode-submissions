class Solution {
public:
    int reverse(int x) {
        return helper(x, 0);
    }

private:
    int helper(int x, int rev) {
        if (x == 0) {
            return rev;
        }

        int digit = x % 10;

        // --- Overflow Checks ---
        // INT_MAX is 2147483647. If rev is greater than INT_MAX / 10, multiplying by 10 will overflow.
        // If it's exactly equal, the incoming digit cannot be greater than 7.
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
            return 0;
        }
        // INT_MIN is -2147483648. If rev is less than INT_MIN / 10, multiplying by 10 will underflow.
        // If it's exactly equal, the incoming digit cannot be less than -8.
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
            return 0;
        }

        // Add the digit to our reversed number
        rev = rev * 10 + digit;

        // Recursive call with the remaining digits and the new reversed number
        return helper(x / 10, rev);
    }
};