class Solution {
public:
    bool isPalindrome(string s) {
        string copy_s = "";
        string copy_r = "";

        for(const auto& c : s){
            if(!isalnum(c))continue;
            char temp = tolower(c);
            copy_s += (temp);
        }

        for(int i = s.size()-1; i >= 0; --i){
            char c = s[i];
            if(!isalnum(c))continue;
            char temp = tolower(c);
            copy_r += (temp);
        }
        return copy_r == copy_s;
    }
};
