const vector<int> di {1, -1, 0, 0};
const vector<int> dj {0, 0, 1, -1};
int const MAX_M = 50 + 1;
int const MAX_N = 50 + 1;
int const MAX_MOVES = 50 + 1;
int const MOD = 1e9 + 7;

class Solution {
    int m, n;
    int cache[MAX_M][MAX_N][MAX_MOVES];

    bool isOut(int i, int j) {
        return i < 0 || i >= m || j < 0 || j >= n;
    }
    
    int getWaysCount(int i, int j, int remainingMoves) {
        if(isOut(i, j)) {
            return 1;
        }
        if(!remainingMoves) {
            return 0;
        }
        
        int &count = cache[i][j][remainingMoves];
        if(count != -1) {
            return count;
        }
        count = 0;

        for(int dir{}; dir<4; ++dir) {
            int i2 = i + di[dir];
            int j2 = j + dj[dir];

            count += getWaysCount(i2, j2, remainingMoves - 1);
            count %= MOD;
        }
        return count;
    }

public:
    int findPaths(int m_, int n_, int maxMove, int startRow, int startColumn) {
        m = m_;
        n = n_;
        memset(cache, -1, sizeof(cache));
        
        return getWaysCount(startRow, startColumn, maxMove);
    }
};
