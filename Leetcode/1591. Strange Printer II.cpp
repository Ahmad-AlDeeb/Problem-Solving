struct Cell {
    int i, j;
};

class Solution {
    const vector<int> di {1, -1, 0, 0};
    const vector<int> dj {0, 0, 1, -1};
    int m, n;
    unordered_map<int, pair<Cell,Cell>> corners;
    unordered_set<int> allColors;
    
    unordered_map<int, pair<Cell, Cell>> getCorners(vector<vector<int>>& grid) {
        unordered_map<int, pair<Cell,Cell>> corners;
        for(int i{}; i < m; ++i) {
            for(int j{}; j < n; ++j) {
                int color = grid[i][j];
                allColors.insert(color);                

                // Handling min since default pair values are 0.
                if(corners.find(color) == corners.end()) {
                    corners[color].first.i = i;
                    corners[color].first.j = j;
                }
                else {
                    corners[color].first.i = min(corners[color].first.i, i);
                    corners[color].first.j = min(corners[color].first.j, j);
                }

                corners[color].second.i = max(corners[color].second.i, i);
                corners[color].second.j = max(corners[color].second.j, j);
            }
        }
        return corners;
    }

public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        m = targetGrid.size();
        n = targetGrid.front().size();
        corners = getCorners(targetGrid);
        
        unordered_map<int, unordered_set<int>> adjacent;
        unordered_map<int, int> inDegree;
        
        for(auto p1 : corners) {
            int color = p1.first;
            auto corner1 = p1.second.first;
            auto corner2 = p1.second.second;

            int maxI = corner2.i;
            int maxJ = corner2.j;
            for(int i = corner1.i; i <= maxI; i++)
                for(int j = corner1.j; j <= maxJ; j++) {
                    if(targetGrid[i][j] != color) {
                        
                        if(adjacent[color].insert(targetGrid[i][j]).second) {
                            inDegree[targetGrid[i][j]]++;
                        }
                    }
                }
        }

        queue<int> colors;
        for(auto color : allColors) {
            if(!inDegree[color]) {
                colors.push(color);
            }
        }
        
        vector<int> poppedColors;
        while(!colors.empty()) {
            int size = colors.size();
            while(size--) {
                int current = colors.front();
                colors.pop();

                poppedColors.push_back(current);
                
                for(auto child : adjacent[current]) {
                    if(!--inDegree[child]) {
                        colors.push(child);
                    }
                }
            }
        }
        return poppedColors.size() == allColors.size();
    }
};
