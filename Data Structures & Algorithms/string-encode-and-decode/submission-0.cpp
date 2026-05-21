class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        for(string s : strs) {
            int size = s.size();
            encoded_string += to_string(size) + "#" + s;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;
        int count = 0;
        int i = 0;
        while(i < s.size()) {
            string curr_String = "";
            // continue grabbing digits until we can make the number then we iterate downwards
            if(count == 0 && s[i] != '#') {
                string numSize = "";
                while(s[i] != '#') {
                    numSize += s[i];
                    i++;
                }
                count = stoi(numSize);
                i++;
            }


            // iterate using the count to make a new string to push into the 
            while(count > 0) {
                curr_String += s[i];
                count--;
                i++;    
            }

            //push the new string into the vector
            decoded_strings.push_back(curr_String);
            count = 0;
        }

        return decoded_strings;
    }
};
