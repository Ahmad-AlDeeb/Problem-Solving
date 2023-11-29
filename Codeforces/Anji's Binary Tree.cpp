#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll int
#define ld long double
#define F first
#define S second
#define vll vector<long long>
#define pb push_back
#define all(v) v.begin(), v.end()
///////////////////////////////////////
const ll N = 1e7+7;
const ll M = 998244353;
const ll MAX = 1e18;
const ld EPS = 1e-19;
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
///█████████████████████████████████████████████████████ Solution ██████████████████████████████████████████████████████
vector<pair<pair<ll,ll>, ll>> adj;
ll n; string s;
ll ans;
void dfs(ll node, ll cost) {
    adj[node].S = cost;

    ll l = adj[node].F.F;
    if(l) {
        if(s[node-1] != 'L')
            dfs(l, adj[node].S +1);
        else
            dfs(l, adj[node].S);
    }

    ll r = adj[node].F.S;
    if(r) {
        if(s[node-1] != 'R')
            dfs(r, adj[node].S +1);
        else
            dfs(r, adj[node].S);
    }

    if(!l && !r) ans = min(ans,cost);
}

void fast() {
    cin >> n >> s;
    adj = vector<pair<pair<ll,ll>, ll>>(n+1);
    ans = n;

    for(ll i{1}; i<=n; i++) {
        ll l,r; cin >> l >> r;
        pair<ll,ll> children = make_pair(l,r);
        adj[i] = make_pair(children,0);
    }

    dfs(1,0);
    cout << ans;
}
///█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
//        cout << "Case " << i << ": ";
        fast();
        cout << endl;
    }

}


