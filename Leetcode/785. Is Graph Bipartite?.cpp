class Solution {
    int colors[100];
    bool is_bipartite{true};

    void dfs(int node, vector<vector<int>>& graph, int color = 1) {
        if(colors[node]) {
            if(color != colors[node]) {
                is_bipartite = false;
            }
            return;
        }
        colors[node] = color;

        for(auto child : graph[node]) {
            dfs(child, graph, 3 - color);
        }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        for(int i{}; i < graph.size(); ++i) {
            if(!colors[i]) {
                dfs(i, graph);
            }
        }
        
        return is_bipartite;
    }
};
