class Solution {
    unordered_map<int,vector<pair<int,bool>>> adj;
    bool vis[50000];

    void dfs(int node, int &cost) {
        if(vis[node]) {
            return;
        }
        vis[node] = true;

        for(auto child : adj[node]) {
            if(!vis[child.first]) {
                cost += child.second;
            }
            
            dfs(child.first, cost);
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto con : connections) {
            adj[con[0]].emplace_back(con[1], true);
            adj[con[1]].emplace_back(con[0], false);
        }

        int cost;
        dfs(0, cost);
        return cost;
    }
};
