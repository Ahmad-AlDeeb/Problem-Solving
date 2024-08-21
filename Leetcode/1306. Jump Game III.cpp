class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0) {
            return true;
        }
        
        int n = arr.size();
        vector<vector<int>> adj(n);
        
        for(int i{}; i < n; ++i) {    
            int prev = i - arr[i];
            if(prev >= 0) {
                adj[i].push_back(prev);
            }
            
            int next = i + arr[i];
            if(next < n) {
                adj[i].push_back(next);
            }
        }
        

        vector<bool> vis(n);
        queue<int> q;
        q.push(start);
        for(int level{}, size{1}; !q.empty(); ++level, size = q.size()) {
            while(size--) {
                int cur = q.front();
                q.pop();
                vis[cur] = true;

                if(arr[cur] == 0) {
                    return true;
                }

                for(auto child : adj[cur]) {
                    if(!vis[child]) {
                        q.push(child);
                    }
                }
            }
        }
        return false;
    }
};
