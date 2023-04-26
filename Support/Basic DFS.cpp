vector<vector<ll>>adj;
vector<bool>vis;
vector<ll> topsort;
ll n;

void dfs(ll node) {
    vis[node]=true;

    for(auto child:adj[node])
        if(!vis[child]) dfs(child);

    topsort.pb(node); // DAG // Other Way Indegree / Outdegree
}

ll connected_components_cnt() {
    ll cnt{};
    for(ll i{}; i<n; i++)
        dfs(i),cnt++;
    return cnt;
}
