class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(const string& str : strs) {
            result += to_string(str.size()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int idx = 0;

        while(idx < s.size()) {
            string size = "";
            while(s[idx] != '#') {
                size += s[idx];
                idx++;
            }

            int len = stoi(size);
            idx++;
            
            string temp = s.substr(idx, len);
            result.push_back(temp);
            idx += len;
        }

        return result;
    }
};
