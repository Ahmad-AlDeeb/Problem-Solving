#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
///////////////////////////////////////
const ll N = 1e7 + 7;
const ll M = 998244353;
const ll MAX = 1e18;
const ld EPS = 1e-19;
ll pow(ll x, ll y) {
    ll ans{1};
    while (y) {
        if (y & 1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}

ll big_pow(ll x, ll y) {
    ll ans{1};
    while (y) {
        if (y & 1) ans = ((ans % M) * (x % M)) % M;
        x = ((x % M) * (x % M)) % M;
        y /= 2;
    }
    return ans;
}

bool is_int(ld num) {
    return num == (ll) num;
}

int cmp_d(ld a, ld b) {
    if (fabs(a - b) <= EPS) return -1;
    return a > b ? 1 : 0;
}

ll mod(ll x, ll m) {
    return (x % m + m) % m;
}
///█████████████████████████████████████████████████████ Solution ██████████████████████████████████████████████████████
void fast() {
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i{}; i < n-1; ++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxNode = 1;

    vector<bool> visited(n + 1);
    visited[maxNode] = true;

    queue<int> nodes;
    nodes.push(maxNode);

    int maxLevel{};
    for(int level{}, size = nodes.size(); !nodes.empty(); ++level, size = nodes.size())
        while(size--) {
            int current = nodes.front();
            nodes.pop();

            if(level > maxLevel) {
                maxLevel = level;
                maxNode = current;
            }

            for(auto child : adj[current]) {
                if(!visited[child]) {
                    visited[child] = true;
                    nodes.push(child);
                }
            }
        }

    visited = vector<bool>(n + 1);
    visited[maxNode] = true;
    nodes.push(maxNode);

    int longestPath{};
    for(int level{}, size = nodes.size(); !nodes.empty(); ++level, size = nodes.size())
        while(size--) {
            int current = nodes.front();
            nodes.pop();

            longestPath = level;

            for(auto child : adj[current]) {
                if(!visited[child]) {
                    visited[child] = true;
                    nodes.push(child);
                }
            }
        }
    cout << longestPath;
}
///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
int main() {
    IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    // cin >> tc;
    for (ll i{1}; i <= tc; i++) {
        // cout << "Case " << i << ": ";
        fast();
        if (i != tc) cout << endl;
    }
}
