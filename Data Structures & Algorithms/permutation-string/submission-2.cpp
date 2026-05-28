class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int right = s1.size() - 1;

        if(right + 1 > s2.size()) return false;

        // create the initial freq count for s1 and s2 with window
        vector<int> freqS1(26, 0);
        vector<int> freqS2(26, 0);

        for(int i = 0; i <= right; i++) {
            char c1 = s1[i];
            char c2 = s2[i];

            freqS1[c1 - 'a']++;
            freqS2[c2 - 'a']++;
        }


        while(right < s2.size() - 1) {
            // if they match then there is a permutation that exists
            if(freqS1 == freqS2) return true;

            // otherwise move the window up by one
            char cLeft = s2[left];
            left++;
            right++;
            char cRight = s2[right];

            // remove the left char from frequency and add the new right extended one
            freqS2[cLeft - 'a']--;

            freqS2[cRight - 'a']++;

        }

        return (freqS1 == freqS2);
    }






    
};
