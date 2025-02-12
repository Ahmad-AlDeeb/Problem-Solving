class Solution {
    const int MOD = 1e9 + 7;
    int cache[100000][2][3];

    int getCount(int n, int index, bool isAbsent, int lateCount) {
        if(index >= n) {
            return 1;
        }

        int &count = cache[index][isAbsent][lateCount];
        if(count != -1) {
            return count;
        }
        count = 0;

        int absentAnswer = 0;
        if(!isAbsent) {
            absentAnswer = getCount(n, index + 1, true, 0) % MOD;
        }
        
        int lateAnswer = 0;
        if(lateCount < 2) {
            lateAnswer = getCount(n, index + 1, isAbsent, lateCount + 1) % MOD;
        }

        int presentAnswer = getCount(n, index + 1, isAbsent, 0) % MOD;

        count += absentAnswer + lateAnswer;
        count %= MOD;
        count += presentAnswer;        
        count %= MOD;

        return count;
    }

public:
    int checkRecord(int n) {
        memset(cache, -1, sizeof(cache));
        return getCount(n, 0, false, 0);
    }
};
