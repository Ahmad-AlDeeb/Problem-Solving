class Solution {
    const vector<int> di {1, -1, 0, 0};
    const vector<int> dj {0, 0, 1, -1};
    int n;

    bool valid(int i, int j) {
        return (i >= 0 && i < n) and (j >= 0 && j < n);
    }
    
    pair<int,int> getStart(vector<vector<int>>& grid) {
        for(int i{}; i < n; ++i) {
            for(int j{}; j < n; ++j) {
                if(grid[i][j] == 1) {
                    return {i,j};
                }
            }
        }
        return {0,0};
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n));
        
        // Get first island        
        auto start = getStart(grid);
        visited[start.first][start.second] = true;

        queue<pair<int,int>> cells;
        cells.push(start);

        queue<pair<int,int>> land1;
        for(int size = cells.size(); !cells.empty(); size = cells.size())
            while(size--) {
                auto current = cells.front();
                int i = current.first;
                int j = current.second;                
                cells.pop();

                land1.push(current);

                for(int d{}; d < 4; ++d) {
                    int i2 = i + di[d];
                    int j2 = j + dj[d];

                    if(valid(i2, j2) && grid[i2][j2] && !visited[i2][j2]) {
                        visited[i2][j2] = true;
                        cells.emplace(i2,j2);
                    }
                }
            }
        
        // Get answer
        cells = land1;
        int answer{INT_MAX};
        for(int level{}, size = cells.size(); !cells.empty(); ++level, size = cells.size())
            while(size--) {
                auto current = cells.front();
                cells.pop();

                for(int d{}; d < 4; ++d) {
                    int i = current.first + di[d];
                    int j = current.second + dj[d];

                    if(valid(i, j) && !visited[i][j]) {
                        visited[i][j] = true;

                        if(grid[i][j]) {
                            answer = min(answer, level);
                        }
                        else {
                            cells.emplace(i, j);
                        }
                    }
                }
            }
        return answer;
    }
};


