class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n != m) return false;

        unordered_map<char, int> frequencyS;
        unordered_map<char, int> frequencyT;

        for(int i = 0; i < n; i++) {
            if(frequencyS.find(s[i]) != frequencyS.end()) {
                frequencyS[s[i]]++;
            } else {
                frequencyS.insert({s[i], 1});
            }
            if(frequencyT.find(t[i]) != frequencyT.end()) {
                frequencyT[t[i]]++;
            } else {
                frequencyT.insert({t[i], 1});
            }
        }

        return (frequencyT == frequencyS);
    }
};
