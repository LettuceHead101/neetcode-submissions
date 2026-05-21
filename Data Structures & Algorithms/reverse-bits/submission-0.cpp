class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
            // Shift result to the left to make room for the incoming bit
            result <<= 1; 
            
            // Extract the rightmost bit of 'n' (using n & 1) and add it to 'result'
            result |= (n & 1); 
            
            // Shift 'n' to the right to process the next bit on the next loop
            n >>= 1; 
        }
        
        return result;
    }
};