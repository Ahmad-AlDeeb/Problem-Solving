vector<int> di {1, 0, -1, 0};
vector<int> dj {0, 1, 0, -1};

class Solution {
    int m,n;
    vector<vector<bool>> vis;

    bool is_valid(int i, int j, vector<vector<int>> &grid2) {
        return (i >= 0 && i < m) and (j >= 0 && j < n) and (grid2[i][j]);
    }

    void dfs(int i, int j, bool &success, vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        if(vis[i][j]) {
            return;
        }
        vis[i][j] = true;

        if(!grid1[i][j]) {
            success = false;
        }

        for(int k{}; k<4; k++) {
            if(is_valid(i+di[k], j+dj[k], grid2)) {
                dfs(i+di[k], j+dj[k], success, grid1, grid2);
            }
        }
    }

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid1.size();
        n = grid1.front().size();
        vis = vector<vector<bool>>(500, vector<bool>(500));
        

        int answer{};
        for(int i{}; i < m; ++i) {
            for(int j{}; j < n; ++j) {
                if(!vis[i][j] && grid2[i][j]) {
                    bool success {true};
                    dfs(i, j, success, grid1, grid2);
                    answer += success;
                }

            }
        }
        return answer;
    }
};
