const vector<int> di {1, -1, 0, 0};
const vector<int> dj {0, 0, 1, -1};
class Solution {
    int m,n;
    int vis[500][500];
    bool is_cycle;


    bool valid(int i, int j, char c, vector<vector<char>>& grid) {
        return (i >= 0 && i < m) and (j >= 0 && j < n) and (grid[i][j] == c);
    }

    void dfs(int i, int j, vector<vector<char>>& grid, int pre_moves = 0) {
        if(vis[i][j]) {
            if(pre_moves - vis[i][j] > 1) {
                is_cycle = true;
            }
            return;
        }
        vis[i][j] = pre_moves + 1;

        for(int d{}; d<4; ++d) {
            int i2 = i + di[d];
            int j2 = j + dj[d];

            if(valid(i2, j2, grid[i][j], grid)) {
                dfs(i2, j2, grid, vis[i][j]);
            }
        }
    }
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid.front().size();

        for(int i{}; i < m; ++i) {
            for(int j{}; j < n; ++j) {
                if(!vis[i][j]) {
                    is_cycle = false;
                    dfs(i, j, grid);
                    if(is_cycle) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
