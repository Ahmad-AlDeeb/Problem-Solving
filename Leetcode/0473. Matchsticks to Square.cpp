class Solution {
    bool isPossible(vector<int>& matchsticks, int index, int target, vector<int>& sums) {
        if(index >= matchsticks.size()) {
            for(int i{}; i < 4; ++i) {
                if(sums[i] != target) {
                    return false;
                }
            }
            return true;
        }

        bool result{false};
        for(int i{}; i < 4; ++i) {
            if(sums[i] + matchsticks[index] <= target) {
                sums[i] += matchsticks[index];
                result = (result || isPossible(matchsticks, index + 1, target, sums));
                sums[i] -= matchsticks[index];
            }
        }
        return result;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int sum{};
        for(auto num : matchsticks) {
            sum += num;
        }
        int target {sum / 4};
        vector<int> sums(4);

        sort(matchsticks.rbegin(), matchsticks.rend());
        return isPossible(matchsticks, 0, target, sums);
    }
};
