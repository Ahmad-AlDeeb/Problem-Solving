class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int size = hand.size();
        if(size % groupSize != 0) {
            return false;
        }

        int groupsCount = size / groupSize;
        vector<vector<int>> groups(groupsCount);

        sort(hand.begin(), hand.end());
        for(auto smallestVal : hand) {
            bool isInserted{};
            for(auto &group : groups) {

                if(group.size() == groupSize || !group.empty() && group.back() == smallestVal) {
                    continue;
                }

                
                if(!group.empty() && smallestVal - group.back() > 1) {
                    return false;
                }

                group.push_back(smallestVal);
                isInserted = true;
                break;
            }
            if(!isInserted) {
                return false;
            }
        }
        return true;
    }
};
 
