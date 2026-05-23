class Solution {
public:
    unordered_set<int> seen;

    bool isHappy(int n) {
        int x = sod(n);
        if(x == 1) return true;

        // we are in a cycle
        if(seen.find(x) != seen.end()) {
            return false;
        } else {
            seen.insert(x);
            return isHappy(x);
        }
    }

    int sod(int x) {
        int sum = 0;

        while(x > 0) {
            int digit = x % 10;
            sum += digit * digit;

            x /= 10;
        }

        return sum;
    }
};
