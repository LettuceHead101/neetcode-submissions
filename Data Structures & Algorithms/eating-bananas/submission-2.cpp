class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // The minimum possible eating speed is 1
        int low = 1; 
        
        // The maximum possible eating speed is the size of the largest pile
        int high = *max_element(piles.begin(), piles.end());
        
        // This will store our optimal answer
        int ans = high; 

        // Standard Binary Search
        while (low <= high) {
            int mid = low + (high - low) / 2; // Test the middle speed
            
            // Use 'long long' because adding up hours for giant piles can overflow a standard 'int'
            long long hours_taken = 0; 
            
            for (int pile : piles) {
                // This is the math shortcut for finding the ceiling of division!
                // It replaces your inner while loop.
                // Equivalent to: ceil((double)pile / mid)
                hours_taken += (pile + mid - 1) / mid; 
            }

            // If Koko finishes in time, this is a valid speed.
            // But we want the *minimum* valid speed, so we save it and try going slower.
            if (hours_taken <= h) {
                ans = mid;         // Record the current best answer
                high = mid - 1;    // Search the left half (slower speeds)
            } 
            // If Koko takes too long, she is eating too slowly.
            else {
                low = mid + 1;     // Search the right half (faster speeds)
            }
        }

        return ans;
    }
};