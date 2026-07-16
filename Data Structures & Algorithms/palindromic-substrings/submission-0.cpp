class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            count += fun(s, i, i);
            count += fun(s, i, i+1);
        }

        return count;
    }

    int fun(const string& s, int left, int right){
        int temp = 0;

        while(left >= 0 && right < s.size() && s[left] == s[right]){
            temp += 1;
            left--;
            right++;
        }
        return temp;
    }
};
