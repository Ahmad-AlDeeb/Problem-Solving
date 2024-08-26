class Solution {
    const vector<int> di {1, -1, 0, 0};
    const vector<int> dj {0, 0, 1, -1};
    int m, n;
    bool valid(int i, int j) {
        return (i >= 0 && i < m) and (j >= 0 && j < n);
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix.front().size();
        vector<vector<int>> inDegree(m, vector<int>(n));
        for(int i{}; i < m; ++i) {
            for(int j{}; j < n; ++j) {
                
                for(int d{}; d < 4; ++d) {
                    int i2 = i + di[d];
                    int j2 = j + dj[d];

                    if(valid(i2, j2) && matrix[i2][j2] > matrix[i][j]) {
                        inDegree[i2][j2]++;
                    }
                }
            }
        }

        queue<pair<int,int>> cells;
        for(int i{}; i < m; ++i) {
            for(int j{}; j < n; ++j) {
                if(!inDegree[i][j]) {
                    cells.emplace(i, j);
                }
            }
        }

        int longestPath{};
        for(int level{}, size = cells.size(); !cells.empty(); ++level, size = cells.size())
            while(size--) {
                auto current = cells.front();
                int i = current.first;
                int j = current.second;
                cells.pop();
                
                longestPath = level;

                for(int d{}; d < 4; ++d) {
                    int i2 = i + di[d];
                    int j2 = j + dj[d];

                    if(valid(i2, j2) && matrix[i2][j2] > matrix[i][j] && !--inDegree[i2][j2]) {
                        cells.emplace(i2, j2);
                    }
                }
            }
        return longestPath + 1;
    }
};
