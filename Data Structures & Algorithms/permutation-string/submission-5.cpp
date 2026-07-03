class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;

        vector<int> freq(26, 0);
        vector<int> window(26, 0);

        int l = 0;
        int r = s1.size();

        for(int i = 0; i < s1.size(); i++){
            freq[s1[i]-'a']++;
            window[s2[i]-'a']++;
        }

        for(int i = r; i < s2.size(); i++){
            if(freq == window){
                return true;
            } else {
                window[s2[l]-'a']--;
                l++;

                window[s2[i]-'a']++;
            }
        }

        return freq == window;
    }

};
