class Solution {
public:
    int getSum(int a, int b) {
        // Run the loop as long as there is a carry (a)
        while (a != 0) {
            // Calculate the carry and cast to unsigned to safely left-shift
            int carry = (a & b);
            
            // Calculate the sum without the carry and store in b
            b = a ^ b;
            
            // Shift the carry by 1 and store in a
            a = (unsigned int)carry << 1; 
        }

        // When the carry (a) is 0, b holds the final sum
        return b;
    }
};