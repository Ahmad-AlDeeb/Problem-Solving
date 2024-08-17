const vector<int> di {1, -1, 0, 0};
const vector<int> dj {0, 0, 1, -1};
class Solution {
    int m,n;
    bool vis[50][50];
    bool target[50][50];
    
    bool valid(int i, int j, int color, vector<vector<int>>& grid) {
        return (i >= 0 && i < m) and (j >= 0 && j < n) and (grid[i][j] == color);
    }

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(vis[i][j]) {
            return;
        }
        vis[i][j] = true;

        for(int k{}; k<4; k++) {
            int i2 = i + di[k];
            int j2 = j + dj[k];
            
            if(valid(i2, j2, grid[i][j], grid)) {
                dfs(i2, j2, grid);
            }
            else {
                target[i][j] = true;
            }
        }
    }


public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        m = grid.size();
        n = grid.front().size();
        
        dfs(row, col, grid);
        
        for(int i{}; i < m; ++i) {
            for(int j{}; j < n; ++j) {
                if(target[i][j]) {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }
};
