class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();
        for (int i = n-1; i >= 0; i--) {
            if (digits[i] == 9 && (i == n-1 || carry == 1)) {
                carry = 1;
                digits[i] = 0;
                if (i == 0) {
                    digits.insert(digits.begin(), carry);
                }
            } else if (i == n-1 || carry == 1) {
                if (carry == 1) carry = 0;
                digits[i]++;
            }
        }
        return digits;
    }
};
