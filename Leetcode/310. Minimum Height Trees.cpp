class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }
        
        vector<vector<int>> adjacent(n);
        vector<int> inDegree(n);
        for(auto edge : edges) {
            adjacent[edge[0]].push_back(edge[1]);
            adjacent[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }

        queue<int> nodes;
        for(int node{}; node < n; ++node) {
            if(inDegree[node] == 1)
                nodes.push(node);
        }

        vector<vector<int>> levels;
        for(int level{}, size = nodes.size(); !nodes.empty(); ++level, size = nodes.size()) {
            vector<int> currentLevel;
            while(size--) {
                int current = nodes.front();
                nodes.pop();

                currentLevel.push_back(current);

                for(auto child : adjacent[current]) {
                    if(--inDegree[child] == 1) {
                        nodes.push(child);
                    }
                }
            }
            levels.push_back(currentLevel);
        }

        return levels.back();
    }
};
