class Solution {
public:
    string predictPartyVictory(string senate) {
        string living;
        unordered_set<int> dead;

        for(int iteration{}, i{}; iteration < 5; ++i) {
            if(i == senate.size()) {
                iteration++;
                i = 0;
            }
            if(dead.count(i)) {
                continue;
            }

            if(living.empty() || senate[i] == living.back()) {
                living += senate[i];
            }
            else {
                dead.insert(i);
                living.pop_back();
            }
        }

        return (living.back() == 'R')? "Radiant" : "Dire";
    }
};
