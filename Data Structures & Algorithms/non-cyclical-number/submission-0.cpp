class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;

        while(n != 1) {
            n = fun(n);
            if(seen.find(n) != seen.end()){ 
                return false;
            }
            seen.insert(n);
        }
        return true;
    }

    int fun(int n) {
        vector<int> digits;
        while(n != 0) {
            int digit = n % 10;
            digits.push_back(digit);
            n /= 10;
        }

        int rs = 0;

        for(int m : digits) {
            m = m*m;
            rs += m;
        }
        return rs;
    }
};
