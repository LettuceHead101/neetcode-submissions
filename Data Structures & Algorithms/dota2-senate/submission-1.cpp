class Solution {
public:
    string predictPartyVictory(string senate) {
        int rcount = 0;
        int dcount = 0;
        vector<bool> v(senate.size(), true);
        long idx = 0;

        for(char c : senate){
            if(c == 'R'){
                rcount++;
            } else {
                dcount++;
            }
        }

        while(rcount > 0 && dcount > 0){
            // person hasn't been skipped
            if(v[idx % senate.size()]){
                // which party am i
                char party = senate[idx % senate.size()];
                char target;

                if(party == 'R'){
                    target = 'D';
                } else {
                    target = 'R';
                }

                // find and skip the next person
                for(int i = idx; i < senate.size() + idx; i++) {
                    if(senate[i % senate.size()] == target && v[i % senate.size()] == true){
                        v[i % senate.size()] = false;
                        if(target == 'R'){
                            rcount -= 1;
                        } else {
                            dcount -= 1;
                        }
                        break;
                    }
                }
                idx++;
            } else {
                idx++;
                continue;
            }
        }

        return(rcount <= 0) ? "Dire" : "Radiant";
    }
};