const vector<int> di {1, -1, 0, 0};
const vector<int> dj {0, 0, 1, -1};
class Solution {
    int row, col;
    bool success;

    bool valid(int i, int j, int parent, vector<vector<int>>& heights, int effort) {
        return (i >= 0 && i < row) and (j >= 0 && j < col) and (abs(parent - heights[i][j]) <= effort);
    }

    void dfs(int i, int j, int parent, vector<vector<int>>& heights, vector<vector<int>>& vis, int effort) {
        if(vis[i][j]) {
            return;
        }
        vis[i][j] = true;
        
        if(i == row-1 && j == col-1) {
            success = true;
        }
        else {
            for(int d{}; d < 4; ++d) {
                int i2 = i + di[d];
                int j2 = j + dj[d];

                if(valid(i2, j2, heights[i][j], heights, effort)) {
                    dfs(i2, j2, heights[i][j], heights, vis, effort);
                }
            }
        }
    }

    bool reachable(int effort, vector<vector<int>>& heights) {
        success = false;

        vector<vector<int>> vis(row, vector<int>(col));
        dfs(0, 0, 0, heights, vis, effort);

        return success;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights.front().size();
        
        int answer{}, l{}, r{1000000-1};
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(reachable(mid, heights)) {
                r = mid -1;
                answer = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return answer;
    }
};
