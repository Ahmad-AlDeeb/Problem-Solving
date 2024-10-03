int const MAX_SIZE = 200 + 1;

class Solution {
    vector<vector<int>> dungeon;
    vector<vector<int>> cache;
    int m, n;

    int getMinHealth(int i, int j) {
        if(i >= m || j >= n) {
            return INT_MAX;
        }

        int currentHealth = dungeon[i][j];
        
        if(i == m - 1 && j == n - 1) {
            if(currentHealth >= 0) {
                return 1;
            }
            return 1 - currentHealth;
        }

        int &answer = cache[i][j];
        if(answer != -1) {
            return answer;
        }

        int rightHealth = getMinHealth(i    , j + 1);
        int downHealth  = getMinHealth(i + 1, j    );
        int minHealthNeeded = min(rightHealth, downHealth);

        if(currentHealth >= minHealthNeeded) {
            return answer = 1;
        }
        return answer = minHealthNeeded - currentHealth;
    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon_) {
        dungeon = dungeon_;
        m = dungeon.size();
        n = dungeon[0].size();
        cache.resize(MAX_SIZE, vector<int>(MAX_SIZE, -1));

        return getMinHealth(0, 0);
    }
};
