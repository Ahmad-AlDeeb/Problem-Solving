class Solution {
    const vector<int> di{1, -1, 0, 0};
    const vector<int> dj{0, 0, 1, -1};
    int m, n;

    bool valid(int i, int j) {
        return (i >= 0 && i < m) and (j >= 0 && j < n);
    }

    vector<vector<int>> BFS(vector<vector<int>>& heights, vector<pair<int,int>>& starts) {
        vector<vector<int>> visited(m, vector<int>(n));

        queue<pair<int,int>> cells;
        for(auto cell : starts) {
            int i = cell.first;
            int j = cell.second;

            cells.emplace(i, j);
            visited[i][j]++;
        }

        for(int size = cells.size(); !cells.empty(); size = cells.size()) 
            while(size--) {
                auto current = cells.front();
                int i = current.first;
                int j = current.second;
                cells.pop();

                for(int dir{}; dir < 4; ++dir) {
                    int i2 = i + di[dir];
                    int j2 = j + dj[dir];

                    if(valid(i2, j2) && !visited[i2][j2] && heights[i2][j2] >= heights[i][j]) {
                        visited[i2][j2]++;
                        cells.emplace(i2, j2);
                    }
                }
            }
        
        return visited;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights.front().size();
        
        vector<pair<int,int>> upAndLeft;
        for(int j{}; j < n; ++j) {
            upAndLeft.emplace_back(0, j);
        }
        for(int i{1}; i < m; ++i) {
            upAndLeft.emplace_back(i, 0);
        }
        vector<vector<int>> visited1 = BFS(heights, upAndLeft);


        vector<pair<int,int>> downAndRight;
        for(int j{}; j < n; ++j) {
            downAndRight.emplace_back(m-1, j);
        }
        for(int i{}; i < m-1; ++i) {
            downAndRight.emplace_back(i, n-1);
        }
        vector<vector<int>> visited2 = BFS(heights, downAndRight);

        vector<vector<int>> answer;
        for(int i{}; i < m; ++i)
            for(int j{}; j < n; ++j)
                if(visited1[i][j] && visited2[i][j]) 
                    answer.push_back(vector<int> {i, j});    
        return answer;
    }
};
