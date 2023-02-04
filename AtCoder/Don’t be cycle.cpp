#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<unordered_set>
#include<map>
#include<bitset>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define F first
#define S second
#define dd double
#define ll long long
#define ld long double
#define pb push_back
#define all(v) v.begin(), v.end()
const ll inf = 1e17;
const ll M = 1e5;

ll n,m,comp{},ans{};
vector<vector<ll>>adj;
vector<bool>vis;
void dfs(ll node) {
    vis[node]=true;

    for(auto child:adj[node])
        if(!vis[child]) dfs(child);
}

int main() { IOS
//    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    cin >> n >> m;
    adj = vector<vector<ll>>(n+1);
    vis = vector<bool>(n+1);

    for(ll i{}; i<m; i++) {
        ll a,b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(ll i{1}; i<=n; i++)
        if(!vis[i]) {
            comp++;
            dfs(i);
        }
    cout << m-n+comp;
}
