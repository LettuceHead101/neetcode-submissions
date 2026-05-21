class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // This map connects a unique frequency signature to its list of anagrams.
        // Key: The string signature (e.g., "1#0#0#1...")
        // Value: A vector containing all strings that match that signature
        unordered_map<string, vector<string>> anagramGroups;

        // Iterate through each string in the input array
        for(string currentString : strs) {
            
            // Array to count the frequency of each character (a-z)
            vector<int> charCounts(26, 0);

            // Tally up the characters for the current string
            for(int i = 0; i < currentString.size(); i++) {
                char letter = currentString[i];
                charCounts[letter - 'a']++;
            }
            
            // Build a safe, unique signature string using delimiters
            string signature = "";
            for(int i = 0; i < 26; i++) {
                // Using to_string() and a '#' delimiter prevents multi-digit bugs.
                // Example: 10 'a's becomes "10#" instead of an unpredictable ASCII character.
                signature += to_string(charCounts[i]) + "#";
            }

            // Push the original string into the map under its specific signature.
            // If the signature doesn't exist yet, the map creates a new vector automatically.
            anagramGroups[signature].push_back(currentString);
        }

        // Prepare the final 2D vector to return
        vector<vector<string>> finalSolution;

        // Extract just the grouped vectors from our map
        for(auto pair : anagramGroups) {
            // pair.second represents the vector of strings (the anagram group)
            finalSolution.push_back(pair.second);
        }

        return finalSolution;
    }
};