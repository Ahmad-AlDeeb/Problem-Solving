int n,e;
vector< vector<int> > adj;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    
    for(ll i{}; i<adj[node].size; i++) {
        int child = adj[node][i];
        if(!visited[child]) dfs(child);
    }
}


int main() { IOS
    cin >> n >> e;
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n);
    
    for(int i{}; i<n; i++) {
        int from,to;
        cin >> from >> to;
        adj[from-1].push_back(to-1)
    }
}
