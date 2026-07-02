class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for(const auto& word : strs){
            int size = word.size();

            ans += to_string(size);
            ans += ("#");
            ans += word;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};
