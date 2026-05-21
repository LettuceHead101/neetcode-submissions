class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0); // Pre-allocate the vector with size n+1, filled with 0s
        for(int i = 1; i <= n; i++) {
            // result[i / 2] gets the bits of the base number.
            // (i % 2) adds 1 if the current number is odd, and 0 if it's even.
            result[i] = result[i / 2] + (i % 2); 
        }
        return result;
    }
};