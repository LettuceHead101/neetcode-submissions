class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> m;
        int l = 0;
        int r = 0;
        int total = 0;

        while (r < s.size()) {
            // If the character is NOT in the set, expand the window to the right
            if (m.find(s[r]) == m.end()) {
                m.insert(s[r]);
                total = max(total, r - l + 1); // Update max length
                r++;                           // Move right pointer
            } 
            // If it IS in the set, shrink the window from the left until the duplicate is gone
            else {
                m.erase(s[l]);                 // Remove the leftmost character
                l++;                           // Move left pointer
            }
        }

        return total;
    }
};