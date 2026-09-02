class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = static_cast<int>(s.size());
        const int n = static_cast<int>(p.size());

        // previous[j] represents whether the already-processed prefix
        // of s matches the first j characters of p.
        //
        // current[j] calculates the same information after adding the
        // next character from s.
        vector<char> previous(n + 1, false);
        vector<char> current(n + 1, false);

        // An empty string matches an empty pattern.
        previous[0] = true;

        // Initialize matches against an empty input string.
        //
        // A pattern such as "a*" can match an empty string because
        // '*' is allowed to use zero copies of the preceding 'a'.
        //
        // Similarly, "a*b*" can be reduced one starred pair at a time:
        // "a*b*" -> "a*" -> empty pattern.
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                previous[j] = previous[j - 2];
            }
        }

        // Process one input character at a time.
        for (int i = 1; i <= m; ++i) {
            // Reset the row before calculating it.
            fill(current.begin(), current.end(), false);

            // A non-empty string can never match an empty pattern.
            current[0] = false;

            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] != '*') {
                    // A normal pattern character must equal the current
                    // string character. A dot matches any single character.
                    bool charactersMatch =
                        p[j - 1] == '.' || p[j - 1] == s[i - 1];

                    // If the current characters match, the result depends
                    // on whether everything before them also matched.
                    current[j] =
                        charactersMatch && previous[j - 1];
                } else if (j >= 2) {
                    // The element controlled by '*' is immediately before it.
                    char repeatedElement = p[j - 2];

                    // Option 1: Use zero copies of the preceding element.
                    // Removing "x*" means checking the current string prefix
                    // against the pattern ending two positions earlier.
                    bool useZeroCopies = current[j - 2];

                    // Option 2: Use one or more copies.
                    //
                    // The current string character must match the element
                    // before '*'. We then look at previous[j], not
                    // previous[j - 2], because the same "x*" remains
                    // available to consume additional characters.
                    bool repeatedElementMatches =
                        repeatedElement == '.' ||
                        repeatedElement == s[i - 1];

                    bool useOneOrMoreCopies =
                        repeatedElementMatches && previous[j];

                    current[j] =
                        useZeroCopies || useOneOrMoreCopies;
                }
            }

            // The row we just calculated becomes the previous row
            // for the next input character.
            swap(previous, current);
        }

        // After every character has been processed, this state tells us
        // whether the entire string matches the entire pattern.
        return previous[n];
    }
};