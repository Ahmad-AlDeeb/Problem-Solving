int const MAX_M = 100 + 1;
int const MAX_N = 100 + 1;

class Solution {
    int cache[MAX_M][MAX_N];
    vector<vector<int>> grid;
    int m, n;

    bool isValid(int i, int j) {
        return (i < m && j < n) && (!grid[i][j]);
    }

    int getUniquePaths(int i, int j) {
        if(!isValid(i, j)) {
            return 0;
        }

        if(i == m - 1 && j == n - 1) {
            return 1;
        }

        int &answer = cache[i][j];
        if(answer != -1) {
            return answer;
        }

        return answer = getUniquePaths(i + 1, j) + getUniquePaths(i, j + 1);
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(cache, -1, sizeof(cache));
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        grid = obstacleGrid;

        return getUniquePaths(0, 0);
    }
};
