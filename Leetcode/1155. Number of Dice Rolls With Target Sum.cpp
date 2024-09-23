int const MAX_N = 30 + 1;
int const MAX_TARGET = 1000 + 1;
int const MOD = 1e9 + 7;

class Solution {
    int cache[MAX_N][MAX_TARGET];
    int n, k;

    int getCount(int i, int remain) {
        if(i == n) {
            if(remain == 0) {
                return 1;
            }    
            return 0;
        }
        

        int &count = cache[i][remain];
        if(count != -1) {
            return count;
        }
        count = 0;

        for(int num{1}; num <= k; ++num) {
            if(num <= remain) {
                count += getCount(i + 1, remain - num);
                count %= MOD;
            }
        }
        return count;
    }

public:
    int numRollsToTarget(int n_, int k_, int target) {
        memset(cache, -1, sizeof(cache));
        n = n_;
        k = k_;

        return getCount(0, target);
    }
};
