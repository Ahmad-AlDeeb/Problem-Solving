int const MAX_VALUE = 1e9 + 1;
int const MOD = 1e9 + 7;

class Solution {
    unordered_map<int, int> cache;
    unordered_set<int> nums;

    long long getCount(int current) {
        if(cache.count(current)) {
            return cache[current];
        }
        int &count = cache[current];
        count = 1;

        for(auto num : nums) {
            int child1 = num;
            int child2 = current / num;

            if(current % child1 == 0  && nums.count(child2)) {
                long long subTreesCount = getCount(child1) * getCount(child2);
                subTreesCount %= MOD;

                count += subTreesCount;
                count %= MOD;
            }
        }
        return count;
    }

public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        nums.insert(arr.begin(), arr.end());
        
        int count{};
        for(auto num : nums) {
            count += getCount(num);
            count %= MOD;
        }
        return count;
    }
};
