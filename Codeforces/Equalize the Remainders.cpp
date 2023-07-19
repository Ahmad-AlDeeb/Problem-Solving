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
const ll SZ {101};
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
vll div(ll x) {
    vll div;
    for(ll i{1}; i*i<=x; i++)
        if(x%i == 0) {
            div.pb(i);
            if(i*i != x) div.pb(x/i);
        }
    return div;
}
void fast() {
    ll n,m; cin >> n >> m;
    vll v(n);
    map<ll,vll> r;
    for(ll i{}; i<n; i++) {
        cin >> v[i];
        r[v[i]%m].pb(i);
    }


    ll k {n/m}, ans{};
    vector<pair<ll,ll>> extra;
    for(ll i{}; i<2*m; i++) {
        ll cur = i%m;

        while(r[cur].size() > k) {
            extra.emplace_back(r[cur].back(), i);
            r[cur].pop_back();
        }
        while(r[cur].size() < k && !extra.empty()) {
            ll ind = extra.back().F;
            ll MOD = extra.back().S;
            extra.pop_back();
            r[cur].pb(ind);

            v[ind] += i-MOD;
            ans += i-MOD;
        }
    }
    cout << ans << endl;
    for(auto &num:v) cout << num << " ";
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
