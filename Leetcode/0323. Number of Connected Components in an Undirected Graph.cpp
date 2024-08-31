class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_set<int> vis;
    void dfs(int node) {
        if(vis.count(node)) {
            return;
        }
        vis.insert(node);

        for(auto child : adj[node]) {
            dfs(child);
        }
        return;
    }
    /**
     * @param n: the number of vertices
     * @param edges: the edges of undirected graph
     * @return: the number of connected components
     */
    int countComponents(int n, vector<vector<int>> &edges) {
        unordered_set<int> nodes;

        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
            nodes.insert(edge[0]);
            nodes.insert(edge[1]);
        }

        int answer{};
        for(auto node : adj) {
            if(!vis.count(node.first)) {
                answer++;
                dfs(node.first);
            }
        }
        
        return answer + (n - nodes.size());
    }
};
