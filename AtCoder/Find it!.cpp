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
///////////////////////////////////
const vll di {0,0,1,-1};
const vll dj {1,-1,0,0};
const string letters{"abcdefghijklmnopqrstuvwxyz"};
const ll MAX = 1e18;
const ll M = 1e9+7;
const ld EPS = 1e-19;
const ll SZ {10004};
const ld PI = 3.14159265358979323846;
ll pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans *= x;
        x *= x;
        y /= 2;
    }
    return ans;
}
ll big_pow(ll x, ll y) {
    ll ans{1};
    while(y) {
        if(y&1) ans = ((ans%M)*(x%M)) % M;
        x = ((x%M) * (x%M)) %M;
        y/=2;
    }
    return ans;
}
bool is_int(ld num) {
    return num == (ll)num;
}
int cmp_d(ld a, ld b) {
    if(fabs(a-b) <= EPS) return -1;
    return a>b? 1:0;
}
ll mod(ll x, ll m){
    return (x%m +m) % m;
}
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
vector<vll> adj;
vector<bool> vis;
bool cool{false};
vll cycle, ans;
set<ll> exist;

void dfs(ll node) {
    if(!vis[node]) vis[node]=true;
    cycle.pb(node);
    exist.insert(node);

    for(auto child:adj[node]) {
        if(exist.count(child)) {
            while(cycle.back() != child)
                ans.pb(cycle.back()), cycle.pop_back();
            ans.pb(child);

            cool=true;
        }
        else if(!vis[child])dfs(child);
    }
}
void fast() {
    ll n; cin >> n;
    adj = vector<vll>(n+1);
    vis = vector<bool>(n+1,false);
    ans.clear();
    cool=false;
    for(ll i{1}; i<=n; i++) {
        ll x; cin >> x; adj[i].pb(x);
    }


    for(ll i{1}; i<=n; i++) {
        cycle.clear(), exist.clear();
        if(!vis[i]) dfs(i);
        if(cool) break;
    }

    reverse(all(ans));
    cout << ans.size() << endl;
    for(auto node:ans) cout << node << " ";
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    while(tc--) {
        fast();
//        cout << endl;
    }
}
