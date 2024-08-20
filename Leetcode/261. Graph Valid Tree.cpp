class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        if(edges.size() != n-1) {
            return false;
        }
        
        vector<vector<int>> adj(n);
        for(auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> parent(n, -1);
        queue<int> q;
        parent[0] = -2;
        q.push(0);

        for(int level{}, size{1}; !q.empty(); ++level, size = q.size()) {
            while(size--) {
                int cur = q.front();
                q.pop();

                for(auto child : adj[cur]) {
                    if(parent[child] == parent[cur]) {
                        return false;
                    }
                    if(parent[child] == -1) {
                        parent[child] = cur;
                        q.push(child);
                    }
                }
            }
        }

        for(auto p : parent) {
            if(p == -1) {
                return false;
            }
        }

        return true;
    }
};
