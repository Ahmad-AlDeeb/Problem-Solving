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
const ll N = 1e5+5;
const ll M = 1e9+7;
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
///////////////////////////////////////////////// ===== Solution ===== /////////////////////////////////////////////////
void fast() {
    ll n; cin >> n;
    map<ll,ll> f;
    vll v(n); for(auto &i:v) cin >> i, f[i]++;

    ll tar{v[0]},mx{};
    for(auto p:f) if(p.S > mx) mx=p.S, tar=p.F;

    vll vis(n);
    for(ll i{}; i<n; i++) vis[i] = (v[i]==tar);

    vector<pair<ll, pair<ll,ll>>> op;
    for(ll i{}; i<n; i++)
        if(vis[i]) {
            for(ll j{i}; j>0; j--) {
                if(vis[j-1]) continue;

                ll type{1};
                if(v[j-1]>tar) type=2;
                pair<ll,ll> p = {j-1,j};

                op.emplace_back(type,p);
            }
            for(ll j{i}; j<n-1; j++) {
                if(vis[j+1]) continue;

                ll type{1};
                if(v[j+1]>tar) type=2;
                pair<ll,ll> p = {j+1,j};

                op.emplace_back(type,p);
            }
            break;
        }
    cout << op.size() << endl;
    for(auto o:op) cout << o.F << " " << o.S.F+1 << " " << o.S.S+1 << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() { IOS
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ll tc{1};
//    cin >> tc;
    for(ll i{1}; i<=tc; i++) {
//        cout << "Case " << i << ": ";
        fast();
//        cout << endl;
    }
}
