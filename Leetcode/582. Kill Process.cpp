class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    
    void dfs(int node, int kill, vector<int>& ans, bool found = false) {
        if(vis[node]) {
            return;
        }
        vis[node] = true;

        if(node == kill) {
            found = true;
        }

        if(found) {
            ans.push_back(node);
        }

        for(auto child : adj[node]) {
            dfs(child, kill, ans, found);
        }
    }
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        int n = pid.size();
        int mx{};
        for(int i{}; i<n; i++) {
            mx = max(mx, ppid[i]);
            mx = max(mx, pid[i]);
        }
        
        
        adj = vector<vector<int>> (mx + 1);
        vis = vector<bool> (mx + 1);


        for(int i{}; i<n; i++) {
            adj[ppid[i]].push_back(pid[i]);
        }

        vector<int> ans;
        for(int i{}; i<=mx; i++) {
            dfs(i, kill, ans);
        }
        return ans;
    }
};
