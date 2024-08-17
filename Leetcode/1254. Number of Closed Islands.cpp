const vector<int> di {1, -1, 0, 0};
const vector<int> dj {0, 0, 1, -1};
class Solution {
    int m,n;
    bool vis[100][100];
    bool is_island;

    bool valid(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || i >= m || j < 0 || j >= n) {
            is_island = false;
            return false;
        }
        return grid[i][j] == 0;
    }

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(vis[i][j]) {
            return;
        }
        vis[i][j] = true;

        for(int d{}; d<4; ++d) {
            int i2 = i + di[d];
            int j2 = j + dj[d];
            
            if(valid(i2, j2, grid)) {
                dfs(i2, j2, grid);
            }
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid.front().size();

        int answer{};
        for(int i{}; i < m; ++i) {
            for(int j{}; j < n; ++j) {
                if(!vis[i][j] && !grid[i][j]) {
                    is_island = true;
                    dfs(i, j, grid);
                    answer += is_island;
                }
            }
        }
        return answer;
    }
};
