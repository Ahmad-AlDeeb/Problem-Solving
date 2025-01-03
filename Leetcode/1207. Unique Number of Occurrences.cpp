class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occ;
        for(auto num : arr) {
            occ[num]++;
        }

        unordered_set<int> uniqueOcc;
        for(auto p : occ)  {
            int occCount = p.second;
            if(!uniqueOcc.insert(occCount).second) {
                return false;
            }
        }
        return true;
    }
};
