class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        
        int left = 0; 
        int maxValue = 0;
        unordered_set<char> seen;
        
        for(int i = 0; i < n; i++) {

            if(seen.find(s[i]) != seen.end()) { // Have we seen this character?
                
                // Decrease the window until we have a unique window
                // TODO: What condition keeps this loop running? 
                // Hint: You need to keep looping as long as the current character s[i] is still in the 'seen' set.
                while(seen.find(s[i]) != seen.end()) {
                    
                    // TODO 1: Remove the character currently at the 'left' pointer from your 'seen' set.
                    seen.erase(s[left]);
                    // TODO 2: Increment your 'left' pointer by 1 to shrink the window.
                    left++;
                }
                
                // TODO 3: Now that you've shrunk the window and removed the duplicate, 
                // you need to actually insert the current character s[i] into the 'seen' set!
                seen.insert(s[i]);
                
            } else { // If not, then increase the window
                
                // TODO 4: You found a new unique character! Insert s[i] into the 'seen' set.
                seen.insert(s[i]);
                
                if(i - left + 1 > maxValue) { // Do we have a new max length?
                    maxValue = i - left + 1;
                }
            }
        }

        return maxValue;
    }
};