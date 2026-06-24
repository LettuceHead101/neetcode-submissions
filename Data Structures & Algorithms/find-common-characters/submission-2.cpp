class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // Initialize an array to keep track of the minimum frequencies.
        // We start with a high number (like 1000) so we can easily find the minimums.
        vector<int> minFreq(26, 1000); 

        // Loop through each word
        for(const string& word : words) {
            // Count frequencies for the CURRENT word
            vector<int> currentFreq(26, 0);
            for(char c : word) {
                currentFreq[c - 'a']++;
            }

            // Compare the current word's frequencies with our minimums
            // and update minFreq with the lowest values.
            for(int i = 0; i < 26; i++) {
                minFreq[i] = min(minFreq[i], currentFreq[i]);
            }
        }

        vector<string> result;
        
        // Build the final result array
        for(int i = 0; i < 26; i++) {
            // If a letter's minimum frequency is > 0, it means it appeared in ALL strings.
            // We loop here to add duplicates (e.g., if minFreq[i] is 2, it adds it twice).
            while(minFreq[i] > 0) {
                // Convert the character back to a string and add to result
                result.push_back(string(1, i + 'a'));
                minFreq[i]--;
            }
        }

        return result;
    }

};