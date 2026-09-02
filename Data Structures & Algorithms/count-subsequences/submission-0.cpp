#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        const int n = static_cast<int>(s.size());
        const int m = static_cast<int>(t.size());

        // Deleting characters cannot turn a shorter source into
        // a longer target.
        if (m > n) {
            return 0;
        }

        // dp[j] stores the number of ways to form the first j characters
        // of t using the portion of s processed so far.
        vector<unsigned long long> dp(m + 1, 0);

        // There is exactly one way to form an empty target:
        // select no characters from the source.
        dp[0] = 1;

        for (char sourceChar : s) {
            // Traverse backward so dp[j - 1] still represents the state
            // from before sourceChar was processed.
            //
            // This prevents one source character from being reused for
            // multiple positions in the target.
            for (int j = m; j >= 1; --j) {
                if (sourceChar == t[j - 1]) {
                    // dp[j] already contains the number of ways that skip
                    // sourceChar.
                    //
                    // dp[j - 1] counts the ways that use sourceChar as the
                    // new final character of this target prefix.
                    dp[j] += dp[j - 1];
                }
            }
        }

        return static_cast<int>(dp[m]);
    }
};