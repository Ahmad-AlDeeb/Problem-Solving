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
//////// Bipartite graph 
vector<vector<ll>>graph;
vector<ll>visited;
enum status {path=0, cycle=1};
 
status dfs(ll current, ll parent, ll &count) {
    if(visited[current])
        return cycle;
    visited[current] = 1;
 
    for(ll child:graph[current])
        if(child!=parent) {
            count++;
 
            status s = dfs(child, current, count);
            if(s == cycle)
                return cycle;
 
        }
    return path;
}
