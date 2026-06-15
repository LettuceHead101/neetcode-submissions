class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(string s : strs) {
            int num = s.size();
            result += to_string(num) + '#' + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;

        while(i < s.size()) {
            int num = 0;
            string strNum = "";
            string word = "";

            while(s[i] != '#') {
                strNum += s[i];
                i++;
            }
            num = stoi(strNum);
            i++;

            while(num > 0) {
                word += s[i];
                i++;
                num--;
            }
            result.push_back(word);
        }


        return result;
    }
};
