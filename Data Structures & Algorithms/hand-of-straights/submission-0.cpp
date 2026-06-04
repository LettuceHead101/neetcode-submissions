class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        unordered_map<int, int> handFreq;
        for(int card : hand) handFreq[card]++;

        sort(hand.begin(), hand.end());
        for(int card : hand) {
            if(handFreq[card] > 0) {
                for(int i = card; i < card + groupSize; i++) {
                    if(handFreq[i] == 0) return false;
                    handFreq[i]--;
                }
            }
        }

        return true;
    }
};
