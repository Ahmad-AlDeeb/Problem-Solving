class Solution {
    vector<vector<int>> graph;
    vector<vector<int>> paths;
    vector<int> path {0};
    int n;

    void traverse(int node) {
        if(node == n - 1) {
            paths.push_back(path);
            return;
        }

        for(auto child : graph[node]) {
            path.push_back(child);
            traverse(child);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph_) {
        graph = graph_;
        n = graph.size();
        
        traverse(0);
        return paths;
    }
};
