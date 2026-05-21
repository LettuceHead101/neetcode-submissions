class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;

        int sSize = s.size();
        int tSize = t.size();

        if(sSize != tSize) {
            return false;
        }

        for(int i = 0; i < sSize; i++) {
            if(smap.find(s[i]) != smap.end()) {
                smap[s[i]]++;
            } else {
                smap.insert({s[i], 1});
            }

            if(tmap.find(t[i]) != tmap.end()) {
                tmap[t[i]]++;
            } else {
                tmap.insert({t[i], 1});
            }
        }

        return (smap == tmap);
    }
};
