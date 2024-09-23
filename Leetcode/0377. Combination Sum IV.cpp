int const MAX_TARGET = 1000 + 1;

class Solution {
    int cache[MAX_TARGET];
    vector<int> numbers;

    int getCount(int remain) {
        if(remain == 0) {
            return 1;
        }

        int &count = cache[remain];
        if(count != -1) {
            return count;
        }
        count = 0;

        for(auto num : numbers) {
            if(num <= remain)
                count += getCount(remain - num);
        }
        return count;
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(cache, -1, sizeof(cache));
        numbers = nums;

        return getCount(target);
    }
};
