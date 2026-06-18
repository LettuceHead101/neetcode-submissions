class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carryover = true;
        int i = digits.size() - 1;
        while(carryover && i >= 0) {
            digits[i] += 1;

            if(digits[i] > 9) {
                digits[i] -= 10;
            } else {
                carryover = false;
            }

            i--;
        }

        if(carryover) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};
