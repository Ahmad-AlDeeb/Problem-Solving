vector<vector<ll>>adj;
vector<bool>vis;
void dfs(ll node) {
    vis[node]=true;

    for(auto child:adj[node])
        if(!vis[child]) dfs(child);
}
