class Solution {
    vector<int> BFS(vector<vector<pair<int, string>>> &adjacent) {
        vector<int> path(adjacent.size(), -1);
        
        set<pair<int,string>> visited;
        visited.emplace(0, "RED");
        visited.emplace(0, "BLUE");

        queue<pair<int, string>> nodes;
        nodes.emplace(0, "RED");
        nodes.emplace(0, "BLUE");
        
        for(int level{}, size = nodes.size(); !nodes.empty(); ++level, size = nodes.size())
            while(size--) {
                auto current = nodes.front();
                int node = current.first;
                string color = current.second;
                nodes.pop();

                path[node] = (path[node] == -1)? level : min(path[node], level);

                for(auto child : adjacent[node]) {
                    if(child.second != color && visited.insert(child).second) {
                        nodes.push(child);         
                    }
                }
            }

        return path;
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,string>>> adjacent(n);

        for(auto edge : redEdges) {
            adjacent[edge[0]].emplace_back(edge[1], "RED");
        }
        for(auto edge : blueEdges) {
            adjacent[edge[0]].emplace_back(edge[1], "BLUE");
        }

        vector<int> answer = BFS(adjacent);
        return answer;
    }
};
