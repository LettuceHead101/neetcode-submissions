class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0;
        int leftMax = 0;

        for(char c : s) {
            if(c == '(') {
                leftMin++;
                leftMax++;
            }
            if(c == ')') {
                leftMin--;
                leftMax--;
            }
            if(c == '*') {
                leftMin -= 1;
                leftMax += 1;
            }

            if(leftMax < 0) return false;
            if(leftMin < 0) {
                leftMin = 0;
            }
        }

        return (leftMin == 0);
    }
};
