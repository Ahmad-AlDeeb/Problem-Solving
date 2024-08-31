class Solution {
    const vector<int> di {1, -1, 0, 0};
    const vector<int> dj {0, 0, 1, -1};
    int m, n;

    bool valid(int i, int j, vector<vector<int>>& rooms) {
        return (i >= 0 && i < m) and (j >= 0 && j < n) and (rooms[i][j] != -1);
    }
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        m = rooms.size();
        n = rooms.front().size();

        queue<pair<int,int>> cells;
        vector<vector<bool>> visited(m, vector<bool>(n));

        for(int i{}; i < m; ++i) {
            for(int j{}; j < n; ++j) {
                if(rooms[i][j] == 0) {
                    visited[i][j] = true;                    
                    cells.emplace(i, j);
                }
            }
        }

        for(int level{}, size = cells.size(); !cells.empty(); 
            ++level, size = cells.size()) {
                while(size--) {
                    auto current = cells.front();
                    int i = current.first;
                    int j = current.second;
                    cells.pop();
                    
                    rooms[i][j] = level;

                    for(int d{}; d < 4; ++d) {
                        int i2 = i + di[d];
                        int j2 = j + dj[d];

                        if(valid(i2, j2, rooms) && !visited[i2][j2]) {
                            cells.emplace(i2, j2);
                        }
                    }
                }
        }
    }
};
