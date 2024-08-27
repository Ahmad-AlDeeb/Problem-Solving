class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adjacent(n);
        vector<int> inDegree(n);

        for(auto edge : edges) {
            adjacent[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        queue<int> nodes;
        unordered_map<int, unordered_map<char,int>> nodeColors;
        
        for(int node{}; node < n; ++node) {
            if(!inDegree[node]) {
                nodes.push(node);
                nodeColors[node][colors[node]]++;
            }
        }

        vector<int> popped;
        int answer{};
        while(!nodes.empty()) {
            int size = nodes.size();
            while(size--) {
                int current = nodes.front();
                nodes.pop();
                popped.push_back(current);

                answer = max(answer, nodeColors[current][colors[current]]);

                for(auto child : adjacent[current]) {
                    for(auto color : nodeColors[current])
                        nodeColors[child][color.first] = max(nodeColors[child][color.first], color.second);

                    if(!--inDegree[child]) {
                        nodes.push(child);

                        nodeColors[child][colors[child]]++;
                    }
                }
            }
        }
        if(popped.size() != n) {
            return -1;
        }

        return answer;
    }
};
