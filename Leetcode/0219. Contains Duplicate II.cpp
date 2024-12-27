class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> cache;
        for(int i{}; i < nums.size(); ++i) {
            cache[nums[i]].push_back(i);
        }

        for(auto p : cache) {
            int uniqueValue = p.first;
            vector<int> indexes = p.second;

            for(int i{1}; i < indexes.size(); ++i) {
                if(indexes[i] - indexes[i - 1] <= k) {
                    return true;
                }
            }
        }
        return false;
    }
};
